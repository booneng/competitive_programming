#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>

#define ll long long int

using namespace std;

vector<pair<double, double> > merge(vector<pair<double, double> > v1, vector<pair<double, double> > v2) {
  vector<pair<double, double> > merged;
  int i = 0, j = 0;
  while (i < v1.size() || j < v2.size()) {
    double left, right;
    if (j == v2.size() || (i < v1.size() && v1[i].first < v2[j].first)) {
      left = v1[i].first;
      right = v1[i].second;
      i++;
    }
    else {
      left = v2[j].first;
      right = v2[j].second;
      j++;
    }
    if (merged.size() == 0 || merged[merged.size() - 1].second < left) {
      merged.push_back(make_pair(left, right));
    }
    else {
      merged[merged.size() - 1].second = max(merged[merged.size() - 1].second, right);
    }
  }
  return merged;
}

int main() {
  int t;
  cin >> t;
  cout << fixed;
  for (int i = 1; i <= t; i++) {
    int n, p;
    cin >> n >> p;
    int cookies[105][2];
    double perimeter = 0;
    for (int j = 0; j < n; j++) {
      cin >> cookies[j][0] >> cookies[j][1];
      perimeter += 2 * cookies[j][0] + 2 * cookies[j][1];
    }
    vector<pair<double, double> > extras;
    for (int j = 0; j < n; j++) {
      double small = 2 * min(cookies[j][0], cookies[j][1]);
      double large = 2 * sqrt((double)cookies[j][0] * cookies[j][0] + cookies[j][1] * cookies[j][1]);
      extras.push_back(make_pair(small, large));
    }
    double missing = p - perimeter;
    vector<pair<double, double> > intervals;
    intervals.push_back(make_pair(0, 0));
    for (int j = 0; j < extras.size(); j++) {
      vector<pair<double, double> > next;
      double small = extras[j].first;
      double large = extras[j].second;
      vector<pair<double, double> >::iterator it;
      for (it = intervals.begin(); it != intervals.end(); it++) {
	if (it->first + small > missing) break;
	next.push_back(make_pair(it->first + small, it->second + large));
      }
      intervals = merge(intervals, next);
    }
    double left = intervals[intervals.size() - 1].first;
    double right = intervals[intervals.size() - 1].second;
    if (missing <= right) perimeter = p;
    else if (missing > right) perimeter += right;
    
    cout << "Case #" << i << ": " << perimeter << endl;
  }
}
