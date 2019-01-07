#include <iostream>
#include <string>

using namespace std;

int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    string s;
    cin >> s;
    string r;
    char first = s[0];
    r.insert(0, 1, first);
    for (int j = 1; j < s.size(); j++) {
      char current = s[j];
      if (current >= first) {
	r.insert(0, 1, current);
	first = current;
      }
      else {
	r.insert(r.end(), 1, current);
      }
    }
    cout << "Case #" << i << ": " << r << endl;
  }

}
