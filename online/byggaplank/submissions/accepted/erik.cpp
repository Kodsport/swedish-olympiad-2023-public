#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>

using namespace std;

typedef long long int ll;
typedef vector<ll> vi;
typedef set<ll> si;
typedef pair<ll, ll> pii;
typedef vector<pii> vpii;

int main() {
    ll n, k;
    cin >> n >> k;

    k = min<ll>(k, n - 1);

    vi h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    vpii h_sort(n);
    for (int i = 0; i < n; i++) {
        h_sort[i] = make_pair(h[i], i);
    }

    sort(h_sort.begin(), h_sort.end());

    si low;

    ll global_best = 0;

    low.insert(-1);
    low.insert(n);

    for (int i = 0; i < n; i++) {
        vi left(k + 1);
        vi right(k + 1);
        fill_n(left.begin(), k + 1, 0);
        fill_n(right.begin(), k + 1, n - 1);

        low.insert(h_sort[i].second);
        si::iterator itr = low.find(h_sort[i].second);

        itr++;
        for (int j = 0; (j <= k) && (itr != low.end()); j++) {
            right[j] = *itr - 1;
            itr++;
        }

        itr = low.find(h_sort[i].second);
        for (int j = 0; (j <= k) && (itr != low.begin()); j++) {
            itr--;
            left[j] = *itr + 1;
        }


        for (int j = 0; j <= k; j++) {
            // compare left[j] and right[k - j]
            global_best = max<ll>(global_best, h_sort[i].first * (right[k - j] - left[j] + 1));
        }
    }

    cout << global_best << endl;

    return 0;
}
