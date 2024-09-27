#include <bits/stdc++.h>

typedef long long ll;
const long long inf = 2e9;
using namespace std;

ll LOG=20;
ll getLca(ll a, ll b, vector<vector<pair<ll,ll>>> & parents, vector<ll> & dist){
    ll diff=dist[a]-dist[b];
    if(diff>0)swap(a,b);
    diff=abs(diff);
    for(int i=LOG-1; i>=0; i--){
        if((1<<i) & diff)b=parents[i][b].first;
    }
    if(a==b)return a;
    for(int i=LOG-1; i>=0; i--){
        if(parents[i][a].first!=parents[i][b].first){
            a=parents[i][a].first;
            b=parents[i][b].first;
        }
    }
    return parents[0][a].first;
}

ll getKthAncestor(ll x,ll k,vector<vector<pair<ll,ll>>> & parents){
    ll ans=x;
    for(int j=0; j<LOG; j++){
        if((1<<j)& k)ans=parents[j][ans].first;
    }
    return ans;
}
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
    for(auto &a:v)cin>>a;
    vector<vector<pair<ll,ll>>> parents(LOG,vector<pair<ll,ll>>(n,{-1,inf}));
    queue<ll> q;
    q.push(root);
    vector<ll> dist(n,-1);
    dist[root] = 0;
    parents[0][0]={0,inf};
    while (!q.empty())
    {
        ll cur = q.front();
        q.pop();
        for(auto & a: g[cur])
        {
            if (dist[a]==-1)
            {
                parents[0][a] = {cur,v[cur]};
                dist[a]=dist[cur]+1;
                q.push(a);
            }
        }
    }
    for(int i=1; i<LOG; i++){
        for(int j=0; j<n; j++){
            parents[i][j]={parents[i-1][parents[i-1][j].first].first,min(parents[i-1][j].second,parents[i-1][parents[i-1][j].first].second)};
        }
    }
    while(Q--){
        ll a,b,val;
        cin>>a>>b>>val;
        a--,b--;
        val%=v[a];
        ll lca=getLca(a,b,parents,dist);
        // Getting the closest node to the current node whose weight is less or equal to val
        ll cur=a;
        while(cur!=lca){
            for(int i=LOG-1; i>=0; i--){
                if(parents[i][cur].second>val and dist[parents[i][cur].first]>dist[lca])cur=parents[i][cur].first;
            }
            cur=parents[0][cur].first;
            val%=v[cur];
        }
        
        // Going down to the end node. This happens in (LogN)^3.
        while(cur!=b){
            ll diff=dist[b]-dist[cur];
            for(int i=LOG-1; i>=0; i--){
                if((1<<i) >diff)continue;
                ll k=diff- (1<<i);
                if(parents[i][getKthAncestor(b,k,parents)].second>val)cur=getKthAncestor(b,k,parents);
            }
            val%=v[cur];
        }
        cout<<val<<'\n';
    }
    return 0;
}