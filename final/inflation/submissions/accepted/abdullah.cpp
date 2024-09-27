#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

  double I;
  cin >> I;
  ll n=30;
  vector<double> v(n);
  double ans = I;
  for(int i=0; i<n; i++){
    double a;
    cin>>a;
    ans=max(ans+a,ans*(1+a/(double)100));
  }
  cout << setprecision(10) << fixed << ans << endl;
}
