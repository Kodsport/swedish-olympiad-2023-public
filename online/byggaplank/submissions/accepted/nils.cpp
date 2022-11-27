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

const int MAXN = 50001;

int n, k;
vi H, ind, leq;

int PREV[MAXN];
int NEXT[MAXN];

bool comp(int i, int j){
    if(H[i] == H[j])return i<j;
    return H[i] < H[j];
}

int FIRST;

int step(int i, int d){
    if(d == 0)return i;
    if(d < 0 && i == -1)return i;
    if(d > 0 && i == n)return i;
    if(d > 0 && i == -1)return step(FIRST, d-1);
    if(d > 0)return step(NEXT[i], d-1);
    return step(PREV[i], d+1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    vi st;
    rep(c1,0,n){
        int a;
        cin >> a;
        H.push_back(a);
        ind.push_back(c1);
        while(sz(st) > 0 && H[st.back()] > a){
            st.pop_back();
        }
        if(sz(st) == 0){
            leq.push_back(-1);
        }
        else{
            leq.push_back(st.back());
        }
        st.push_back(c1);
        PREV[c1] = -1;
        NEXT[c1] = n;
    }
    sort(all(ind), comp);
    ll ans = 0;

    FIRST = n;

    rep(c1,0,n){
        int i = ind[c1];
        int x = step(leq[i], -k);
        int y = step(leq[i], 1);

        int x2 = x;
        int k2 = 0;
        while(x2 != y){
            x2 = step(x2,1);
            if(x2 != y)k2++;
        }
        y = step(y, k-k2);

        rep(c1,0,k+1){
            ll w = y-x-1;
            ans = max(ans, w*H[i]);
            x = step(x, 1);
            y = step(y, 1);
        }
        int R;
        int L = leq[i];
        if(L == -1){
            R = FIRST;
            FIRST = i;
        }
        else{
            R = NEXT[L];
        }
        if(L != -1)NEXT[L] = i;
        PREV[i] = L;
        if(R != n)PREV[R] = i;
        NEXT[i] = R;
    }
    cout << ans << "\n";


    return 0;
}