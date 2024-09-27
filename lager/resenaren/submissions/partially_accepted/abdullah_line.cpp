#include <bits/stdc++.h>

typedef long long ll;
const long long inf = 2e9;
using namespace std;

ll LOG=20;
struct SparseTable {
    ll n;
    vector<vector<int>> p;
    SparseTable(vector<int> & v){
        n=v.size();
        p.resize(LOG,vector<int>(n));
        p[0]=v;
        for(int i=1; i<LOG; i++){
            for(int j=0; j<(n-(1<<i)+1); j++){
                p[i][j]=min(p[i-1][j],p[i-1][j+(1<<(i-1))]);
            }
        }
    }
    ll rmq(ll l, ll r){ // [l,r]
        ll diff=r-l+1;
        return min(p[log2(diff)][l],p[log2(diff)][r-(1<<(int)(log2(diff)))+1]);
    }

    ll nearestLeqLeft(ll lo, ll x){
        ll l=0,r=lo;
        while(l<=r){
            ll mid=(l+r)/2;
            if(rmq(mid,r)<=x)l=mid+1;
            else r=mid-1;
        }
        return r;
    }

    ll nearestLeqRight(ll lo, ll x){
        ll l=lo,r=n-1;
        while(l<=r){
            ll mid=(l+r)/2;
            if(rmq(l,mid)<=x)r=mid-1;
            else l=mid+1;
        }
        return l;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n, Q;
    cin >> n>>Q;
    ll root = 0;
    vector<vector<ll>> g(n);
    for(int i=0;i<n-1;i++)
    {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> v(n);
    for(int i=0; i<n; i++)cin>>v[i];
    SparseTable sparseTable(v);
    while(Q--){
        ll a,b,val;
        cin>>a>>b>>val;
        a--,b--;
        if(a<b){
            ll l=a;
            val%=v[a];
            while(l<=b){
                l=sparseTable.nearestLeqRight(l,val);
                if(l<=b)val%=v[l];
            }
        }
        else {
            ll l=a;
            val%=v[a];
            while(l>=b){
                l=sparseTable.nearestLeqLeft(l,val);
                if(l>=b)val%=v[l];
            }
        }
        cout<<val<<'\n';
    }
    return 0;
}