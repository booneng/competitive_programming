#include <iostream>

using namespace std;

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int n;
    cin >> n;
    int m[1005];
    for (int i = 0; i < n; i++) {
      cin >> m[i];
    }
    int y = 0;
    for (int i = 1; i < n; i++) {
      if (m[i] < m[i - 1]) y += m[i - 1] - m[i];
    }

    int z = 0;
    int min_rate = 0;
    for (int i = 1; i < n; i++) {
      if (m[i] < m[i - 1]) min_rate = max(m[i - 1] - m[i], min_rate);
    }

    for (int i = 0; i < n - 1; i++) {
      if (m[i] > min_rate) z += min_rate;
      else z += m[i];
    }
    cout << "Case #" << t << ": " << y << ' ' << z << endl;
  }
  
}
