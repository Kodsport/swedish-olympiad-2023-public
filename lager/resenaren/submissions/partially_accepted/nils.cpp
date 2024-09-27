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
const ll MAXN = 500001;

int n,q;
vector<vi> C(MAXN, vi());
vi A;

const int SQRT = 500;

int PAR[MAXN] = {0};
int SQRT_PAR[MAXN] = {0};
int SQRT_MIN[MAXN] = {0};
int DIST[MAXN] = {0};

void bfs(int start){
    PAR[start] = start;
    DIST[start] = 0;
    vi Q;
    Q.push_back(start);
    while(!Q.empty()){
        int a = Q.back();
        Q.pop_back();
        trav(b, C[a]){
            if(b != PAR[a]){
                PAR[b] = a;
                DIST[b] = DIST[a]+1;
                Q.push_back(b);
            }
        }
    }
}

int lca(int u, int v){
    // lca in sqrt(n) :)
    if(DIST[u] > DIST[v])swap(u, v);
    while(DIST[v]%SQRT != DIST[u]%SQRT){
        v = PAR[v];
    }
    while(DIST[v] > DIST[u]){
        v = SQRT_PAR[v];
    }
    while(SQRT_PAR[u] != SQRT_PAR[v]){
        u = SQRT_PAR[u];
        v = SQRT_PAR[v];
    }
    while(u != v){
        u = PAR[u];
        v = PAR[v];
    }
    return u;
}

int jump(int from, int to, int x){

    if(x >= SQRT_MIN[to]){
        vi walk;
        int now = PAR[to];
        while(now != from){
            walk.push_back(now);
            now = PAR[now];
        }
        reverse(all(walk));
        trav(y, walk){
            if(x >= A[y])x %= A[y];
        }
    }

    if(x >= A[to])x %= A[to];
    return x;
}

int query(int u, int v, int x){
    int w = lca(u, v);
    x %= A[u];
    while(u != w){
        if(DIST[u] - DIST[w] < SQRT || SQRT_MIN[u] <= x){
            u = PAR[u];
            if(x >= A[u])x %= A[u];
        }
        else{
            u = SQRT_PAR[u];
        }
    }

    vi skips;
    while(DIST[v]%SQRT != DIST[w]%SQRT){
        skips.push_back(v);
        v = PAR[v];
    }
    while(v != w){
        skips.push_back(v);
        v = SQRT_PAR[v];
    }
    reverse(all(skips));
    int prev = w;
    trav(nxt, skips){
        x = jump(prev, nxt, x);
        prev = nxt;
    }

    return x;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> q;
    rep(c1,0,n-1){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        C[a].push_back(b);
        C[b].push_back(a);
    }
    bfs(0);
    rep(c1,0,n){
        int a;
        cin >> a;
        A.push_back(a);
    }

    rep(c1,0,n){
        int mi = big;
        int i = c1;
        rep(c2,0,SQRT){
            i = PAR[i];
            mi = min(mi, A[i]);
        }
        SQRT_PAR[c1] = i;
        SQRT_MIN[c1] = mi;
    }

    rep(c1,0,q){
        int a,b,x;
        cin >> a >> b >> x;
        a--;
        b--;
        int ans = query(a, b, x);
        cout << ans << "\n";
    }

    return 0;
}