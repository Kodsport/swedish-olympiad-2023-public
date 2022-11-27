// #pragma GCC target ("avx,avx2,fma")
// #pragma GCC optimize ("Ofast,inline") // O1 - O2 - O3 - Os - Ofast
// #pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (b) - 1; i >= (a); --i)
#define trav(a, x) for (auto &a : x)

#define all(x) x.begin(), x.end()
#define sz(x) x.size()
#define pb push_back
#define debug(x) cout<<#x<<" = "<<x<<endl

#define umap unordered_map
#define uset unordered_set

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;

const int INF = 1'000'000'007;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n,k;
    vii planks;

    cin>>n>>k;
    rep(i,0,n) {
        int h;
        cin>>h;
        planks.emplace_back(h,i);
    }
    
    sort(all(planks));
    set<int> activated;
    activated.insert(-1);
    activated.insert(n);
    
    ll ans=0;

    trav(plank,planks) {
        int h,i;
        tie(h,i)=plank;
        
        auto it=activated.insert(i).first;
        auto l=it,r=it;
        --l;
        ++r;
        int cnt=0;

        //cout<<"lo = "<<*l<<" hi = "<<*r<<endl;

        while(cnt<k) {
            if(l==activated.begin()) break;
            --l;
            ++cnt;
        }

        while(cnt<k) {
            ++r;
            if(r==activated.end()) {
                --r;
                break;
            }
            ++cnt;
        }

        while(l!=it&&r!=activated.end()) {
            int lo=*l+1,hi=*r-1;
            ans=max(ans,ll(h)*(hi-lo+1));
            ++l;
            ++r;
        }
    }

    cout<<ans<<endl;
    return 0;
}