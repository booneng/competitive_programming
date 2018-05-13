#include <iostream>
#include <set>
#include <vector>

using namespace std;

int n;
int a[1005];
set<int> seen;
vector<int> newa;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = n - 1; i >= 0; i--) {
    if (seen.find(a[i]) == seen.end()) {
      newa.push_back(a[i]);
      seen.insert(a[i]);
    }
  }
  cout << newa.size() << endl;
  for (int i = newa.size() - 1; i >= 0; i--) {
    cout << newa[i] << ' ';
  }
}
