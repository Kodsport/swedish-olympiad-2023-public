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


int main()
{
	dread3(int, r, c, n);

	vp2 events(n);
	rep(i, n) read(events[i].first), read(events[i].second);

	vp2 dirs = { {0,1},{0,-1},{1,0},{-1,0} };


	map<p2, int> added;
	rep(i, n)
	{
		p2 ev = events[i];
		if ((r==3)||setcontains(added, ev + p2(1, 0))|| setcontains(added, ev + p2(-1, 0)))
		{
			cout << i + 1 << endl;
			return 0;
		}
		added[ev] = i;
	}

	cout << "nej";
	return 0;
}
