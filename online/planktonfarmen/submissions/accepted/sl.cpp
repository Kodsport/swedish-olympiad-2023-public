#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define trav(a, x) for (auto& a : x)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int A, N;
	cin >> A >> N;
	vi len(N);
	rep(i,0,N) cin >> len[i];
	sort(all(len));
	reverse(all(len));
	int res = 0, j = N-1;
	rep(i,0,N) {
		ll x = len[i];
		while (j >= 0 && len[j] * x < A)
			j--;
		if (j <= i) break;
		res++;
		j--;
	}
	cout << res << endl;
}
