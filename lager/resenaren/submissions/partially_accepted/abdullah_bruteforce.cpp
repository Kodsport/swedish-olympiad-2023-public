#include <bits/stdc++.h>

typedef long long ll;
const long long inf = 2e9;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n, Q;
    cin >> n>>Q;
    ll root = 0;
    vector<vector<ll>> g(n);
    vector<ll> v(n);
    for(int i=0;i<n-1;i++)
    {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i=0; i<n; i++)cin>>v[i];
    while(Q--){
        ll a,b,val;
        cin>>a>>b>>val;
        a--,b--;
        vector<ll> ans(n,-1);
        queue<ll> q;
        q.push(a);
        ans[a]=val%v[a];
        while(!q.empty()){
            ll cur=q.front();
            q.pop();
            for(auto a: g[cur]){
                if(ans[a]==-1){
                    ans[a]=ans[cur]%v[a];
                    q.push(a);
                }
            }
        }
        cout<<ans[b]<<'\n';
    }
    return 0;
}