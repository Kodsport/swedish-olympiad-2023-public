#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n,T;

vector<ll> query(ll y){
    cout << "? " << y << "\n";
    fflush(stdout);
    vector<ll> res(n);
    for(ll c1 = 0; c1 < n; c1++){
        cin >> res[c1];
    }
    return res;
}

map<ll,ll> make_map(vector<ll> &V){
    map<ll,ll> res;
    for(auto v : V){
        if(res.find(v) == res.end())res[v] = 0;
        res[v]++;
    }
    return res;
}

ll map_count(map<ll,ll> &M, ll x){
    if(M.find(x) == M.end())return 0;
    return M[x];
}

void inc(map<ll,ll> &M, ll x){
    if(M.find(x) == M.end())M[x] = 0;
    M[x]++;
}

ll odd_one_out(map<ll,ll> &M1, map<ll,ll> &M2){
    for(auto p : M1){
        ll x = p.first;
        ll f = p.second;
        if(f == 0)continue;
        if(M2.find(x) == M2.end() || M2[x] < f){
            return x;
        }
    }
    return -1;
}

int main(){
    cin >> n >> T;

    vector<ll> Q1 = query(1);
    ll last = 1;
    for(ll c1 = 0; c1 < n; c1++){
        last += Q1[c1];
    }
    vector<ll> ans;
    if(n > 1){
        map<ll,ll> M1 = make_map(Q1);
        if(Q1[0] == 0){
            ans.push_back(1);
        }
        else{
            vector<ll> Q2 = query(2);
            map<ll,ll> M2 = make_map(Q2);
            ll x = odd_one_out(M1, M2);
            ans.push_back(x+1);
        }
        for(ll c1 = 1; c1 < n-1; c1++){
            vector<ll> V = query(ans.back()+1);
            map<ll,ll> M2 = make_map(V);

            // adjust map
            if(c1 == 1){
                M1[ans[0]-1]--;
                inc(M1, 1);
            }
            else{
                M1[ans[c1-1] - ans[c1-2] - 1]--;
                inc(M1, ans[c1-1] - ans[c1-2]);
            }

            ll x = odd_one_out(M1, M2);
            ans.push_back(ans.back()+x);
            M1 = M2;
        }
    }
    ans.push_back(last);
    cout << "! ";
    for(ll c1 = 0; c1 < n; c1++){
        cout << ans[c1] << " ";
    }cout << "\n";
    fflush(stdout);

}