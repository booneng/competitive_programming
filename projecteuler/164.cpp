#include <iostream>

using namespace std;

unsigned long long int cache[20][10][10];

unsigned long long int counts(int i, int prev, int prev_prev) {
  if (i == 20) return 1;
  unsigned long long int total = 0;
  if (cache[i][prev][prev_prev] != 0) {
    return cache[i][prev][prev_prev];
  }
  for (int j = 0; prev + prev_prev + j <= 9; j++) {
    if (i == 0 && j == 0) {
      continue;
    }
    total += counts(i + 1, j, prev);
  }
  cache[i][prev][prev_prev] = total;
  return total;
}

int main() {
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 10; j++) {
      for (int k = 0; k < 10; k++) {	
	cache[i][j][k] = 0;
      }
    }
  }
  cout << counts(0, 0, 0);
}
