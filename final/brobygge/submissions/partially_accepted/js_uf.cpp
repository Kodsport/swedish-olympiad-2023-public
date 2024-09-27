#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(it,x) for(auto& it : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template<typename T, typename S> ostream& operator<<(ostream& os, const pair<T, S>& v) { return os << v.first << " " << v.second; }
template<typename T, typename S> istream& operator>>(istream& is, const pair<T, S>& v) { return is >> v.first >> v.second; }
template<typename T> ostream& operator<<(ostream& os, const vector<T>& v) { rep(i, 0, sz(v)) { if (i) os << " " << v[i]; else os << v[i]; } os << endl; return os; }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { trav(it, v) is >> it; return is; }
template<typename T> using v = vector<T>; template<typename T> using vv = v<v<T>>; template<typename T> using vvv = v<v<v<T>>>;
template<typename T> std::vector<T> make(T init, std::size_t size) { return std::vector<T>(size, init); }
template<typename T, typename... Args> auto make(T init, std::size_t first, Args... sizes) { auto inner = make<T>(init, sizes...); return std::vector<decltype(inner)>(first, inner); }
template<typename A, typename B> auto smax(A& a, const B& b) { if (b > a) a = b; }
template<typename A, typename B> auto smin(A& a, const B& b) { if (b < a) a = b; }
bool within(int r, int c, int R, int C) { return 0 <= r && r < R && 0 <= c && c < C; }

struct UF {
    vi e;
    UF(int n) : e(n, -1) {}
    bool sameSet(int a, int b) { return find(a) == find(b); }
    int size(int x) { return -e[find(x)]; }
    int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
    bool join(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (e[a] > e[b]) swap(a, b);
        e[a] += e[b]; e[b] = a;
        return true;
    }
};

vector<pii> deltas = {
    {-1, 0},
    {1, 0},
    {0, 1},
    {0, -1},
};

void solve() {
    int N, M, T;
    cin >> N >> M >> T;

#define SOURCE 0
#define S(r, c) ((r)*M + (c))
#define SINK S(N, 0)
#define STATES SINK + 1

    vector<vector<bool>> added = make(false, N, M);

    UF uf(STATES);
    rep(i, 0, T) {
        int r, c;
        cin >> r >> c;
        added[r][c] = true;
        for (auto [dr, dc] : deltas) {
            int nr = r + dr,
                nc = c + dc;
            if (within(nr, nc, N, M) && added[nr][nc]) {
                uf.join(S(r, c), S(nr, nc));
            }
            if (nr == 0) uf.join(SOURCE, S(r, c));
            if (nr == N - 1) uf.join(S(r, c), SINK);
        }


        if (uf.sameSet(SOURCE, SINK)) {
            cout << i + 1 << endl;
            return;
        }
    }

    cout << "nej";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int TC = 1;
    if (!TC) cin >> TC;
    rep(i, 1, TC + 1) {
        // cout << i << " ";
        solve();
    }
}
