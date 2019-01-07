#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int n, c, m;
    cin >> n >> c >> m;
    vector<int> seats(1005);
    for (int i = 0; i < m; i++) {
      int p, b;
      cin >> p >> b;
      seats[p]++;
    }
    int total = 0;
    int most = 0;
    for (int i = 1; i <= c; i++) {
      total += customers[i].size();
      most = max(most, (int)customers[i].size());
    }
    int rc;
    if (total % n) {
      rc = max(total / n + 1, most);
    }
    else {
      rc = max(total / n, most);
    }
    int tseats = 0;
    for (int i = 1; i <= n; i++) {
      tseats += seats[i];
      int lb;
      if (tseats % i) lb = tseats / i + 1;
      else lb = tseats / i;
      rc = max(rc, lb);
    }
    int promoted = 0;
    for (int i = 1; i <= n; i++) {
      if (seats[i] > rc) promoted += seats[i] - rc;
    }
    cout << "Case #" << t << ": " << rc << ' ' << promoted << endl;
  }
}
