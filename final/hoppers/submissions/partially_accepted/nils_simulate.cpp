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
const ll MAXN = 1000001;
int n,N;

// > ^ < v
int DX[4] = {0, -1, 0, 1};
int DY[4] = {1, 0, -1, 0};

vi C;
int INDEX[MAXN] = {0};

int parse(char ch){
    if(ch == '>')return 0;
    if(ch == '^')return 1;
    if(ch == '<')return 2;
    if(ch == 'v')return 3;
    return -1; 
}

int ANS[MAXN] = {0};
int NODE[MAXN] = {0};


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int r,c;
    
    cin >> r >> c >> n;
    N = r*c;

    rep(c1,0,r){
        string s;
        cin >> s;
        rep(c2,0,c){
            int z = parse(s[c2]);
            int i = c1*c+c2;
            int x2 = c1+DX[z];
            int y2 = c2+DY[z];
            int j = x2*c+y2;
            C.push_back(j);
        }
    }

    rep(c1,0,n){
        int x,y;
        cin >> x >> y;
        int i = x*c+y;
        NODE[c1] = i;
        ANS[c1] = big;
    }

    rep(t,1,r*c+1){
        rep(c1,0,n){
            int j = INDEX[NODE[c1]]-1;
            int node = NODE[c1];
            if(node < 0)continue;
            if(ANS[c1] == big && j != -1 && j != c1 && (NODE[j] == node || NODE[j] == -(t*N + node))){
                ANS[c1] = node;
                ANS[j] = node;
                NODE[j] = -(t*N + node);
                NODE[c1] = -(t*N + node);
            }
            INDEX[node] = c1+1;
        }

        int live = 0;
        rep(c1,0,n){
            if(ANS[c1] == big){
                NODE[c1] = C[NODE[c1]];
                live++;
            }
        }
        if(live == 0)break;
    }

    rep(c1,0,n){
        if(ANS[c1] == big){
            cout << "cycle\n";
        }
        else{
            cout << ANS[c1]/c << " " << ANS[c1]%c << "\n";
        }
    }

    return 0;
}