#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <limits.h>
#include <math.h>
#include <chrono>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

#define rep(i,a,b) for (int i = a; i < b; i++)
#define pb push_back

typedef long long ll;
typedef vector<double> vd;
typedef vector<vector<double>> vvd;

int rows, cols, region_count;
vvd score, original_score;

vector<vector<int>> in_region;
vector<set<pair<int,int>>> region;
vector<double> region_sum;
vector<set<pair<double, pair<int,int>>>> periferal;

vector<pair<int,int>> nei(int r, int c) {
  vector<pair<int,int>> ret;
  if (r > 0) ret.pb({r - 1, c});
  if (r < rows - 1) ret.pb({r + 1, c});
  if (c > 0) ret.pb({r, c - 1});
  if (c < cols - 1) ret.pb({r, c + 1});
  return ret;
}

void add_to_region(int i, int r, int c) {
  region[i].insert({r, c});
  in_region[r][c] = i;
  region_sum[i] += score[r][c];
}

void remove_from_region(int i, int r, int c) {
  region[i].erase({r, c});
  in_region[r][c] = -1;
  region_sum[i] -= score[r][c];
}

void output_regions() {
  rep(r,0,rows) {
    rep(c,0,cols) {
      if(in_region[r][c] != -1) cout << in_region[r][c] << " ";
      else cout << "*";
    }
    cout << endl;
  }
}

pair<int,int> get_best_tile(int index) {
  double current_region_sum = region_sum[index];
  double desired_score = -current_region_sum;

  if (periferal[index].size() == 0) return {-1, -1};

  auto iter2 = periferal[index].lower_bound({desired_score, {0, 0}});
  auto iter1 = iter2;
  if (iter2 == periferal[index].begin()) iter1 = iter2;
  else {
    iter1 = iter2;
    iter1--;
  }

  if (iter2 == periferal[index].end()) iter2 = iter1;

  auto [score1, pair1] = *iter1;
  auto [score2, pair2] = *iter2;

  auto best = (abs(score1 - desired_score) < abs(score2 - desired_score)) ? iter1 : iter2;
  auto [s, p] = *best;
  auto [r, c] = p;
  if (in_region[r][c] == -1) return {r, c};
  periferal[index].erase(best);
  return get_best_tile(index);
}

void output_region_sum() {
  rep(i,0,region_count) {
    cout << "region sum " << i << ": " << region_sum[i] << endl;
  }
}

void output_averages() {
  double sum_squares = 0.0;
  double average = 0.0;
  rep(r,0,rows) rep(c,0,cols) average += score[r][c];
  average /= (double)(rows*cols);

  rep(index, 0, region_count) {
    double region_average = 0.0;
    for (auto [r, c] : region[index]) region_average += score[r][c];
    region_average /= (double)(region[index].size());
    /* cout << "size: " << (double) (region[index].size()) << endl; */
    sum_squares += (region_average-average) * (region_average-average);
/*     cout << "Average for region " << index << ": " << region_average << endl;
 */  }
  cout << "Score: " << sum_squares << endl;
}

int dfs(int r, int c, vector<vector<bool>> & v) {
  v[r][c] = true;
  int index = in_region[r][c];
  int ans = 1;
  for (auto [R, C] : nei(r, c)) {
    if (v[R][C]) continue;
    if (in_region[R][C] != index) continue;
    ans += dfs(R, C, v);
  }
  return ans;
}

bool can_change(int r, int c) {
  int index = in_region[r][c];
  int startr = -1, startc = -1;
  for (auto [R, C] : nei(r, c)) {
    if (in_region[R][C] == index) {
      startr = R;
      startc = C;
    }
  }
  if (startr == -1) return false;

  vector<vector<bool>> v(rows, vector<bool>(cols, false));
  v[r][c] = true;
  return (dfs(startr, startc, v) == region[index].size() - 1);

}

bool should_do(double score_change, double heat) {
  // score_change > 0
  double random = (double)rand() / (double)RAND_MAX;

  return exp(-score_change/heat) > random; 
}

void bad_hill_climb(double heat) {
  rep(r,0,rows) rep(c,0,cols) {
    for (auto [R, C] : nei(r, c)) {
      // test if good to change region for (r, c)
      int a = in_region[r][c], b = in_region[R][C];
      if (a == b) continue;
      double score_change = abs(region_sum[a] - score[r][c]) + abs(region_sum[b] + score[r][c]) - abs(region_sum[a]) + abs(region_sum[b]);
      if (score_change < 0 || (!should_do(score_change, heat))) continue;
      if (!can_change(r, c)) continue;
      remove_from_region(a, r, c);
      add_to_region(b, r, c);
    }
  }
}

int main() {
  int t; cin >> t;
  srand(t);
  double average = .0;
  cin >> rows >> cols >> region_count;
  score.resize(rows);
  original_score.resize(rows);
  rep(r,0,rows) score[r].resize(cols);
  rep(r,0,rows) rep(c,0,cols) {
    cin >> score[r][c];
    average += score[r][c];
  }
  average /= (double)(rows*cols);

  in_region.resize(rows); rep(r,0,rows) in_region[r].assign(cols, -1);
  region.resize(region_count);
  region_sum.assign(region_count, 0.);

  vector<queue<pair<int,int>>> q(region_count);
  int added = 0;
  for (int i = 0; i < region_count; i++) {
    int r = 0, c = 0;
    while (in_region[r][c] != -1) {
      r = rand() % rows;
      c = rand() % cols;
    }
    add_to_region(i, r, c);
    added++;
    q[i].push({r, c});
  }


  while (added < rows * cols) {
    rep(i,0,region_count) {
        if (q[i].empty()) continue;
        auto [r, c] = q[i].front(); q[i].pop();
        for (auto [R, C] : nei(r, c)) {
            if (in_region[R][C] == -1) {
                add_to_region(i, R, C);
                added++;
                q[i].push({R, C});
            }
        }
    }
  }


  
  
  output_regions();
  //output_averages();
}
