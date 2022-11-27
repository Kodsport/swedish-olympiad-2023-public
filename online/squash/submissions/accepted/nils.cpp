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

const int MAXN = 1001;

int n,k;
vi A;
int DP[MAXN][2][2] = {0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    string s;
    cin >> s;
    rep(c1,0,n){
        if(s[c1] == 'V')A.push_back(1);
        if(s[c1] == 'F')A.push_back(-1);
    }
    A.push_back(-123456);
    rep(c1,0,k+1){
        rep(c2,0,2){
            DP[c1][c2][1] = -123456;
        }
    }
    DP[0][0][1] = 0;

    rep(i,0,n+1){
        int i2 = i%2;
        int j2 = (i+1)%2;
        rep(runs, 0, k+1){
            DP[runs][0][i2] = max(DP[runs][0][j2], DP[runs][1][j2]);
            DP[runs][1][i2] = A[i] + DP[runs][1][j2];
            if(runs > 0){
                DP[runs][1][i2] = max(DP[runs][1][i2], A[i] + DP[runs-1][0][j2]);
                DP[runs][1][i2] = max(DP[runs][1][i2], A[i] + DP[runs-1][1][j2]);
            }
        }
    }
    int ans = 0;
    rep(c1,0,k+1){
        ans = max(ans, DP[c1][0][n%2]);
    }
    cout << ans << "\n";
    return 0;
}