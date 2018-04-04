#include <iostream>

using namespace std;

int n, m;
int x[1000001], y[1000001];

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> x[i];
  for (int i = 0; i < m; i++) cin >> y[i];
  int i = 0;
  int j = 0;
  int xc;
  int yc;
  int count = 0;
  while (i < n && j < m) {
    xc = x[i];
    yc = y[j];
    i++;
    j++;
    while (xc != yc) {
      if (xc < yc) xc += x[i], i++;
      else yc += y[j], j++;
    }
    count++;
  }
  cout << count;
}
