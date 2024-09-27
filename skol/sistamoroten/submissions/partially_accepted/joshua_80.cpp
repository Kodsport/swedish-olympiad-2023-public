// Should get 80
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


int32_t main()
{

    dread3(int, n, m, k);
    vi items;
    repp(j, 1, m + 1) items.push_back(j);


    vector<double> dp(m * n + 1);
    dp[0] = 1;
    vector<double> newdp(dp.size());
    rep(j, n)
    {
        rep(i, dp.size())
        {
            repe(item, items)
            {
                if (i - item >= 0)
                {
                    newdp[i] += dp[i - item];
                }
            }
            newdp[i] /= items.size();
        }
        dp = newdp;
        newdp = vector<double>(dp.size());
    }


    sort(rall(dp));
    double ans = 0;
    rep(i, k) ans += dp[i];
    cout << setprecision(15) << ans << endl;
}