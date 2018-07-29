#include <iostream>
#include <string>
#include <map>

using namespace std;

int n;
string s;

int main() {
  cin >> n >> s;
  long long int ans = 0;
  map<string, int> mp;
  for (int t = 0; t < (1 << n); t++) {
    string a = "", b = "";
    for (int i = 0; i < n; i++) {
      if (t & (1 << i)) a += s[i];
      else b += s[i];
    }
    string c = a + "." + string(b.rbegin(), b.rend());
    mp[c]++;
  }
  
  for (int t = 0; t < (1 << n); t++) {
    string a = "", b = "";
    for (int i = 0; i < n; i++) {
      if (t & (1 << i)) a += s[i + n];
      else b += s[i + n];
    }
    string c = string(a.rbegin(), a.rend()) + "." + b;
    ans += mp[c];
  }
  cout << ans;
}
