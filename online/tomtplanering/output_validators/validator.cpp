// usage: ./a.out input_file correct_output output_dir < contestants_output
#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < int(to); ++i)
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define trav(a, x) for(auto& a : x)
typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> pii;

static string input_file, output_dir, answer_file;

void die(const string& msg) {
    cout << msg << endl;
    ofstream(output_dir + "/score.txt") << 0;
    exit(43);
}

void accept(long double score) {
    ofstream(output_dir + "/score.txt") << setprecision(2) << fixed << score;
    exit(42);
}

void judge_error(const string& msg) {
	cout << msg << endl;
	exit(1);
}

template <class F>
void assert_done(istream& is, F fail) {
    try {
        string dummy;
        is >> dummy;
		if (is) fail("extraneous data: " + dummy);
    } catch(...) {}
}



template <class F>
double score(istream& is, vector<pair<int,int>>& houses, F fail) {
	int n = sz(houses);
    vector<int> permutation;
    set<int> seen;
    int last = -1;
    ll ans = 0;
    for(int c1 = 0; c1 < n/2; c1++){
        int a;
        if(!(is >> a)){
            fail("Could not read answer.\n");
        }
        if(a <= 0 || a > n){
            fail("Answer out of bounds.\n");
        }
        if(seen.find(a) != seen.end()){
            fail("Visited the same house twice.\n");
        }
        seen.insert(a);
        a--;
        if(last != -1){
            ans += abs(houses[last].first - houses[a].first) + abs(houses[last].second - houses[a].second);
        }
        last = a;
    }

	assert_done(is, fail);
	return ans;
}

int main(int argc, char** argv) {
    if (argc < 4) exit(1);
    cin.sync_with_stdio(0);
    cin.tie(0);

    input_file = argv[1];
    answer_file = argv[2];
    output_dir = argv[3];

    ifstream fin(input_file);
    fin.exceptions(cin.failbit | cin.badbit | cin.eofbit);

    int T;
    fin >> T;

    int n;
    fin >> n;

	vector<pair<int,int>> houses;

	rep(i,0,n){
		int x,y;
		fin >> x >> y;
		houses.push_back({x, y});
	}

    assert_done(fin, die);
    fin.close();

	ifstream fans(answer_file);

    try {
		long double sc = score(cin, houses, die);
		long double bestsc = score(fans, houses, judge_error);
        //bestsc = double(n*m)/2.0;
		long double ratio = bestsc / sc;
		if (T == 0) accept(0);
		else accept(10.0 * ratio);
    } catch(...) {
        die("IO failure");
    }
}
