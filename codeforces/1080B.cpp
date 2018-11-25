#include <bits/stdc++.h>

using namespace std;

long long sumToi(long long i) {
  long long half = i / 2;
  long long add = half * (half + 1);
  long long minus = half * (half - 1) + half;
  if (i % 2) minus += i;
  return add - minus;

}


int main() {
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    long long l, r;
    cin >> l >> r;
    cout << sumToi(r) - sumToi(l - 1) << endl;
  }

}
