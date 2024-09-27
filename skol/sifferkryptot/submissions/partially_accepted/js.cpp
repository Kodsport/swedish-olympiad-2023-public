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
    string S;
    cin >> S;

    ll res = 1;
    for (int i = 0; i < sz(S); i++) {
        bool is12 = S[i] == '1' || S[i] == '2';
        bool nextis12 = (i + 1 != sz(S)) && (S[i + 1] == '1' || S[i + 1] == '2');
        bool nextis39 = i + 1 < sz(S) && '3' <= S[i + 1];
        bool nextnextis39 = i + 2 < sz(S) && '3' <= S[i + 2];
        bool nextnextisend = i + 2 >= sz(S);

        if (is12 && nextis39) {
            res *= 2;
        } else if (is12 && nextis12 && nextnextis39) {
            res *= 3;
            i++;
        } else if (is12 && nextis12 && nextnextisend) {
            res *= 2;
            i++;
        }
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

