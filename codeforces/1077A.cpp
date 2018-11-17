#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int a, b, k;
    cin >> a >> b >> k;
    long long int pos = (k / 2) * (a - b);
    if (k % 2) pos += a;
    cout << pos << endl;
  }

}
