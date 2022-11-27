#include <bits/stdc++.h>
using namespace std;
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const ll inf = 1000000007;
const ll maxx = 1000000;

struct pt{
    int x,y;
};

pt p(int x, int y){
    pt res;
    res.x = x;
    res.y = y;
    return res;
}

ll dist(pt p1, pt p2){
    return abs(p1.x-p2.x) + abs(p1.y-p2.y);
}

int T,n;
vector<pt> houses;
vi indx, invx;

bool compx(int i, int j){
    return houses[i].x < houses[j].x;
}

bool compy(int i, int j){
    return houses[i].y < houses[j].y;
}

bool compmax(int i, int j){
    return max(houses[i].x, houses[i].y) < max(houses[j].x, houses[j].y);
}

ll score(vi &P){
    ll res = 0;
    rep(c1,1,sz(P)){
        res += dist(houses[P[c1]], houses[P[c1-1]]);
    }
    return res;
}

int find_closest(int i, vi &seen){
    int j = invx[i];
    int res = -1;
    int d = inf;
    for(int j2 = j-1; j2 >= 0; j2--){
        int i2 = indx[j2];
        if(seen[i2])continue;
        if(abs(houses[i].x - houses[i2].x) >= d)break;
        int d2 = dist(houses[i], houses[i2]);
        if(d2 < d){
            d = d2;
            res = i2;
        }
    }
    for(int j2 = j+1; j2 < n; j2++){
        int i2 = indx[j2];
        if(seen[i2])continue;
        if(abs(houses[i].x - houses[i2].x) >= d)break;
        int d2 = dist(houses[i], houses[i2]);
        if(d2 < d){
            d = d2;
            res = i2;
        }
    }
    return res;
}

vi get_k_closest(int i, vi &seen, int k){
    vi res;
    rep(c1,0,k){
        int j = find_closest(i, seen);
        if(j == -1)break;
        res.push_back(j);
        seen[j] = 1;
    }
    trav(y, res){
        seen[y] = 0;
    }
    return res;
}

ll around(int i, vi &P){
    ll res = 0;
    if(i > 0)res += dist(houses[P[i]], houses[P[i-1]]);
    if(i < n/2-1)res += dist(houses[P[i]], houses[P[i+1]]);
    return res;
}

void try_to_swap(vi &P, int d){
    int i = rand()%(n/2);
    int j = i + rand()%d + 1;
    if(d > n)j = rand()%(n/2);
    j = min(j, n/2-1);

    ll old_score = around(i, P) + around(j, P);
    swap(P[i], P[j]);
    ll new_score = around(i, P) + around(j, P);
    if(new_score >= old_score)swap(P[i], P[j]);
}

void hillclimb(vi &P, bool small){
    int lim = 2000000;
    if(small){
        rep(c1,0,lim){
            try_to_swap(P, n+1);
        }
    }
    else{
        rep(c1,0,lim){
            int d = 100 - (99 * c1) / lim;
            try_to_swap(P, d);
        }
    }
    rep(c1,0,2*lim){
        try_to_swap(P, 5);
    }
    rep(c1,0,2*lim){
        try_to_swap(P, 2);
    }
}


vi solve1(int runs=1){
    vi ans;
    ll best = inf*inf;
    rep(run,0,runs){
        vi ind;
        rep(c1,0,n){
            ind.push_back(c1);
        }
        sort(all(ind), compx);
        ll mindist = inf;
        int start = 0;
        rep(c1,0,n/2+1){
            int i = ind[c1];
            int j = ind[c1+n/2-1];
            ll d = houses[j].x - houses[i].x;
            if(d < mindist ||(d == mindist && rand()%2 == 0)){
                mindist = d;
                start = c1;
            }
        }

        vi res;
        rep(c1,0,n/2){
            res.push_back(ind[start+c1]);
        }

        if(T == 2){
            rep(c1,0,1000000){
                try_to_swap(res, 8);
            }
            rep(c1,0,4000000){
                try_to_swap(res, 3);
            }
        }
        ll new_dist = score(res);
        if(new_dist < best){
            best = new_dist;
            ans = res;
        }
    }

    return ans;
}

vi solve_random(int runs, int hc){
    // Takes a random solution, and hillclimbs with 'try_to_swap'
    vi res;
    ll best_score = inf*inf;
    vi ind;
    rep(c1,0,n){
        ind.push_back(c1);
    }
    rep(_,0,runs){
        vi temp;
        random_shuffle(all(ind));
        rep(c1,0,n/2){
            temp.push_back(ind[c1]);
        }
        rep(c1,0,hc){
            try_to_swap(temp, n+1);
        }
        ll sc = score(temp);
        if(sc < best_score){
            best_score = sc;
            res = temp;
        }
    }
    return res;
}

vi greedy(vi taken){
    vi seen(n, 0);
    trav(y, taken){
        seen[y] = 1;
    }
    while(sz(taken) < n/2){
        int now = taken.back();
        int nex = find_closest(now, seen);
        seen[nex] = 1;
        taken.push_back(nex);
    }
    return taken;
}

vi tree_search(vi &taken, int branch, int depth){
    if(depth == 0)return greedy(taken);
    vi seen(n, 0);
    trav(y, taken){
        seen[y] = 1;
    }
    int i = taken.back();
    vi res = get_k_closest(i, seen, branch);
    ll best_score = inf*inf;
    vi ans;
    trav(j, res){
        taken.push_back(j);
        vi temp = tree_search(taken, branch, depth-1);
        ll new_score = score(temp);
        if(new_score < best_score){
            best_score = new_score;
            ans = temp;
        }
        taken.pop_back();
    }

    return ans;
}

vi solve_tree_search(int runs, int branch, int depth){
    vi ans;
    ll best_score = inf*inf;
    rep(c1,0,runs){
        int start = c1%n;
        vi taken = {start};
        vi temp = tree_search(taken, branch, depth);
        ll new_score = score(temp);
        if(new_score < best_score){
            best_score = new_score;
            ans = temp;
        }
    }
    hillclimb(ans, 1);
    return ans;
}

vi solve_greedy(int runs, int hc){
    vi res;
    ll best_score = inf*inf;
    vi seen(n, 1);
    rep(run,0,runs){
        int start = rand()%n;
        vi temp = greedy({start});
        ll new_score = score(temp);
        if(new_score < best_score){
            best_score = new_score;
            res = temp;
        }
    }
    hillclimb(res, 0);
    return res;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    cin >> T >> n;
    rep(c1,0,n){
        int x,y;
        cin >> x >> y;
        houses.push_back(p(x, y));
        indx.push_back(c1);
        invx.push_back(0);
    }
    sort(all(indx), compx);
    rep(c1,0,n){
        invx[indx[c1]] = c1;
    }

    vi ans;
    if(T == 1)ans = solve1();
    if(T == 2)ans = solve1(5);
    if(T == 3)ans = solve_random(10000, 1000);
    if(T == 4)ans = solve_tree_search(n, 2, 10);
    if(T == 5)ans = solve_tree_search(n, 3, 7);
    if(T == 6)ans = solve_greedy(2000, 1000000);
    if(T == 7)ans = solve_greedy(1000, 1000000);
    if(T == 8)ans = solve_greedy(80, 1000000);
    if(T == 9)ans = solve_greedy(40, 1000000);
    if(T == 10)ans = solve_greedy(25, 1000000);
    if(T == 0)ans = solve_random(1000, 1000);


    rep(c1,0,n/2){
        cout << ans[c1]+1 << " ";
    }cout << "\n";

    cerr << score(ans) << "\n";

    return 0;
}
