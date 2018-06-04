#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long int

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    int n;
    cin >> n;
    vector<int> even;
    vector<int> odd;
    for (int j = 0; j < n; j++) {
      int temp;
      cin >> temp;
      if(j % 2) {
	even.push_back(temp);
      }
      else {
	odd.push_back(temp);
      }
    }
    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());
    int trouble_sorted[n];
    for (int j = 0; j < n; j++) {
      if (j % 2) {
	trouble_sorted[j] = even[j / 2];
      }
      else {
	trouble_sorted[j] = odd[j / 2];
      }
    }
    int first = -1;
    for (int k = 0; k < n - 1; k++) {
      if (trouble_sorted[k] > trouble_sorted[k + 1]) {
	first = k;
	break;
      }
    }
    cout << "Case #" << i << ": ";
    if (first < 0) cout << "OK";
    else cout << first;
    cout << endl;
  }
}
