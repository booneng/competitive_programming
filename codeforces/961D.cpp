#include <iostream>
#include <cmath>
#define ll long long int
using namespace std;

ll p[100005][2];
ll b[100005][2];
int n;

bool solve(ll x1, ll y1, ll x2, ll y2) {
  ll xdiff = x2 - x1;
  ll ydiff = y2 - y1;
  int m = 0;
  for (int i = 0; i < n; i++) {
    ll xi = p[i][0];
    ll yi = p[i][1];
    if ((xi - x1) * ydiff - (yi - y1) * xdiff != 0) {
      b[m][0] = xi;
      b[m][1] = yi;
      m++;
    }
  }
  if (m <= 2) {
    return true;
  }
  x1 = b[0][0];
  y1 = b[0][1];
  xdiff = b[1][0] - b[0][0];
  ydiff = b[1][1] - b[0][1];
  for (int i = 0; i < m; i++) {
    ll xi = b[i][0];
    ll yi = b[i][1];
    if ((xi - x1) * ydiff - (yi - y1) * xdiff != 0) {
      return false;
    }
  }
  return true;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> p[i][0] >> p[i][1];
  }
  if (solve(p[0][0], p[0][1], p[1][0], p[1][1]) || solve(p[0][0], p[0][1], p[2][0], p[2][1]) || solve(p[1][0], p[1][1], p[2][0], p[2][1])) cout << "YES";
  else cout << "NO";					 
}

      
