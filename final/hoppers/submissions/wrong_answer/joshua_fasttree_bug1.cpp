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

#define PBDS 0
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
ifstream filein("E:\\downloads\\test_data\\test_data\\005-case05.in");
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

#define UNVISITED 0
#define VISITING 1
#define CYCLE 2
#define TREE 3
vvi color;
vvi inputIndex;
vvi cyclepar;
vvi cyclepos;
vector<string> board;
vp2 ans;
map<char, p2> cToDir = { {'>',{0,1}},{'v',{1,0}},{'<',{0,-1}},{'^',{-1,0}} };
p2 moveonce(p2 p)
{
    return p + cToDir[board[p.first][p.second]];
}

p2 dfs(p2 u)
{
    if (color[u.first][u.second] > VISITING) return { -1,-1 };
    if (color[u.first][u.second] == VISITING)
    {
        color[u.first][u.second] = TREE; // Will color cycle later
        return u;
    }
    color[u.first][u.second] = VISITING;

    p2 ret = dfs(moveonce(u));

    color[u.first][u.second] = TREE;
    return ret;
}

int colorcycle(p2 u, int par)
{
    if (color[u.first][u.second] == CYCLE) return -1;
    color[u.first][u.second] = CYCLE;
    cyclepar[u.first][u.second] = par;
    return cyclepos[u.first][u.second] = colorcycle(moveonce(u), par) + 1;
}

int finddepth(p2 u, vvvp2& redges)
{
    int ret = 0;
    repe(e, redges[u.first][u.second]) ret = max(ret, 1 + finddepth(e, redges));
    return ret;
}

// map with increment key operation
struct incmap : unordered_map<int, int>
{
    int inc = 0;
    vi* killist = new vi();


    void swap(incmap& other)
    {
        unordered_map<int, int>::swap(other);
        vi* temp;
        temp = other.killist;
        other.killist = this->killist;
        killist = temp;

        int tempi;
        tempi = other.inc;
        other.inc = this->inc;
        inc = tempi;
    }
};

incmap findcollisions(p2 u, vvvp2& redges)
{
    incmap ancestors;
    if (inputIndex[u.first][u.second] != -1) ancestors.insert(p2(0, inputIndex[u.first][u.second]));

    repe(e, redges[u.first][u.second])
    {
        incmap r = findcollisions(e, redges);
        r.inc++;
        if (r.size() > ancestors.size()) ancestors.swap(r);
        repe(k, *r.killist)
        {
            ancestors.killist->push_back(k + r.inc);
        }
        repe(e, r)
        {
            int t = e.first + r.inc;
            if (setcontains(ancestors, t - ancestors.inc))
            {
                ans[e.second] = u;

                ancestors.killist->push_back(t - ancestors.inc * 2);
            }
            else
            {
                ancestors[t - ancestors.inc] = e.second;
            }
        }
    }

    repe(a, *ancestors.killist)
    {
        int t = a + ancestors.inc;
        if (setcontains(ancestors, t)) ans[ancestors[t]] = u;
        ancestors.erase(t);

        //ancestors.erase(k);
    }


#if _LOCAL // Needed so ancestors doesnt get optimized away during debugging
    incmap c;
    c.inc = ancestors.inc;
    repe(e, ancestors) c.insert(e);
    return c;
#else
    return ancestors;
#endif
}

