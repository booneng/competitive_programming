#include <bits/stdc++.h>

using namespace std;

double dist(double x1, double y1, double x2, double y2) {
  double dx = x1 - x2;
  double dy = y1 - y2;
  return sqrt(dx * dx + dy * dy);
}

int main() {
  cout << setprecision(10);
  cout << fixed;
  double a, b, c;
  cin >> a >> b >> c;
  double x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  double ans = abs(x1 - x2) + abs(y1 - y2);
  double px1 = (-b * y1 - c) / a;
  double py1 = (-a * x1 - c) / b;
  double px2 = (-b * y2 - c) / a;
  double py2 = (-a * x2 - c) / b;
  double dx1x2 = abs(px1 - x1) + dist(px1, y1, px2, y2) + abs(px2 - x2);
  double dx1y2 = abs(px1 - x1) + dist(px1, y1, x2, py2) + abs(py2 - y2);
  double dy1x2 = abs(py1 - y1) + dist(x1, py1, px2, y2) + abs(px2 - x2);
  double dy1y2 = abs(py1 - y1) + dist(x1, py1, x2, py2) + abs(py2 - y2);
  ans = min(ans, dx1x2);
  ans = min(ans, dx1y2);
  ans = min(ans, dy1x2);
  ans = min(ans, dy1y2);
  cout << ans;
}
