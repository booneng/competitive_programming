#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long int

using namespace std;


ll getGCD(ll n1, ll n2) {
  while(n1 != n2) {
    if(n1 > n2)
      n1 -= n2;
    else
      n2 -= n1;
  }
  return n1;
}

int main() {
  int n;
  ll p;
  
  cin >> n >> p;
  vector<ll> x(n);

  bool found = false;
  for (int i = 0; i < n; i++) {
    cin >> x[i];
    if (x[i] == p) found = true;
  }
  if (!found) x.push_back(p);
  sort(x.begin(), x.end());
  
  int gcd = x[1] - x[0];
  for (int i = 2; i < x.size(); i++) {
    gcd = getGCD(gcd, x[i] - x[i - 1]);
  }
  cout << gcd;
}
