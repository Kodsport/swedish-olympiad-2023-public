#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define trav(a, x) for (auto& a : x)
typedef vector<int> vi;

vector<vi> ed;
vi paths;
int rec(int at, int par) {
	int best = 0;
	trav(x, ed[at]) if (x != par) {
		int l = rec(x, at);
		paths.push_back(min(best, l));
		best = max(best, l);
	}
	return best + 1;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N;
	cin >> N;
	ed.resize(N);
	rep(i,0,N-1) {
		int a, b;
		cin >> a >> b;
		ed[a].push_back(b);
		ed[b].push_back(a);
	}
	int l = rec(0, -1);
	paths.push_back(l - 1);
	sort(all(paths), greater());
	rep(i,0,N) rep(j,0,paths[i]) cout << i+1 << ' ';
	cout << endl;
}
