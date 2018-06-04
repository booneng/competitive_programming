#include <iostream>
#include <cmath>

using namespace std;

int main() {
  cout << fixed;
  cout.precision(20);
  int t;
  cin >> t;
  double PI = atan(1) * 4; 
  for (int i = 1; i <= t; i++) {
    double a;
    cin >> a;
    double theta1 = fabs(asin(a / 1.414213) - PI / 4);
    double theta2 = PI / 2 - theta1;
    if (theta1 < theta2) {
      double temp = theta1;
      theta1 = theta2;
      theta2 = temp;
    }
    double temp = theta1 - PI / 4;
    double top_x = sqrt(0.5) * sin(temp);
    double top_y = sqrt(0.5) * cos(temp);
    double dx1 = cos(-theta1);
    double dy1 = sin(-theta1);
    double x1 = top_x + dx1 / 2;
    double y1 = top_y + dy1 / 2;
    double dx2 = cos(PI + theta2);
    double dy2 = sin(PI + theta2);
                             double x2 = top_x + dx2 / 2;
    double y2 = top_y + dy2 / 2;
    cout << "Case #" << i << ": " << endl;
    cout << x1 << ' ' << y1 << ' ' << 0 << endl;
    cout << x2 << ' ' << y2 << ' ' << 0 << endl;
    cout << 0 << ' ' << 0 << ' ' << 0.5 << endl;
  }

}
