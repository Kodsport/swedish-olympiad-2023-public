#undef _GLIBCXX_DEBUG                // disable run-time bound checking, etc
#pragma GCC optimize("Ofast,inline") // Ofast = O3,fast-math,allow-store-data-races,no-protect-parens
#pragma GCC optimize ("unroll-loops")

#pragma GCC target("bmi,bmi2,lzcnt,popcnt")                      // bit manipulation
#pragma GCC target("movbe")                                      // byte swap
#pragma GCC target("aes,pclmul,rdrnd")                           // encryption
#pragma GCC target("avx,avx2,f16c,fma,sse3,ssse3,sse4.1,sse4.2") // SIMD

#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;

#define enablell 1

typedef long long ll;
typedef unsigned long long ull;
#if enablell
#define int ll
#define inf int(1e18)
#define float double
#else
const int inf = int(2e9);
#endif
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<vvb> vvvb;
typedef pair<int, int> p2;
typedef vector<p2> vp2;
typedef vector<vp2> vvp2;
typedef vector<vvp2> vvvp2;
typedef tuple<int, int, int> p3;
typedef vector<p3> vp3;
typedef vector<vp3> vvp3;
typedef vector<vvp3> vvvp3;
typedef tuple<int, int, int, int> p4;
typedef vector<p4> vp4;

#define PBDS 1
#define _LOCAL _MSC_VER > 0
#if _LOCAL
#define gc() getchar()
#define popcount(x) __popcnt(x)
#define leading_zeros(x) _lzcnt_u32(x)
uint32_t clz(uint32_t x) { return _lzcnt_u32(x); }
uint32_t ctz(uint32_t x) { return _tzcnt_u32(x); }
#define bswap64(x) _byteswap_uint64(x)
#define assert(x) debassert(x)
#else
#define popcount(x) __builtin_popcount(x)
uint32_t clz(uint32_t x) { return __builtin_clz(x); }
uint32_t ctz(uint32_t x) { return __builtin_ctzll(x); }
#define bswap64(x) __builtin_bswap64(x)
#define gc() getchar_unlocked()
#if PBDS
using namespace __gnu_pbds;
// lower_bound is now upper_bound and vice versa (multiset). generally a bit broken
template<typename T> using indexed_multiset = tree<int, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T> using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
struct chash { // large odd number for C
    const uint64_t C = ll(4e18 * acos(0)) | 71;
    ll operator()(ll x) const { return __builtin_bswap64(x * C); }
};

template<typename T, typename U> using fast_map = __gnu_pbds::gp_hash_table<T, U, chash>;
template<typename T> using fast_set = __gnu_pbds::gp_hash_table<T, null_type, chash>;
template<typename T, typename H> using fast_set_h = __gnu_pbds::gp_hash_table<T, null_type, H>;
#endif

#endif

#define FAST_INPUT 0
#define FILE_TC 0
#if FILE_TC && _LOCAL
//ifstream filein("C:\\Users\\Matis\\source\\repos\\Comp prog\\x64\\Debug\\in.txt");
ifstream filein("E:\\desktop\\code\\repos\\Comp prog\\x64\\Debug\\data9.txt");
//ifstream filein("E:\\desktop\\po-repos\\swedish-olympiad-2023\\online\\tomtplanering\\data\\secret\\group10\\010-case10.in");

#define cin filein
//ifstream cin("C:\\Users\\Matis\\desktop\\po-two\\swedish-olympiad-2014\\");
void fast() {}
#else
inline void fast() { ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }
#endif

