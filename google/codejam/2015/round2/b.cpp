#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int n;
double v, x;
double r[105], c[105];

bool sort2(pair<double, double> n1, pair<double, double> n2) {
  return n1.first > n2.first;
}
bool sort1(pair<double, double> n1, pair<double, double> n2) {
  return n1.first < n2.first;
}
void solve(int t) {
  cin >> n >> v >> x;
  bool more = false;
  bool less = false;
  double flow = 0;
  vector<pair<double, double> > sources;
  for (int i = 0; i < n; i++) {
    cin >> r[i] >> c[i];
    flow += r[i];
    sources.push_back(make_pair(c[i], r[i]));
  }
  double time = v / flow;
  double temp = 0;
  for (int i = 0; i < n; i++) {
    double vi = r[i] * time;
    temp += vi * c[i];
  }
  temp /= v;
  bool high_temp = false;
  if (temp == x) {
    cout << "Case #" << t << ": " << time << endl;
    return;
  }
  sort(sources.begin(), sources.end());
  if (x < sources[0].first || x > sources[n - 1].first) {
    cout << "Case #" << t << ": IMPOSSIBLE" << endl;
    return;
  }
  if (x == sources[0].first || x == sources[n - 1].first) {
    double rate = 0.0;
    for (int i = 0; i < n; i++) {
      if (x == sources[i].first) rate += sources[i].second;
    }
    cout << "Case #" << t << ": " << v / rate << endl;
    return;
  }
  if (temp > x) {
    high_temp = true;
    sort(sources.begin(), sources.end(), sort1);
  }
  else if (temp < x) {
    sort(sources.begin(), sources.end(), sort2);
  }
  double left = 0;
  double right = flow;
  double target = v * x;
  for (int i = 0; i < 500; i++) {
    double mid = 0.5 * (left + right);
    double cur = 0;
    double rem = mid;
    for (int i = 0; i < n; i++) {
      double tmp = min(sources[i].second, rem);
      rem -= tmp;
      cur += tmp * sources[i].first;
    }
    if ((high_temp && cur < x * mid) || (!high_temp && cur > x * mid)) {
      left = mid;
    }
    else {
      right = mid;
    }
  }
  cout << "Case #" << t << ": " << v / right << endl;
}


int main() {
  cout << fixed;
  cout << setprecision(15);
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    solve(i);
  }
}
