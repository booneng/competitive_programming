#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n;
  cin >> n;
  set<int> arr;
  for(int i = 0; i < n; i++) {
    int temp;
    cin >> temp;
    arr.insert(temp);
  }
  int max = 0;
  vector<int> a;
  for (set<int>::iterator i = arr.begin(); i != arr.end(); i++) {
    a.push_back(*i);
  }
  sort(a.begin(), a.end());
  int u = a.size();
  for (int i = u - 2; i >= 0; i--) {
    if (a[i] < max) break;
    int max_mul = a[u - 1] / a[i] + 1;
    for(int j = 2; j <= max_mul; j++) {
      int tmp = j * a[i];
      int p = lower_bound(a.begin(), a.end(), tmp) - a.begin();
      if (p > 0) {
	int cur = a[p - 1] % a[i];
	if (cur > max) {
	  max = cur;
	}
      }
    }
  }
  cout << max;

}
