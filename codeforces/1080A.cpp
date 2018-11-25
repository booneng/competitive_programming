#include <bits/stdc++.h>

using namespace std;

int main() {
  long long n, k;
  cin >> n >> k;

  long long nredbooks = n * 2 / k;
  if ((n * 2) % k) nredbooks++;
  long long ngreenbooks = n * 5 / k;
  if ((n * 5) % k) ngreenbooks++;
  long long nbluebooks = n * 8 / k;
  if ((n * 8) % k) nbluebooks++;

  cout << (nredbooks + ngreenbooks + nbluebooks);
}
