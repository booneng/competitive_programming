#include <iostream>
#include <set>
using namespace std;

int main() {
  int t;
  cin >> t;
  for (int j = 0; j < t; j++) {
    int n;
    cin >> n;
    cout << "Case #" << j + 1 << ": ";
    if (n == 0) {
      cout << "INSOMNIA" << endl;
      continue;
    }
    set<int> seen;
    int i = 1;
    while (1) {
      int c = n * i;
      while (c > 0) {
	int current = c % 10;
	if (seen.find(current) == seen.end()) {
	  seen.insert(current);
	}
	c /= 10;
      }
      if (seen.size() == 10) {
	cout << n * i << endl;
	break;
      }
      i++;
    }
  }

}
