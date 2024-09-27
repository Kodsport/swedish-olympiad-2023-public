#include <bits/stdc++.h>
using namespace std;

int n,T;

vector<int> query(int y){
    cout << "? " << y << "\n";
    fflush(stdout);
    vector<int> res(n);
    for(int c1 = 0; c1 < n; c1++){
        cin >> res[c1];
    }
    return res;
}

map<int,int> make_map(vector<int> &V){
    map<int,int> res;
    for(auto v : V){
        if(res.find(v) == res.end())res[v] = 0;
        res[v]++;
    }
    return res;
}

int map_count(map<int,int> &M, int x){
    if(M.find(x) == M.end())return 0;
    return M[x];
}

void inc(map<int,int> &M, int x){
    if(M.find(x) == M.end())M[x] = 0;
    M[x]++;
}

int odd_one_out(map<int,int> &M1, map<int,int> &M2){
    for(auto p : M1){
        int x = p.first;
        int f = p.second;
        if(f == 0)continue;
        if(M2.find(x) == M2.end() || M2[x] < f){
            return x;
        }
    }
    return -1;
}

int main(){
    cin >> n >> T;

    vector<int> Q1 = query(1);
    int last = 1;
    for(int c1 = 0; c1 < n; c1++){
        last += Q1[c1];
    }
    vector<int> ans;
    if(n > 1){
        map<int,int> M1 = make_map(Q1);
        if(Q1[0] == 0){
            ans.push_back(1);
        }
        else{
            vector<int> Q2 = query(2);
            map<int,int> M2 = make_map(Q2);
            int x = odd_one_out(M1, M2);
            ans.push_back(x+1);
        }
        for(int c1 = 1; c1 < n-1; c1++){
            vector<int> V = query(ans.back()+1);
            map<int,int> M2 = make_map(V);

            // adjust map
            if(c1 == 1){
                M1[ans[0]-1]--;
                inc(M1, 1);
            }
            else{
                M1[ans[c1-1] - ans[c1-2] - 1]--;
                inc(M1, ans[c1-1] - ans[c1-2]);
            }

            int x = odd_one_out(M1, M2);
            ans.push_back(ans.back()+x);
            M1 = M2;
        }
    }
    query(1);
    query(1);
    ans.push_back(last);
    cout << "! ";
    for(int c1 = 0; c1 < n; c1++){
        cout << ans[c1] << " ";
    }cout << "\n";
    fflush(stdout);

}