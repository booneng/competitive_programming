#include <iostream>
#include <algorithm>

using namespace std;

int n;
int b[100005];
int diff[100005];
int tmp[100005];

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }

  int ans = 100005;
  for (int i = -1; i < 2; i++) {
    for (int j = -1; j < 2; j++) {
      int diff = b[1] + j - b[0] - i;
      bool ok = true;
      int count = 0;
      if (i) count++;
      if (j) count++;
      for (int k = 2; k < n; k++) {
	int comp = b[0] + i + k * diff;
	int kdiff = comp - b[k];
	if (!(kdiff <= 1 && kdiff >= -1)) {
	  ok = false;
	  break;
	}
	else if (kdiff) count++;
      }
      if (ok) ans = min(ans, count);
    }
  }
  if (ans == 100005) cout << -1;
  else cout << ans;
}
