#include <iostream>

using namespace std;
int n;
int main() {
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == -1) continue;
    ans ^= 1;
    int x = i;
    while (x != -1) {
      int y = a[x];
      a[x] = -1;
      x = y;
    }
  }

  if (ans) {
    cout << "Um_nik";
  }
  else {
    cout << "Petr";
  }
}
