// Should be about O(rc+nlogn)
#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;

const int inf = int(2e9);
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> p2;
typedef vector<p2> vp2;
typedef vector<vp2> vvp2;
typedef vector<vvp2> vvvp2;
typedef tuple<int, int, int> p3;
typedef vector<p3> vp3;
typedef tuple<int, int, int, int> p4;

template <typename T> inline void read(T& a) { cin >> a; }
template <typename T> inline void read(T& a, T& b) { cin >> a >> b; }
template <typename T> inline void read(T& a, T& b, T& c) { cin >> a >> b >> c; }
#define quit cout << endl; _Exit(0);
#define dread(type, a) type a; read(a)
#define dread2(type, a, b) dread(type, a); dread(type, b)
#define dread3(type, a, b, c) dread2(type, a, b); dread(type, c)
#define readvector(type, name, size) vector<type> name(size); rep(i,size) {dread(type,temp); name[i]=temp;}


#define rep(i, high) for (int i = 0; i < high; i++)
#define repp(i, low, high) for (int i = low; i < high; i++)
#define repe(i, container) for (auto& i : container)
#define per(i, high) for (int i = high-1; i >= 0; i--)
#define perr(i, low, high) for (int i = high-1; i >= low; i--)

#define all(a) a.begin(),a.end()
#define setcontains(set, x) (set.find(x) != set.end())
#define sz(container) ((int)container.size())
#define mp(a,b) (make_pair(a,b))

template <typename T, typename U> inline void operator+=(pair<T, U>& l, const pair<T, U>& r) { l = { l.first + r.first,l.second + r.second }; }
template <typename T, typename U> inline pair<T, U> operator+(const pair<T, U> l, const pair<T, U> r) { return { l.first + r.first, l.second + r.second }; }


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

inline int hashpos(p2 u) { return u.first * (board[0].size()+10) + u.second; }
typedef unordered_map<int, int> umap;
// Very painful to implement properly
umap findcollisions(p2 u, int depth, vvvp2& redges)
{
    umap ancestors;
    if (inputIndex[u.first][u.second] != -1) ancestors.insert(p2(depth, inputIndex[u.first][u.second]));

    repe(e, redges[u.first][u.second])
    {
        umap r = findcollisions(e, depth + 1, redges);

        if (r.size() > ancestors.size()) ancestors.swap(r);
        repe(e, r)
        {
            if (e.second >= inf)
            {
                if (e.second==inf+hashpos(u) && setcontains(ancestors,e.first) && ancestors[e.first] < inf)
                {
                    ans[ancestors[e.first]] = u;
                    ancestors[e.first] = inf + hashpos(u);
                }
                continue;
            }
            int t = e.first;

            if (setcontains(ancestors, t) && (ancestors[t] == inf + hashpos(u) || ancestors[t] < inf))
            {
                ans[e.second] = u;
                if (ancestors[t] < inf) ans[ancestors[t]] = u;
                ancestors[t] = inf + hashpos(u);
            }
            else
            {
                ancestors[t] = e.second;
            }
        }
    }


    return ancestors;
}

void solvesmart(int r, int c, int n, vector<string>& boardin, vp2& starting)
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
        umap cycleenter = findcollisions(root, 1, redges);
        p2 r = moveonce(root);
        repe(c, cycleenter) if (c.second < inf) enteringcycle.emplace(c.first, c.second, r.first, r.second);
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
        int dt = time - 0;

        if (time != t)
        {
            remthist = set<p2>();
        }

        int pos = (cyclepos[x][y] + dt) % len;
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

    rep(i, sz(ans))
    {
        if (ans[i].first == inf)
        {
            cout << "cycle\n";
        }
        else
        {
            cout << ans[i].first << " " << ans[i].second << "\n";
        }
    }
}

int main()
{

    dread3(int, r, c, n);
    vector<string> board(r);
    rep(i, r) read(board[i]);
    vp2 queries(n);
    rep(i, n) read(queries[i].first), read(queries[i].second);
    solvesmart(r, c, n, board, queries);

    return 0;
}
