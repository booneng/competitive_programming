#include <bits/stdc++.h>

using namespace std;

int main() {
  int a = 10;
  int b = 1;
  
  int prev;
  cout << "? 0 0" << endl;
  cout.flush();
  cin >> prev;
  int add_a = 0;
  int add_b = 0;
  for (int i = 29; i >= 0; i--) {
    int num = 1 << i;
    cout << "? " << num + add_a << ' ' << num + add_b << endl;
    cout.flush();
    int res;
    cin >> res;
    if (res > prev) {
      add_b += num;
      cout << "? " << add_a << ' ' << add_b << endl;
      cout.flush();
      cin >> res;
      prev = res;
    }
    else if (res < prev) {
      add_a += num;
      cout << "? " << add_a << ' ' << add_b << endl;
      cout.flush();
      cin >> res;
      prev = res;
    }
    else {
      cout << "? " << num + add_a << ' ' << add_b << endl;
      cout.flush();
      cin >> res;
      if (res == -1) {
	add_a += num;
	add_b += num;
      }
    }
  }
  cout << "! " << add_a << ' ' << add_b;
}