#if FAST_INPUT && !FILE_TC
inline void read(int& v) { v = 0; int sign = 1; char c = gc(); if (c == '-') { sign = -1; } else { v += c - '0'; } while ((c = gc()) != EOF && c != ' ' && c != '\n') { v *= 10; v += c - '0'; } v *= sign; }
inline void read(int& u, int& v) { read(u); read(v); }
inline void read(int& u, int& v, int& k) { read(u); read(v); read(k); }
//inline void read(int& v) { char c; while ((c = getchar()) != EOF && c != ' ' && c != '\n') { v *= 10; v += c - '0'; } }
inline void read(string& s) { char c; while ((c = gc()) != EOF && c != '\n' && c != ' ') { s.push_back(c); } }
#else
template <typename T> inline void read(T& a) { cin >> a; }
template <typename T> inline void read(T& a, T& b) { cin >> a >> b; }
template <typename T> inline void read(T& a, T& b, T& c) { cin >> a >> b >> c; }
#endif
template <typename T> inline void write(T a) { cout << (a) << "\n"; }
#define quit cout << endl; _Exit(0);
#define dread(type, a) type a; read(a)
#define dread2(type, a, b) dread(type, a); dread(type, b)
#define dread3(type, a, b, c) dread2(type, a, b); dread(type, c)
#define dread4(type, a, b, c, d) dread3(type, a, b, c); dread(type, d)
#define dread5(type, a, b, c, d, e) dread4(type, a, b, c, d); dread(type, e)
#define readvector(type, name, size) vector<type> name(size); rep(i,size) {dread(type,temp); name[i]=temp;}
#ifdef _DEBUG
#define noop cout << "";
#define deb __debugbreak();
#define debassert(expr) if (!(expr)) deb;
#define debif(expr) if(expr) deb;
#else
#define noop ;
#define deb ;
#define debassert(expr) ;
#define debif(expr) ;
#endif

#define rep(i, high) for (int i = 0; i < high; i++)
#define repp(i, low, high) for (int i = low; i < high; i++)
#define repe(i, container) for (auto& i : container)
#define per(i, high) for (int i = high-1; i >= 0; i--)
#define perr(i, low, high) for (int i = high-1; i >= low; i--)

#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define setcontains(set, x) (set.find(x) != set.end())
#define within(a, b, c, d) (a >= 0 && a < b && c >= 0 && c < d)
#define sz(container) ((int)container.size())
#define mp(a,b) (make_pair(a,b))

#define ceildiv(x,y) ((x + y - 1) / y)

template<typename T> inline void eraseOne(multiset<T>& mSet, T k) { auto itr = mSet.find(k); if (itr != mSet.end()) { mSet.erase(itr); } }
template<typename T, typename U> inline T first(U& a) { return *begin(a); }
template <typename T, typename U> inline void operator+=(pair<T, U>& l, const pair<T, U>& r) { l = { l.first + r.first,l.second + r.second }; }
template <typename T, typename U> inline pair<T, U> operator+(const pair<T, U> l, const pair<T, U> r) { return { l.first + r.first, l.second + r.second }; }
template <typename T, typename U> inline pair<T, U> operator-(const pair<T, U> l, const pair<T, U> r) { return { l.first - r.first, l.second - r.second }; }
template <typename T, typename U> inline pair<T, U> operator*(const pair<T, U> l, const int m) { return { l.first * m, l.second * m }; }
template <typename Out> inline void split(const string& s, char delim, Out result) { istringstream iss(s); string item; while (getline(iss, item, delim)) { *result++ = item; } }
inline vector<string> split(const string& s, char delim) { vector<string> elems; split(s, delim, back_inserter(elems)); return elems; }
vector<string> split(string s, string d) { size_t k = 0, n, e = d.length(); string t; vector<string> r; while ((n = s.find(d, k)) != string::npos) { t = s.substr(k, n - k); k = n + e; r.push_back(t); } r.push_back(s.substr(k)); return r; }
ll binpow(ll a, ll b) { ll res = 1; while (b > 0) { if (b & 1) res = res * a; a = a * a; b >>= 1; } return res; }
ll binpow(ll a, ll b, ll m) { a %= m; long long res = 1; while (b > 0) { if (b & 1) res = res * a % m; a = a * a % m; b >>= 1; } return res; } // For a < 2^31

#if 1
auto Start = chrono::high_resolution_clock::now();
void resettimer() { Start = chrono::high_resolution_clock::now(); }
int elapsedmillis() { return chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - Start).count(); }
random_device rd;
mt19937 rng(rd());
template<typename T> inline T randint(T lo, T hi) { return uniform_int_distribution<T>(lo, hi)(rng); } // [lo,hi]
template<typename T> inline T randel(vector<T>& v) { return v[uniform_int_distribution<T>((int)0, v.size() - 1)(rng)]; } // [lo,hi]
#endif
const ll mod = 1e9 + 7;

struct Tree
{
    int n;
    vi tree;
    Tree(int n) : n(n), tree(n * 4, -inf) {}

    int merge(int a, int b)
    {
        return max(a, b);
    }

