#include <iostream>
#include <vector>

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
  for (int i = 2; i < n; i++) {
    cout << i << ' ' << isprime[i] << endl;
  }
}
