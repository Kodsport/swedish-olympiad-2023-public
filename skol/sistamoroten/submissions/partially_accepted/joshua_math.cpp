// Gets around 80 if you use gcc

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int inf = int(2e9);
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> p2;

template <typename T> inline void read(T& a) { cin >> a; }
template <typename T> inline void read(T& a, T& b) { cin >> a >> b; }
template <typename T> inline void read(T& a, T& b, T& c) { cin >> a >> b >> c; }
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
#define rall(a) a.rbegin(),a.rend()
#define setcontains(set, x) (set.find(x) != set.end())
auto Start = chrono::high_resolution_clock::now();
#define elapsedmillis() (chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - Start).count())

vector<long double> cache;
inline long double fact(int k)
{
    if (cache[k] != -1) return cache[k];
    return cache[k] = lgammal(k + 1);
}

long double choose(int n, int k)
{
    return fact(n) - fact(k) - fact(n - k);
}

int32_t main()
{

    int n, m, k;
    cin >> n >> m >> k;

    cache.resize(n * m, -1);

    long double tot = n * log(m);

    vector<long double> v;
    repp(t, n, n * m + 1)
    {
        long double ans = 0;
        rep(i, (t - n) / m + 1)
        {
            long double a = choose(n, i) + choose(t - i * m - 1, n - 1) - tot;
            ans += expl(a) * ((i % 2 == 0) ? 1 : -1);
        }
        v.push_back(ans);
    }

    sort(rall(v));

    double ans = 0;
    rep(i, k) ans += v[i];
    cout << setprecision(15) << ans << endl;

}
