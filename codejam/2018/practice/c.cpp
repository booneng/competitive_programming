#include <iostream>
#define ll long long int
using namespace std;

int main() {
  int t;
  cin >> t;
  cout << fixed;
  for (int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    ll d;
    int n;
    cin >> d >> n;
    double max_time = 0;
    for (int i = 0; i < n; i++) {
      ll k, s;
      cin >> k >>  s;
      double time = (double)(d - k) / s;
      if (time > max_time) max_time = time;
    }
    cout << d / max_time << endl;
  }

}
