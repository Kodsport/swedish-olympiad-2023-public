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
int sumd = 0;
int DP[MAXN * MAXA] = {-big};
vector<string> result = {"lose", "draw", "win"};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    rep(c1,0,MAXN*MAXA){
        DP[c1] = -big;
    }
    DP[0] = 0;
    rep(c1,0,n){
        int a,d;
        cin >> a >> d;
        A.push_back(a);
        D.push_back(d);
        sumd += d;

        for(int suma = MAXN*MAXA-1; suma >= a; suma--){
            DP[suma] = max(DP[suma], DP[suma-a] + a-d);
        }

    }
    for(int suma = MAXN*MAXA-2; suma >= 0; suma--){
        DP[suma] = max(DP[suma], DP[suma+1]);
    }

    cin >> q;
    vi ANS(3, 0);
    rep(c1,0,q){
        int a,d;
        cin >> a >> d;
        int ans = 0; 
        if(sumd >= a)ans = 1;
        if(DP[d+1] >= a+d-sumd)ans = 1;
        if(DP[d+1] > a+d-sumd)ans = 2;
        ANS[2-ans]++;
    }
    cout << ANS[0] << " " << ANS[1] << " " << ANS[2] << "\n";


    return 0;
}