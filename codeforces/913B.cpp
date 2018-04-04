#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  int children[n];
  int parents[n];
  int leaf_children[n];
  for (int i = 0; i < n; i++) {
    children[i] = 0;
    leaf_children[i] = 0;
    parents[i] = 0;
  }
  for (int i = 1; i < n; i++) {
    cin >> parents[i];
    parents[i]--;
    children[parents[i]]++;
  }
  for (int i = 0; i < n; i++) {
    if (children[i] == 0) leaf_children[parents[i]]++;
  }
  for (int i = 0; i < n; i++) {
    if (children[i] > 0 && leaf_children[i] < 3) {
      cout << "No";
      return 0;
    }
  }
  cout << "Yes";
}
