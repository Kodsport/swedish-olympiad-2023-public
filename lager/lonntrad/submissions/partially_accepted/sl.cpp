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

void splitBy(const vi& inds, int a, int b, bool big, int qs);

void rec(vi inds, bool big) {
	int n = sz(inds);
	if (n == 1) return;
	if (n == 2) {
		out.push_back({inds[0], inds[1]});
		return;
	}
	assert(n >= 3);
	int qs = 0;
	for (;;) {
		shuffle(all(inds), rng);
		// try to find cur as a node that's close to a large number of other nodes
		int cur = inds[0];
		rep(i,1,n) {
			int next = inds[i];
			int c = 0;
			rep(it,0,2) c += closer(next, cur, inds[rng() % n]), qs++;
			if (c) {
				rep(it,0,3) c += closer(next, cur, inds[rng() % n]), qs++;
				if (2 <= c && c <= 3) {
					splitBy(inds, cur, next, big, qs);
					return;
				}
				if (c >= 3) cur = next;
			}
		}
	}
}

void splitBy(const vi& inds, int a, int b, bool big, int qs) {
	vi A, B;
	trav(z, inds) {
		if (closer(a, b, z)) A.push_back(z);
		else B.push_back(z);
	}
	assert(!A.empty());
	assert(!B.empty());
	a = A[0], b = B[0];
	rep(i,1,sz(A)) {
		if (closer(A[i], a, b))
			a = A[i];
	}
	rep(i,1,sz(B)) {
		if (closer(B[i], b, a))
			b = B[i];
	}
	out.push_back({a, b});
	// if (big) cerr << sz(inds) << " needed " << qs << endl;
	bool abig = sz(A) > sz(B);
	rec(move(A), big && abig);
	rec(move(B), big && !abig);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N;
	cin >> N;
	vi inds;
	rep(i,0,N) inds.push_back(i);
	rec(inds, true);
	cout << "!" << endl;
	trav(pa, out) cout << pa.first+1 << ' ' << pa.second+1 << endl;
	cerr << "total " << totalQ << endl;
}