    void update(int x, int l, int r, int i, int v)
    {
        if (l == r) tree[x] = v;
        else
        {
            int mid = (l + r) / 2;
            if (i <= mid) update(x * 2, l, mid, i, v);
            else update(x * 2 + 1, mid + 1, r, i, v);
            tree[x] = merge(tree[x * 2], tree[x * 2 + 1]);
        }
    }

    void update(int i, int v) { update(1, 0, n - 1, i, v); }

    int query(int x, int l, int r, int ql, int qr)
    {
        if (l > qr || r < ql) return -inf;
        if (l >= ql && r <= qr) return tree[x];

        int mid = (l + r) / 2;
        return merge(query(x * 2, l, mid, ql, qr), query(x * 2 + 1, mid + 1, r, ql, qr));
    }

    int query(int ql, int qr) { return query(1, 0, n - 1, ql, qr); }
};

struct MergeTree
{
    int n;
    vector<Tree> treesboth;
    vector<Tree> trees;
    vvp2 sortedSegs;
    MergeTree(int n, vi& elements) : n(n), trees(n * 4, 0), treesboth(n*4, 0), sortedSegs(n*4)
    {
        vp2 els;
        rep(i, elements.size()) els.emplace_back(elements[i], i);
        build(1, 0, n - 1, els);
    }


    void build(int x, int l, int r, vp2 elements)
    {
        
        trees[x] = Tree(elements.size());
        treesboth[x] = Tree(elements.size());
        sortedSegs[x] = elements;
        sort(all(sortedSegs[x]));
        rep(i, elements.size())
        {
            trees[x].update(i, sortedSegs[x][i].second);
            treesboth[x].update(i, sortedSegs[x][i].second+sortedSegs[x][i].first);
        }

        if (l == r) return;
        int center = elements.size() / 2;
        vp2 left;
        vp2 right;
        rep(i, center + 1) left.push_back(elements[i]);
        repp(i, center + 1, elements.size()) right.push_back(elements[i]);
        int mid = (l + r) / 2;
        build(x * 2, l, mid, left);
        build(x * 2 + 1, mid + 1, r, right);
        
    }


    int query(int x, int l, int r, int ql, int qr, int att)
    {
        if (l > qr || r < ql) return -inf;
        if (l >= ql && r <= qr)
        {
            int ret = -inf;
            auto it = lower_bound(all(sortedSegs[x]), p2(att, inf));
            int i = it - sortedSegs[x].begin();
            ret = max(ret, trees[x].query(i, trees[x].n - 1));
            ret = max(ret, treesboth[x].query(0, i-1)-att);
            return ret;
        }

        int mid = (l + r) / 2;
        return max(query(x * 2, l, mid, ql, qr, att), query(x * 2 + 1, mid + 1, r, ql, qr, att));
    }

    int query(int ql, int qr, int v) { return query(1, 0, n - 1, ql, qr, v); }
};

int32_t main()
{
    fast();

    dread(int, n);
    vp2 team(n);
    rep(i, n) read(team[i].first), read(team[i].second);
    int totAtt = 0;
    int totDef = 0;
    rep(i, n) totAtt += team[i].first;
    rep(i, n) totDef += team[i].second;

    vi dp(totAtt+1,-inf);
    vi newdp(dp.size());
    dp[0] = 0;
    const int maxAtt = 400 * 400;
    bitset<maxAtt> reachable;
    reachable[0] = 1;

    rep(i, n)
    {
        
        per(j, dp.size())
        {
            newdp[j] = dp[j];
            if (j-team[i].first>=0) newdp[j] = max(newdp[j], dp[j - team[i].first]);
            newdp[j] = max(newdp[j], dp[j] + team[i].second);
        }
        reachable |= reachable << team[i].first;
        dp.swap(newdp);
        rep(i, newdp.size()) newdp[i] = -inf;
    }
    
    Tree tree(dp.size());
    rep(i, dp.size())
    {
        tree.update(i, dp[i]);
    }

    MergeTree mtree(dp.size(), dp);

    dread(int, q);
    int win = 0;
    int draw = 0;
    int lose = 0;
    while (q--)
    {
        dread2(int, a, d);

        int bestscore = -inf;
        
        bestscore = max(bestscore, -max(0LL, a - tree.query(0, d)));
        bestscore = max(bestscore, mtree.query(d, dp.size()-1, a)-d);

        if (bestscore < 0) lose++;
        else if (bestscore == 0) draw++;
        else win++;
    }

    cout << win << " " << draw << " " << lose << "\n";

    
    quit;
}
