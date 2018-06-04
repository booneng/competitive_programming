#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>

#define ll long long int

using namespace std;

int main() {
  int t;
  cin >> t;
  cout << fixed;
  for (int i = 1; i <= t; i++) {
    int n;
    double p;
    cin >> n >> p;
    int cookies[105][2];
    double perimeter = 0;
    for (int j = 0; j < n; j++) {
      cin >> cookies[j][0] >> cookies[j][1];
      perimeter += 2 * cookies[j][0] + 2 * cookies[j][1];
    }
    double missing =  p - perimeter;
    double small = 2 * min(cookies[0][0], cookies[0][1]);
    double large = 2 * sqrt((double)cookies[0][0] * cookies[0][0] + cookies[0][1] * cookies[0][1]);
    if (n * small <= missing && n * large >= missing) {
      perimeter = p;
    }
    else if (n * small >= missing && small <= missing) {
      perimeter = p;
    }
    else if (n * large <= missing) {
      perimeter += n * large;
    }
    cout << "Case #" << i << ": " << perimeter << endl;
  }

}
