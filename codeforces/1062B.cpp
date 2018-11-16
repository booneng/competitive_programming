#include <bits/stdc++.h>

using namespace std;

int main() {
  long long n;
  cin >> n;

  if (n == 1) {
    cout << 1 << ' ' << 0;
  }
  else {
    int max_power = -1;
    bool two_powers = false;
    vector<int> primes;
    for (int i = 2; i * i <= n; i++) {
      if (n % i == 0) {
	int power = 0;
	while (n % i == 0) {
	  power++;
	  n /= i;
	}
	if (max_power > 0 && power != max_power) {
	  two_powers = true;
	}
	max_power = max(max_power, power);
	primes.push_back(i);
      }
    }
    if (n > 1) {
      if (max_power > 1) two_powers = true;
      else max_power = 1;
    }
    for (int i : primes) n *= i;
    int steps = 0;
    int i = 1;
    while (i < max_power) {
      i *= 2;
      steps++;
    }
    if (i > max_power || two_powers) steps++;
    cout << n << ' ' << steps;
  }
}
