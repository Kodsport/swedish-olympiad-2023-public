#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define trav(a, x) for (auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vi maxDeg;
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

void rec(vi inds, bool big) {
	int n = sz(inds);
	if (n == 1) return;
	if (n == 2) {
		out.push_back({inds[0], inds[1]});
		return;
	}
	assert(n >= 3);
	int cur = inds[rng() % sz(inds)];

	vector<vi> recurseOn;
	while (sz(inds) > 1) {
		if (maxDeg[cur] == 1 && sz(inds) >= 5) {
			// cur is a leaf so there's little point in splitting it off
			recurseOn.push_back(inds);
			break;
		}
		int adj = cur == inds[0] ? inds[1] : inds[0];
		rep(i,0,sz(inds)) {
			int next = inds[i];
			if (next == cur || next == adj) continue;
			if (closer(next, adj, cur))
				adj = next;
		}
		out.push_back({cur, adj});
		maxDeg[cur]--;
		maxDeg[adj]--;

		vi left, right;
		trav(x, inds) {
			if (closer(cur, adj, x)) left.push_back(x);
			else right.push_back(x);
		}

		inds = move(left);
		recurseOn.push_back(move(right));
	}
	assert(!inds.empty());

	sort(all(recurseOn), [&](const vi& a, const vi& b) { return sz(a) > sz(b); });
	trav(comp, recurseOn) {
		rec(comp, big);
		big = false;
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N;
	cin >> N;
	maxDeg.assign(N, 3);
	vi inds;
	rep(i,0,N) inds.push_back(i);
	rec(inds, true);
	cout << "!" << endl;
	trav(pa, out) cout << pa.first+1 << ' ' << pa.second+1 << endl;
	cerr << "total " << totalQ << endl;
}
