// Gets 20-60 depending on float tolerance
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

int32_t main()
{

    dread3(int, n, m, k);

    vi frequency(n * m + 1);

    mt19937 rng(1234);
    uniform_int_distribution<int> dist(1, m);

    int i = 0;
    while (true)
    {
        int roll = 0;
        rep(i, n) roll += dist(rng);
        frequency[roll]++;

        i++;
        if (i % 10000 == 0 && elapsedmillis() > 980) break;
    }

    sort(rall(frequency));
    double ans = 0;
    rep(i, k) ans += frequency[i];
    ans /= accumulate(all(frequency), 0);
    cout << setprecision(15) << ans << endl;
}