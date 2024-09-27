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
const ll MAXN = 401;
const ll MAXA = 401;
int n,q;

vi A,D;

vi AT,DT;

int result(int a, int d, int a2, int d2){
    int g1 = max(0, a-d2);
    int g2 = max(0, a2-d);
    if(g1 > g2)return 0;
    if(g1 < g2)return 2;
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;

    int a_best = 0;
    int d_best = 0;

    int dsum = 0;
    int asum = 0;

    rep(c1,0,n){
        int a,d;
        cin >> a >> d;
        A.push_back(a);
        D.push_back(d);
        if(a >= d){
            a_best += a;
        }
        else{
            d_best += d;
        }
        asum += a;
        dsum += d;
    }

    AT.push_back(a_best);
    DT.push_back(d_best);

    AT.push_back(asum);
    DT.push_back(0);

    AT.push_back(0);
    DT.push_back(dsum);

    rep(c1,0,n){
        if(A[c1] >= D[c1]){
            AT.push_back(a_best-A[c1]);
            DT.push_back(d_best+D[c1]);
        }
        else{
            AT.push_back(a_best+A[c1]);
            DT.push_back(d_best-D[c1]);
        }
    }

    cin >> q;
    vi ANS(3, 0);
    rep(c1,0,q){
        int a,d;
        cin >> a >> d;
        int res = 2;
        rep(c2,0,sz(AT)){
            res = min(res, result(AT[c2], DT[c2], a, d));
        }
        ANS[res]++;
    }
    cout << ANS[0] << " " << ANS[1] << " " << ANS[2] << "\n";


    return 0;
}