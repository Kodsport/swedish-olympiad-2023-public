#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define trav(a, x) for (auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<pii> out;
mt19937 rng{123};
int totalQ;

bool closer(int a, int b, int c) {
	assert(a != b);
	if (c == a) return true;
	if (c == b) return false;
	cout << "? " << a+1 << ' ' << b+1 << ' ' << c+1 << endl;
	char ch;
	cin >> ch;
	totalQ++;
	return (ch == 'A');
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N;
	cin >> N;
	vi inds;
	rep(i,1,N) inds.push_back(i);
	sort(all(inds), [&](int a, int b) -> bool {
		if (a == b) return false;
		return closer(a, b, 0);
	});
	for (int i = sz(inds)-1; i >= 0; i--) {
		int x = inds[i];
		int best = 0;
		rep(j,0,i) {
			if (closer(inds[j], best, x))
				best = inds[j];
		}
		out.push_back({best, x});
	}
	cout << "!" << endl;
	trav(pa, out) cout << pa.first+1 << ' ' << pa.second+1 << endl;
	cerr << "total " << totalQ << endl;
}
