#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long int

using namespace std;

class Pair {
public:
  ll time;
  double prob;

  Pair(ll t, double p) : time(t), prob(p) {}
  
  bool operator<(const Pair& p) const {
    if (time != p.time) return time < p.time;
    return prob > p.prob;
  }
  

};
int main() {
  int m, n;
  ll k;
  cin >> m >> n >> k;
  int from[m];
  int to[m];
  ll start[m];
  ll stop[m];
  double prob[m];
  vector< pair<ll, int> > time_ord;
  for (int i = 0; i < m; i++) {
    cin >> from[i] >> to[i] >> start[i] >> stop[i] >> prob[i];
    time_ord.push_back(make_pair(-start[i], i));
  }
  sort(time_ord.begin(), time_ord.end());
  ll max_time = time_ord[0].first;
  vector<Pair> dp[n];
  dp[1].push_back(Pair(1e18 + 1, 1.0));
  
  for (int i = 0; i < m; i++) {
    ll time = -time_ord[i].first;
    int idx = time_ord[i].second;
    ll st = stop[idx];
    int dest = to[idx];
    int source = from[idx];
    double p = prob[idx];
    double next_prob = 0.0;
    if (!dp[source].empty() && dp[source][0].time > time) {
      next_prob = dp[source][0].prob;
    }
    auto it = upper_bound(dp[dest].begin(), dp[dest].end(), Pair(st, 1));
    if (it != dp[dest].end()) {
      next_prob = max(p * it->prob + (1 - p) * next_prob, next_prob);
    }
    if (next_prob > 0) {
      if (!dp[source].empty() && dp[source][0].time == time) {
	dp[source][0].prob = max(next_prob, dp[source][0].prob);
      }
      else {
	dp[source].insert(dp[source].begin(), Pair(time, next_prob));
      }
    }
  }
  if (!dp[0].empty()) cout << dp[0][0].prob;
  else cout << 0.0;
}
