#include <iostream>
#include <vector>

using namespace std;


int main() {
  int n;
  cin >> n;
  vector<int> x(n), y(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }

  bool odd = (x[0] + y[0]) % 2 ? true : false;

  for (int i = 0; i < n; i++) {
    if (odd && (x[i] + y[i]) % 2 == 0) {
      cout << -1;
      return 0;
    }
    if (!odd && (x[i] + y[i]) % 2) {
      cout << -1;
      return 0;
    }
  }


  vector<int> d(31, 1);
  for (int i = 0; i < d.size(); i++) {
    d[i] = 1 << i;
  }
  if (!odd) d.insert(d.begin(), 1);
  cout << d.size() << endl;
  for (int i = 0; i < d.size(); i++) cout << d[i] << ' ';
  cout << endl;
  for (int i = 0; i < n; i++) {
    int px = 0, py = 0;
    string s;
    for (int j = d.size() - 1; j >= 0; j--) {
      int ydiff = y[i] - py;
      int xdiff = x[i] - px;
      if (abs(xdiff) > abs(ydiff)) {
	if (xdiff < 0) {
	  s = "L" + s;
	  px -= d[j];
	}
	else {
	  s = "R" + s;
	  px += d[j];
	}
      }
      else {
	if (ydiff < 0) {
	  s = "D" + s;
	  py -= d[j];
	}
	else {
	  s = "U" + s;
	  py += d[j];
	}
      }
    }
    cout << s << endl;
  }
}