string solvesmart(int r, int c, int n, vector<string>& boardin, vp2& starting)
{
    board.resize(0);
    board.resize(r);
    inputIndex.resize(0);
    inputIndex.resize(r, vi(c, -1));
    cyclepar.resize(0);
    cyclepar.resize(r, vi(c, -1));
    cyclepos.resize(0);
    cyclepos.resize(r, vi(c, -1));
    rep(i, r)
    {
        board[i] = boardin[i];
    }

    ans.resize(0);
    ans.resize(n, { inf,inf });
    map<p2, vi> startitems;
    rep(i, n)
    {
        int x, y;
        tie(x, y) = starting[i];
        startitems[p2(x, y)].emplace_back(i);
    }

    // Find all items that are already colliding
    vp3 positions;
    repe(s, startitems)
    {
        if (s.second.size() > 1)
        {
            repe(it, s.second) ans[it] = s.first;
        }
        else
        {
            inputIndex[s.first.first][s.first.second] = s.second.back();
            positions.emplace_back(s.first.first, s.first.second, s.second.back());
        }
    }
    n = positions.size();

    color.resize(0);
    color.resize(r, vi(c));

    int cycleind = 0;
    vp2 cycleheads;
    vi cyclelengths;
    rep(i, r) rep(j, c)
    {
        p2 p = { i,j };

        if (color[p.first][p.second] == UNVISITED)
        {
            p2 cyclehead = dfs(p);
            if (cyclehead.first != -1)
            {
                cyclelengths.push_back(colorcycle(cyclehead, cycleind++) + 1);
                cycleheads.push_back(cyclehead);
            }
        }
    }

    // Display classification of graph, debug
#if _LOCAL && false
    auto getrep = [](int u)
    {
        switch (u)
        {
        case UNVISITED:
            return 'U';
        case VISITING:
            return 'V';
        case TREE:
            return 'T';
        case CYCLE:
            return 'C';

        }
    };
    rep(i, r)
    {
        rep(j, c)
        {
            cout << getrep(color[i][j]);
        }
        cout << "\n";
    }
#endif

    vvvp2 redges(r, vvp2(c));
    vp2 roots;
    rep(i, r) rep(j, c)
    {
        p2 p = { i,j };
        p2 next = moveonce(p);
        if (color[i][j] == TREE && color[next.first][next.second] == CYCLE)
        {
            roots.push_back(p);
        }
        redges[next.first][next.second].push_back(p);
    }

    set<p4> enteringcycle;
    repe(root, roots)
    {
        incmap cycleenter = findcollisions(root, redges);
        p2 r = moveonce(root);
        int ind = cyclepar[r.first][r.second];

        repe(c, cycleenter) enteringcycle.emplace(c.first + cycleenter.inc + 1, c.second, r.first, r.second);
    }

    vector<unordered_map<int, int>> cycles(cycleind);
    vi cycletime(cycleind, 0);
    vector<set<p2>> rems(cycleind);

    rep(i, r) rep(j, c)
    {
        if (cyclepar[i][j] != -1 && inputIndex[i][j] != -1)
        {
            cycles[cyclepar[i][j]].emplace(cyclepos[i][j], inputIndex[i][j]);
        }
    }


    repe(e, enteringcycle)
    {
        int time, node, x, y;
        tie(time, node, x, y) = e;

        p2 p = { x,y };
        int cyclehead = cyclepar[x][y];
        int& t = cycletime[cyclehead];
        unordered_map<int, int>& incycle = cycles[cyclehead];
        int len = cyclelengths[cyclehead];

        set<p2>& remthist = rems[cyclehead];
        int dt = time - t;
        if (time != t)
        {
            remthist = set<p2>();

            // move them forward slow
            unordered_map<int, int> newnodes;
            repe(c, incycle) newnodes.emplace(((c.first - dt) % len + len) % len, c.second);
            incycle = newnodes;
        }

        int pos = cyclepos[x][y];
        if (setcontains(remthist, p))
        {
            ans[node] = p;
        }
        else
        {
            if (setcontains(incycle, pos))
            {
                ans[incycle[pos]] = p;
                ans[node] = p;
                incycle.erase(pos);
                remthist.insert(p);
            }
            else
            {
                incycle.emplace(pos, node);
            }
        }


        t = time;
    }

    stringstream ret;
    rep(i, ans.size())
    {
        if (ans[i].first == inf)
        {
            ret << "cycle\n";
        }
        else
        {
            ret << ans[i].first << " " << ans[i].second << "\n";
        }
    }
    return ret.str();
}

string solvestupid(int r, int c, int n, const vector<string>& board, vp2& start)
{

    vp2 ans(n, { inf,inf });
    map<p2, vi> startitems;
    rep(i, n)
    {
        int x, y;
        tie(x, y) = start[i];
        startitems[p2(x, y)].emplace_back(i);
    }

    vp3 positions;
    repe(s, startitems)
    {
        if (s.second.size() > 1)
        {
            repe(it, s.second) ans[it] = s.first;
        }
        else
        {
            positions.emplace_back(s.first.first, s.first.second, s.second.back());
        }
    }

    map<char, p2> cToDir = { {'>',{0,1}},{'v',{1,0}},{'<',{0,-1}},{'^',{-1,0}} };
    rep(it, r * c + 100)
    {
        map<p2, vi> newpositions;

        rep(i, positions.size())
        {
            int x, y, ind;
            tie(x, y, ind) = positions[i];
            p2 p = { x,y };
            p2 np = p + cToDir[board[p.first][p.second]];

            newpositions[np].push_back(ind);
        }

        positions.resize(0);
        repe(s, newpositions)
        {
            if (s.second.size() > 1)
            {
                repe(it, s.second) ans[it] = s.first;
            }
            else
            {
                p3 np = { s.first.first,s.first.second,s.second.back() };
                positions.emplace_back(np);
            }
        }
    }

    stringstream ret;
    rep(i, n)
    {
        if (ans[i].first == inf)
        {
            ret << "cycle\n";
        }
        else
        {
            ret << "collision at " << ans[i].first << ", " << ans[i].second << "\n";
        }
    }
    return ret.str();
}

int32_t main()
{
    fast();

#if 1
    dread3(int, r, c, n);
    vector<string> board(r);
    rep(i, r) read(board[i]);
    vp2 queries(n);
    rep(i, n) read(queries[i].first), read(queries[i].second);
    cout << solvesmart(r, c, n, board, queries);
    //cout << "\n\n\n";
    //cout << solvestupid(r, c, n, board, queries);
#else

    rep(t, 1000000)
    {
        int r = randint(2, 10);
        int c = randint(2, 10);
        int n = randint(2, 10);
        vector<string> board(r, string(c, '-'));

        rep(i, r) rep(j, c)
        {
            vector<char> choices;
            if (i != 0) choices.push_back('^');
            if (i != r - 1) choices.push_back('v');
            if (j != 0) choices.push_back('<');
            if (j != c - 1) choices.push_back('>');
            board[i][j] = choices[randint((int)0, (int)choices.size() - 1)];
        }
        vp2 queries(n);
        rep(i, n) queries[i].first = randint(0LL, r - 1), queries[i].second = randint(0LL, c - 1);

        string anssmart = solvesmart(r, c, n, board, queries);
        string ansstupid = solvestupid(r, c, n, board, queries);

        if (anssmart != ansstupid)
        {
            cout << r << " " << c << " " << n << "\n";
            rep(i, r)
            {
                rep(j, c) cout << board[i][j];
                cout << "\n";
            }
            repe(q, queries)
            {
                cout << q.first << " " << q.second << "\n";
            }
            deb;
        }
    }
#endif


    quit;
}
