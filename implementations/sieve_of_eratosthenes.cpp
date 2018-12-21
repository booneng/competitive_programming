#include <iostream>
#include <vector>
#include <bits/stdc++.h>


using namespace std;

int main() {
  int n;
  cin >> n;
  vector<bool> isprime(n, true);
  for (int i = 2; i <= sqrt(n); i++) {
    if (isprime[i]) {
      for (int j = i * i; j <= sqrt(n); j += i) {
	isprime[j] = false;
      }
    }
  }
  int m = 0;
  for (int i = 2; i < n; i++) {
    // cout << i << ' ' << isprime[i] << endl;
    if (isprime[i]) m = i;
  }
  cout << m;
}
