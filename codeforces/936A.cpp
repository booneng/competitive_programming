#include <iostream>
#define ll long long int
using namespace std;

int main() {
  ll k, d, t;
  cin >> k >> d >> t;
  cout << fixed;
  double cooked = 0;
  ll m = k / d;
  while (d < (double)k / m) {
    m++;
  }
  double diff = (double)m * d - k;
  double addition1 = (double)k / t;
  double addition2 = diff / (2 * t);
  double batch_cook = addition1 + addition2;
  double batch_time = k + diff;
  ll batches = 1 / batch_cook;
  double minutes = batches * batch_time;
  double remaining = 1 - (batches * batch_cook);
  if (remaining > addition1) {
    minutes += k;
    remaining -= addition1;
    minutes += remaining * 2 * t;
  }
  else {
    minutes += remaining * t;
  }
  cout << minutes;
}
