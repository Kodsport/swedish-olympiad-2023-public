#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <limits.h>
#include <math.h>
#include <chrono>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;


#define ll long long
#define vi vector<ll>
#define vvi vector<vi>
#define p2 pair<ll, ll>
#define p3 tuple<ll,ll,ll>
#define p4 vi
#define ip3 tuple<int,int,int>
#define ip4 tuple<int,int,int,int>
#define vp2 vector<p2>
#define vp3 vector<p3>
#define inf 2e9
#define linf 1e17

#define read(a) cin >> a
#define write(a) cout << (a) << "\n"
#define dread(type, a) type a; cin >> a
#define dread2(type, a, b) dread(type, a); dread(type, b)
#define dread3(type, a, b, c) dread2(type, a, b); dread(type, c)
#define dread4(type, a, b, c, d) dread3(type, a, b, c); dread(type, d)
#define dread5(type, a, b, c, d, e) dread4(type, a, b, c, d); dread(type, e)
#ifdef _DEBUG
#define deb __debugbreak();
#else
#define deb ;
#endif

#define rep(i, high) for (ll i = 0; i < high; i++)
#define repp(i, low, high) for (ll i = low; i < high; i++)
#define repe(i, container) for (auto& i : container)
#define per(i, high) for (ll i = high; i >= 0; i--)

#define readpush(type,vect) type temp; read(temp); vect.push_back(temp);
#define readvector(type, name, size) vector<type> name(size); rep(i,size) {dread(type,temp); name[i]=temp;}
#define readinsert(type,a) {type temp; read(temp); a.insert(temp);}
#define all(a) begin(a),end(a)
#define setcontains(set, x) (set.find(x) != set.end())
#define stringcontains(str, x) (str.find(x) != string::npos)
#define within(a, b, c, d) (a >= 0 && a < b && c >= 0 && c < d)

#define ceildiv(x,y) ((x + y - 1) / y)
#define fract(a) (a-floor(a))
#define sign(a) ((a>0) ? 1 : -1)

auto Start = chrono::high_resolution_clock::now();

inline void fast()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

vector<string> dirmap;
vector<set<int>> visiteds;
vector<string> results;
vector<pair<int, int>> positions;
set<int> crates_left;

map<char, pair<int, int>> dMao = {
    { '>', pair<int, int>(1, 0) },
    { '<', pair<int, int>(-1, 0) },
    { '^', pair<int, int>(0, -1) },
    { 'v', pair<int, int>(0, 1) },
};

int main() {
    int w, h, n;
    cin >> w >> h >> n;

    dirmap.resize(w);
    for (int y = 0; y < w; y++) {
        cin >> dirmap[y];
    }

    results.resize(n, "cycle");
    positions.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> positions[i].second >> positions[i].first;
        crates_left.insert(i);
    }

    visiteds.resize(n);

    while (true)
    {
        map<int, vector<int>> curr_poss;

        int num_loop = 0;
        for (int i : crates_left) {
            auto& [x, y] = positions[i];

            int id = x * w + y;
            if (curr_poss.find(id) == curr_poss.end()) curr_poss.insert({ id, vector<int>() });
            curr_poss.at(id).push_back(i);

            if (visiteds[i].find(id) != visiteds[i].end()) {
                num_loop++;
            }
            else {
                visiteds[i].insert(id);
            }
        }

        for (auto& [pos, crates] : curr_poss) {
            if (crates.size() <= 1) continue;
            else {
                for (int c : crates) {
                    int x = pos % w;
                    int y = pos / w;

                    num_loop = 0;
                    results[c] = to_string(x) + string(" ") + to_string(y);
                    crates_left.erase(c);
                }
            }
        }

        if (num_loop >= crates_left.size()) break;

        for (int i : crates_left) {
            auto& [x, y] = positions[i];
            auto& [dx, dy] = dMao[dirmap[y][x]];

            x += dx;
            y += dy;

        }
    }


    for (int i = 0; i < n; i++) cout << results[i] << endl;
}