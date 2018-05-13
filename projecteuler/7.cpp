#include <iostream>
#include <vector>

#define ll long long int

using namespace std;

int main() {
  vector<ll> primes;
  primes.push_back(2);
  ll cur = 3;
  while (primes.size() < 10001) {
    bool can = true;
    for (int i = 0; i < primes.size(); i++) {
      if (cur % primes[i] == 0) {
	cur += 2;
	can = false;
	break;
      }
    }
    if (can) primes.push_back(cur), cur += 2;
  }
  cout << primes[10000];
}
