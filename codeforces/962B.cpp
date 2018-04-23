#include <iostream>
#include <string>

#define ll long long int

using namespace std;

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  string railway;
  cin >> railway;
  bool prev_a = false;
  bool prev_p = false;
  int count = 0;
  for (int i = 0; i < railway.length(); i++) {
    if (railway[i] == '.') {
      if (prev_a) {
	prev_a = false;
	if (a > 0) {
	  prev_p = true;
	  a--;
	  count++;
	}
      }
      else if (prev_p) {
	prev_p = false;
	if (b > 0) {
	  prev_a = true;
	  b--;
	  count++;
	}
      }
      else if (!(prev_a || prev_p)){
	if (a > b) {
	  prev_p = true;
	  a--;
	  count++;
	}
	else if (b > 0) {
	  prev_a = true;
	  b--;
	  count++;
	}
      }
    }
    else {
      prev_a = false;
      prev_p = false;
    }
  }
  cout << count;
}
