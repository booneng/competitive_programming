#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int k, l, s;
int combinations;
int counts[26];
string target;
int max_occurrences;

int max_overlap(string s) {
  for (int i = 1; i < s.length(); i++) {
    if (s.substr(i).compare(s.substr(0, s.length() - i)) == 0) {
      return s.length() - i;
    }
  }
  return 0;
}

double probability(string target) {
  double p = 1;
  for (int i = 0; i < target.length(); i++) {
    p *= (double)counts[target[i] - 'A'] / k;
  }
  return p;
}
int main() {
  int T;
  cin >> T;
  cout << fixed;
  for (int t = 1; t <= T; t++) {
    cin >> k >> l >> s;
    for (int i = 0; i < 26; i++) counts[i] = 0;
    for (int i = 0; i < k; i++) {
      char temp;
      cin >> temp;
      counts[temp - 'A']++;
    }
    cin >> target;
    double res = 0;
    double p = probability(target);
    if (p > 0) {
      int o = max_overlap(target);
      double max_copies = 1.0 + (s - l) / (l - o);
      double min_copies = p * (s - l + 1);
      res = max_copies - min_copies;
    }
    cout << "Case #" << t << ": " << res << endl;
  }

}
