#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
  int n;
  string s;
  cin >> n;
  cin >> s;
  map<string, int> two_gram_counts;
  int max_count = 0;
  string ans;
  for (int i = 0; i < n - 1; i++) {
    string tmp = s.substr(i, 2);
    two_gram_counts[tmp]++;
    if (two_gram_counts[tmp] > max_count) {
      ans = tmp;
      max_count = two_gram_counts[tmp];
    }
  }
  cout << ans;
}
