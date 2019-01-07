#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool sortFunc(vector<int> a, vector<int> b) {
  return a[0] < b[0];
}


int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    vector< vector<int> > numbers;
    int counts[2505] = {0};
    int n;
    cin >> n;
    for (int j = 0; j < 2 * n - 1; j++) {
      for (int k = 0; k < n; k++) {
	int temp;
	cin >> temp;
	counts[temp]++;
      }
    }
    cout << "Case #" << i << ": ";
    for (int j = 0; j < 2505; j++) {
      if (counts[j] % 2) {
	cout << j << ' ';
      }
    }
    cout << endl;
  }  
}
