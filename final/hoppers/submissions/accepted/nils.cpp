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
const ll MAXN = 1000001;
int n,N;

// > ^ < v
int DX[4] = {0, -1, 0, 1};
int DY[4] = {1, 0, -1, 0};

vi C;
vector<vi> C2(MAXN, vi());
int INDEX[MAXN] = {0};

int parse(char ch){
    if(ch == '>')return 0;
    if(ch == '^')return 1;
    if(ch == '<')return 2;
    if(ch == 'v')return 3;
    return -1; 
}

int indeg[MAXN] = {0};
bool cycle[MAXN] = {0};
int cycle_length[MAXN] = {0};
int ORD[MAXN] = {0};
int ID[MAXN] = {0};
vector<vi> cycles;

int SS[MAXN] = {0};

bool comp(int i, int j){
    return SS[i] < SS[j];
}

int ANS[MAXN] = {0};
int DIST[MAXN] = {0};

map<int,int> MG;
map<int,int> dfs(int i, bool heavy){
    if(sz(C2[i]) == 0){
        map<int,int> res;
        if(INDEX[i] != 0){
            int j = INDEX[i]-1;
            res[DIST[i]] = j;
        }
        if(heavy){
            MG = res;
            return {};
        }
        else{
            return res;
        }
    }

    vector<map<int,int> > MAPS;

    rep(c1,0,sz(C2[i])-1){
        int j = C2[i][c1];
        DIST[j] = DIST[i]+1;
        MAPS.push_back(dfs(j, 0));
    }
    DIST[C2[i].back()] = DIST[i]+1;
    dfs(C2[i].back(), 1);

    set<int> bad_dist;

    trav(m, MAPS){
        trav(p, m){
            int d = p.first;
            int j = p.second;
            if(MG.find(d) == MG.end()){
                MG[d] = j;
            }
            else{
                ANS[j] = i;
                bad_dist.insert(d);
            }
        }
    }
    if(INDEX[i] != 0){
        int d = DIST[i];
        int j = INDEX[i]-1;
        if(MG.find(d) == MG.end()){
            MG[d] = j;
        }
        else{
            ANS[j] = i;
            bad_dist.insert(d);
        }
    }

    trav(d, bad_dist){
        ANS[MG[d]] = i;
        MG.erase(d);
    }

    if(!heavy){
        return MG;
    }
    return {};

}

vector<vector<vi>> TUPP(MAXN, vector<vi>());

bool comp2(vi tupp1, vi tupp2){
    return tupp1[0] < tupp2[0];
}

int NODE[MAXN] = {0};

bool spawnkill[MAXN] = {0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int r,c;
    
    cin >> r >> c >> n;
    N = r*c;

    rep(c1,0,r){
        string s;
        cin >> s;
        rep(c2,0,c){
            int z = parse(s[c2]);
            int i = c1*c+c2;
            int x2 = c1+DX[z];
            int y2 = c2+DY[z];
            int j = x2*c+y2;
            C.push_back(j);
            C2[j].push_back(i);
            indeg[j]++;
            cycle[i] = 1;
            SS[i] = 1;
    
        }
    }

    rep(c1,0,n){
        int x,y;
        cin >> x >> y;
        int i = x*c+y;
        NODE[c1] = i;
        ANS[c1] = big;
        if(spawnkill[i]){
            ANS[c1] = i;
        }
        else{
            if(INDEX[i] != 0){
                ANS[c1] = i;
                ANS[INDEX[i]-1] = i;
                INDEX[i] = 0; 
                spawnkill[i] = 1;
            }
            else{
                INDEX[x*c+y] = c1+1;
            }
        }
    }

    vi leaves;
    rep(c1,0,N){
        if(indeg[c1] == 0){
            leaves.push_back(c1);
        }
    }

    while(sz(leaves) > 0){
        int v = leaves.back();
        leaves.pop_back();
        cycle[v] = 0;
        int w = C[v];
        indeg[w]--;
        SS[w] += SS[v];
        if(indeg[w] == 0){
            leaves.push_back(w);
        }
    }

    int cycs = 0;
    rep(c1,0,N){
        if(cycle[c1] && cycle_length[c1] == 0){
            vi cyc;
            int v = c1;
            while(1){
                ORD[v] = sz(cyc);
                cyc.push_back(v);
                v = C[v];
                if(v == c1)break;
            }
            trav(y, cyc){
                cycle_length[y] = sz(cyc);
                ID[y] = cycs;
            }
            cycles.push_back(cyc);
            cycs++;
        }
    }

    rep(c1,0,N){
        sort(all(C2[c1]), comp);
    }

    rep(c1,0,N){
        if(cycle[c1] && INDEX[c1] != 0){
            int j = INDEX[c1]-1;
            vi V = {0, c1, j};
            TUPP[ID[c1]].push_back(V);
        }
        if(!cycle[c1] && cycle[C[c1]]){
            dfs(c1, 1);
            int v = C[c1];
            trav(p, MG){
                int d = p.first+1;
                int j = p.second;
                TUPP[ID[v]].push_back({d, v, j});
            }
        }
    }
 
    rep(id, 0, sz(cycles)){
        int siz = sz(cycles[id]);
        vi REM(siz, -1);
        vi COL(siz, -1);
        sort(all(TUPP[id]), comp2);
        
        trav(tupp, TUPP[id]){
            int t = tupp[0];
            int v = tupp[1];
            int j = tupp[2];
            int r = (ORD[v] - t) % siz;
            if(r < 0)r = siz+r;

            if(REM[r] != -1){
                ANS[REM[r]] = v;
                ANS[j] = v;
                COL[r] = t;
                REM[r] = -1;
            }
            else{
                if(COL[r] == t){
                    ANS[j] = v;
                }
                else{
                    REM[r] = j;
                }
            }
        }
    }

    rep(c1,0,n){
        if(ANS[c1] == big){
            cout << "cycle\n";
        }
        else{
            cout << ANS[c1]/c << " " << ANS[c1]%c << "\n";
        }
    }

    return 0;
}