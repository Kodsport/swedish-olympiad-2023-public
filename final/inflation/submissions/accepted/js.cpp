#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const bool dbg = false;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

  double I;
  cin >> I;

  int N = 30;

  if (dbg) {
    cin >> N;
  }
  vector<double> A(N);
  rep(i,0,N) cin >> A[i];

  double mx = 0;
  rep(i,0,N + 1) {
    double ni = I;
    rep(j,0,i) {
      ni += A[j];
    }
    rep(j,i,N) {
      ni += A[j] / 100 * ni;
    }
    if (ni > mx) mx = ni;
  }
  cout << setprecision(10) << fixed << mx << endl;
}
