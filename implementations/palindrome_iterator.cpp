#include <bits/stdc++.h>

using namespace std;

int nextPalindrome(int x) {
  string s = to_string(x);
  int n = s.size();
  int mid2 = n / 2;
  int mid1 = n - 1 - mid2;
  bool nines = true;
  while (mid1 >= 0) {
    if (s[mid1] != '9') {
      s[mid1]++;
      s[mid2] = s[mid1];
      nines = false;
      break;
    }
    else {
      s[mid1] = '0';
      s[mid2] = '0';
      mid1--;
      mid2++;
    }
  }
  if (nines) {
    s[0] = '1';
    s += '1';
  }
  return stoi(s);
}

int main() {
  int x = 1;
  while (x < 10000000) {
    cout << x << endl;
    x = nextPalindrome(x);
  }

}
