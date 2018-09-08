#include <iostream>
#include <vector>
#include <cmath>

#define ll long long int

using namespace std;

int main() {
  ll l;
  cin >> l;
  vector<int> bin_rep;
  int count = 0;
  while (l) {
    if (l & 1) {
      count++;
      bin_rep.push_back(1);
    }
    else {
      bin_rep.push_back(0);
    }
    l >>= 1;
  }

  ll mul = 1;
  cout << bin_rep.size() << ' ' << (bin_rep.size() - 1) * 2 + count - 1 << endl;
  for (int i = 1; i < bin_rep.size(); i++) {
    cout << i << ' ' << i + 1 << ' ' << 0 << endl;
    cout << i << ' ' << i + 1 << ' ' << mul << endl;
    mul *= 2;
  }

  for (int i = 0; i < bin_rep.size() - 1; i++) {
    if (bin_rep[i]) {
      cout << i + 1 << ' ' << bin_rep.size() << ' ' << mul << endl;
      mul += pow(2, i);
    }
  }
}
