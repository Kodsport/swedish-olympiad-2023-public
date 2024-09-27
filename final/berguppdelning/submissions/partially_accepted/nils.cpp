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
typedef long double ld;
typedef unsigned long long ull;

const ll big = 1000000007;
const ll MAXN = 100001;

ll n,m,k,T;
int DX[4] = {0, -1, 0, 1};
int DY[4] = {1, 0, -1, 0};

vector<vi> grid(MAXN, vi());
vector<vi> team(MAXN, vi());

vector<pii> coords;
ll sum = 0;

bool inbounds(int i, int j){
    return i >= 0 && j >= 0 && i < n && j < m;
}

bool comp(pii p1, pii p2){
    return abs(n*m*grid[p1.first][p1.second] - sum) < abs(n*m*grid[p2.first][p2.second] - sum);
}

void bfs(pii start){
    int tm = team[start.first][start.second];
    queue<pii> Q;
    Q.push(start);
    while(!Q.empty()){
        pii now = Q.front();
        Q.pop();
        rep(c1,0,4){
            int x2 = now.first + DX[c1];
            int y2 = now.second + DY[c1];
            if(inbounds(x2,y2) && team[x2][y2] == -1){
                team[x2][y2] = tm;
                Q.push({x2,y2});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    cin >> T;
    cin >> n >> m >> k;
    rep(c1,0,n){
        rep(c2,0,m){
            int a;
            cin >> a;
            grid[c1].push_back(a);
            team[c1].push_back(-1);
            coords.push_back({c1, c2});
            sum += a;
        }
    }
    sort(all(coords), comp);
    rep(c1,0,k){
        pii pt = coords[c1];
        team[pt.first][pt.second] = c1;
    }

    for(int c1 = k-1; c1 >= 0; c1--){
        bfs(coords[c1]);
    }

    rep(c1,0,n){
        rep(c2,0,m){
            cout << team[c1][c2] << " ";
        }
        cout << "\n";
    }

    return 0;
}