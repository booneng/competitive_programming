#include <bits/stdc++.h>

using namespace std;
unordered_set<long long> visited;

pair<int, int> findSteps(long long n) {
  visited.insert(n);
  int steps = 0;
  long long sq = sqrt(n);
  while (sq * sq == n) {
    steps++;
    n = sq;
    sq = sqrt(n);
  }
  long long smallest = n;
  int smallest_steps = steps;
  for (long long i = 2; i < n; i++) {
    long long mul = i * n;
    sq = sqrt(mul);
    if (sq * sq == mul) {
      if (visited.find(mul) != visited.end()) continue;
      auto p = findSteps(mul);
      if (p.first < smallest) {
	smallest = p.first;
	smallest_steps = steps + p.second + 1;
      }
      else if (p.first == smallest) {
	smallest_steps = min(smallest_steps, steps + p.second + 1);
      }
    }
  }
  return {smallest, smallest_steps};
}

int main() {
  long long n;
  cin >> n;
  auto p = findSteps(n);
  cout << p.first << ' ' << p.second;
}
