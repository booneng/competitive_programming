#include <iostream>
#include <queue>

#define ll long long int
using namespace std;

void solve(int t) {
  ll c, d, v;
  queue<ll> den;
  cin >> c >> d >> v;
  for (int i = 0; i < d; i++) {
    ll temp;
    cin >> temp;
    den.push(temp);
  }
  ll n = 0;
  ll add = 0;
  while (n < v) {
    ll x = n + 1;
    if (!den.empty() && den.front() <= x) {
      x = den.front();
      den.pop();
    }
    else {
      add++;
    }
    n = n + x * c;
  }
  cout << "Case #" << t << ": " << add << endl;
}

int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    solve(i);
  }
}
