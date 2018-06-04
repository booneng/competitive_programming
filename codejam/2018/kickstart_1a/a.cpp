#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

#define ll long long int

using namespace std;

int main() {
  int t;
  cin >> t;
  for(int i = 1; i <= t; i++) {
    string s;
    cin >> s;
    ll ans = 0;
    if (s.length() == 1 && stoll(s) % 2) {
      cout << "Case #" << i << ": " << 1 << endl;
      continue;
    }
    for (int j = 0; j < s.length(); j++) {
      int check = s[j] - '0';
      if (check % 2) {
	string right = s.substr(j + 1);
	if (right.length() == 0) {
	  ans = 1;
	  break;
	}
	int length = right.length();
	ll remaining = stoll(right);
	ll eights = 0;
	for (int i = 0; i < length; i++) {
	  eights += 8 * pow(10, i);
	}
	ll smaller = remaining + pow(10, length) - eights;
	ll bigger = (check == 9) ? smaller : pow(10, length) - remaining;
	ans = min(bigger, smaller);
	break;
      }
    }
    cout << "Case #" << i << ": " <<  ans << endl;
  }
}
