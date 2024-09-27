#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(it,x) for(auto& it : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template<typename T, typename S> ostream& operator<<(ostream& os, const pair<T, S> &v) { return os << v.first << " " << v.second; }
template<typename T, typename S> istream& operator>>(istream& is, const pair<T, S> &v) { return is >> v.first >> v.second; }
template<typename T> ostream& operator<<(ostream& os, const vector<T> &v) { rep(i,0,sz(v)) { if (i) os << " " << v[i]; else os << v[i]; } os << endl; return os; }
template<typename T> istream& operator>>(istream& is, vector<T> &v) { trav(it, v) is >> it; return is; }
template<typename T> using v = vector<T>; template<typename T> using vv = v<v<T>>; template<typename T> using vvv = v<v<v<T>>>;
template<typename T> std::vector<T> make(T init, std::size_t size) { return std::vector<T>(size, init); }
template<typename T, typename... Args> auto make(T init, std::size_t first, Args... sizes) { auto inner = make<T>(init, sizes...); return std::vector<decltype(inner)>(first, inner); }
template<typename A, typename B> auto smax(A& a, const B& b) { if (b > a) a = b; }
template<typename A, typename B> auto smin(A& a, const B& b) { if (b < a) a = b;}
bool within(int r, int c, int R, int C) { return 0 <= r && r < R && 0 <= c && c < C; }

void solve() {
    int N;
    cin >> N;
    vi F(N);
    vector<string> S(N);
    rep(i,0,N) {
        cin >> F[i] >> S[i];
    }

    int res = 0;
    for (int i = 0; i < N - 1; i++) {
        vector<vi> dist = make(10000, 101, 256);
        deque<pair<int, char>> at;
        trav(it, S[i]) {
            at.emplace_back(F[i], it);
            dist[F[i]][it] = 0;
        }

        auto push_back = [&](int f, int s, int d) {
            if (d < dist[f][s]) {
                dist[f][s] = d;
                at.emplace_back(f, s);
            }
        };
        auto push_front = [&](int f, int s, int d) {
            if (d < dist[f][s]) {
                dist[f][s] = d;
                at.emplace_front(f, s);
            }
        };
        while (!at.empty()) {
            int floor;
            char stair;
            tie(floor, stair) = at.front(); at.pop_front();

            int d = dist[floor][stair];
            if (floor > 1) {
                push_back(floor - 1, stair, d + 1);
            }
            if (floor < 100) {
                push_back(floor + 1, stair, d + 1);
            }

            rep(s,0,N) if (F[s] == floor && count(all(S[s]), stair))
                trav(it, S[s]) push_front(floor, it, d);
        }

        res += dist[F[i + 1]][S[i + 1][0]];
    }
    cout << res << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int TC = 1;
    if (!TC) cin >> TC;
    rep(i,1,TC+1) {
        // cout << i << " ";
        solve();
    }
}

