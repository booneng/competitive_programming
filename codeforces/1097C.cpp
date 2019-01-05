#include <bits/stdc++.h>

using namespace std;

bool check(string s) {
  stack<char> st;
  for (char c : s) {
    if (c == '(') {
      st.push(c);
    }
    else {
      if (!st.empty() && st.top() == '(') {
        st.pop();
      }
      else {
        st.push(c);
      }
    }
  }
  int checksum = 0;
  while (!st.empty()) {
    if (st.top() == '(') {
      checksum |= 1;
    }
    else {
      checksum |= 2;
    }
    if (checksum == 3) return false;
    st.pop();
  }
  return true;
}


int main() {
  int n;
  cin >> n;
  unordered_map<int, int> score_counts;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    if (!check(s)) continue;
    int score = 0;
    for (char c : s) {
      if (c == '(') {
        score++;
      }
      else {
        score--;
      }
    }
    if (score_counts[-score] > 0) {
      ans++;
      score_counts[-score]--;
    }
    else {
      score_counts[score]++;
    }
  }
  cout << ans;
}