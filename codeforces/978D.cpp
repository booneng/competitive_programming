#include <iostream>

using namespace std;

int n;
int b[100005];
int diff[100005];
int tmp[100005];

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }

  for (int i = 1; i < n; i++) {
    diff[i] = b[i] - b[i - 1];
  }

  set<int> possible_diffs;
  possible_diffs.insert(diff[1]);
  possible_diffs.insert(diff[1] - 1);
  possible_diffs.insert(diff[1] + 1);
  possible_diffs.insert(diff[1] - 2);
  possible_diffs.insert(diff[1] + 2);
  
  for (int i = 2; i < n; i++) {
    if (possible_diffs.find(diff[i]) != possible_diff.end()) possible_diffs.insert(diff[i]);
    if (possible_diffs.find(diff[i] - 1) != possible_diff.end()) possible_diffs.insert(diff[i] - 1);
    if (possible_diffs.find(diff[i] + 1) != possible_diff.end()) possible_diffs.insert(diff[i] + 1);
    if (possible_diffs.find(diff[i] - 2) != possible_diff.end()) possible_diffs.insert(diff[i] - 2);
    if (possible_diffs.find(diff[i] + 2) != possible_diff.end()) possible_diffs.insert(diff[i] + 2);
  }

  int ans = 100000;
  set<int>::iterator it = possible_diffs.begin();
  for (; it != possible_diffs.end(); it++) {
    int cur_diff = *it;
    for (int i = 1; i < n; i++) tmp[i] = diff[i];
    for (int i = 1; i < n - 1; i++) {
      if (tmp[i] == cur_diff && tmp[i + 1] == cur_diff) continue;
      else if (tmp[i] == cur_diff - 1) 
    }
  }
}
