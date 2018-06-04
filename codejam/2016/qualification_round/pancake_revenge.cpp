#include <iostream>

using namespace std;

int main() {
  int tc;
  cin >> tc;
  for(int t = 0; t < tc; t++) {
    string pancakes;
    cin >> pancakes;
    int count = 0;
    for (int i = pancakes.length() - 1; i >= 0; i--) {
      if (pancakes[i] == '-') {
	for (int j = i; j >= 0; j--) {
	  pancakes[j] = (pancakes[j] == '+') ? '-' : '+';
	}
	count++;
      }
    }
    cout << "Case #" << t + 1 << ": " << count << endl;
  }
}
