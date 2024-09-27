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

vector<vi> ch;
vi sizes;
int rec(int at, int totSize, pii& bestSplit) {
	int size = 1;
	trav(x, ch[at]) {
		size += rec(x, totSize, bestSplit);
	}
	sizes[at] = size;
	bestSplit = max(bestSplit, {min(size, totSize - size), at});
	return size;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N;
	cin >> N;
	ch.resize(N);
	sizes.resize(N);
	vi pars(N);
	int root = (int)(rng() % N);
	vi inds;
	rep(i,0,N) inds.push_back(i);
	stable_sort(all(inds), [&](int a, int b) {
		return closer(a, b, root);
	});
	rep(it,1,N) {
		int x = inds[it];
		int inSubtree = root;
		int subtreeSize = it;
		vector<pii> toRestore;
		while (subtreeSize > 1) {
			pii bestSplit{-1, -1};
			int sz = rec(inSubtree, subtreeSize, bestSplit);
			assert(sz == subtreeSize);
			int y = bestSplit.second;
			if (closer(y, pars[y], x)) {
				inSubtree = y;
				subtreeSize = sizes[y];
			} else {
				int z = pars[y];
				auto it = find(all(ch[z]), y);
				assert(it != ch[z].end());
				ch[z].erase(it);
				toRestore.push_back({z, y});
				subtreeSize -= sizes[y];
			}
		}

		int par = inSubtree;
		ch[par].push_back(x);
		pars[x] = par;
		out.push_back({par, x});
		trav(pa, toRestore) ch[pa.first].push_back(pa.second);
	}

	cout << "!" << endl;
	trav(pa, out) cout << pa.first+1 << ' ' << pa.second+1 << endl;
	cerr << "total " << totalQ << endl;
}
