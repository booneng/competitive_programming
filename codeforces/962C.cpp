#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>

#define ll long long int

using namespace std;
map<string, ll> used;

int check(string s) {
  if (used.find(s) != used.end()) {
    return used[s];
  }
  if (s.length() == 0) return -1;
  ll n = stoll(s);
  ll root = sqrt((double)n) + 0.5;
  if (root * root == n) {
    used.insert(make_pair(s, 0));
    return 0;
  }
  int min = 10000;
  for (int i = 0; i < s.length(); i++) {
    if (i == 0 && s[1] == '0') continue;
    string temp = s;
    temp.erase(i, 1);
    int res = check(temp);
    if (res >= 0 && res < min) min = res;
  }
  int ans;
  if (min < 10000) {
    ans = min + 1;
  }
  else {
    ans = -1;
  }
  used.insert(make_pair(s, ans));
  return ans;
}


int main() {
  string s;
  cin >> s;
  cout << check(s);
}
