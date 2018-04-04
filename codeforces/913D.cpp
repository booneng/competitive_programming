#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
bool sortFunc(const vector<int>& p1, const vector<int>& p2 ) {
  return p1[0] < p2[0];
}

int main() {
  int n, T;
  cin >> n >> T;
  vector<vector<int> > at;
  for (int i = 0; i < n; i++) {
    int a, t;
    cin >> a >> t;
    vector<int> temp;
    temp.push_back(t);
    temp.push_back(a);
    temp.push_back(i + 1);
    at.push_back(temp);
  }
  sort(at.begin(), at.end(), sortFunc);
  int right = n;
  int left = 0;
  vector<int> p;
  while (left <= right) {
    bool solvable = true;
    int k = (right + left) / 2;
    int time = 0;
    int count = 0;
    vector<int> temp;
    for (int i = 0; i < n; i++) {
      if (at[i][1] <= k) {
	time += at[i][0];
	count++;
	temp.push_back(at[i][2]);
	if (count == k) break;
      }
    }
    if (count < k || time > T) solvable = false;
    if (solvable) {
      left = k + 1;
      p = temp;
    }
    else right = k - 1;
  }
  cout << p.size() << endl;
  cout << p.size() << endl;
  for (int i = 0; i < p.size(); i++) {
    cout << p[i] << ' ';
  }

}
