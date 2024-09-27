// Approximation with normal distribution
// If combined with fft, can solve for all n,m,k with a pretty high error

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

long double normalCDF(long double dev, int k)
{
    return 0.5 * erfl(1 / (dev *sqrt(2))*k/2);
}

long double normalCDF(int n, int m, int k)
{
    long double dev = sqrtl(n * (m * m - 1) / 12);

    return normalCDF(dev, k)*2;
}

int32_t main()
{
    dread3(int, n, m, k);
    
    cout << setprecision(15) << normalCDF(n,m,k) << endl;
}
