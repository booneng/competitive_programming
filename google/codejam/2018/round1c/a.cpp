#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

#define ll long long int

using namespace std;

int n, l;
set<string> wordset;
set<char> pos_char[15];


string get_word(string cur, int i) {
  if (i == l) {
    if (wordset.find(cur) == wordset.end()) return cur;
    return "-";
  }
  for (set<char>::iterator it = pos_char[i].begin(); it != pos_char[i].end(); it++) {
    string tmp = cur + *it;
    string ret = get_word(tmp, i + 1);
    if (ret.compare("-") != 0) {
      return ret;
    }
  }
  return "-";
}
void solve() {
  cin >> n >> l;
  wordset.clear();
  for (int i = 0; i < l; i++) {
    pos_char[i].clear();
  }
  
  for (int i = 0; i < n; i++) {
    string word;
    cin >> word;
    wordset.insert(word);
    for (int j = 0; j < l; j++) {
      pos_char[j].insert(word[j]);
    }
  }
  
  cout << get_word("", 0) << endl;
}

int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
}
