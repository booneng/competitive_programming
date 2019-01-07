#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

#define ll long long int

using namespace std;

int d;
int n;
int ids[205];
int appearances[205];

void solve() {
  cin >> n;
  set<int> sold;
  for (int i = 0; i < n; i++) {
    appearances[i] = 0;
  }
  for(int i = 0; i < n; i++) {
    cin >> d;
    for (int i = 0; i < d; i++) {
      cin >> ids[i];
      appearances[ids[i]]++;
    }
    int min_not_sold = -1;
    int min_app = 205;
    for (int i = 0; i < d; i++) {
      if (sold.find(ids[i]) == sold.end()) {
	if (appearances[ids[i]] <= min_app) {
	  min_app = appearances[ids[i]];
	  min_not_sold = ids[i];
	}
      }
    }
    if (min_not_sold >= 0) {
      sold.insert(min_not_sold);
      cout << min_not_sold << endl;
    }
    else {
      cout << -1 << endl;
    }
    cout.flush();
  }
}

int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    solve();
  }
}
