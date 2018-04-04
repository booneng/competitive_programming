#include <iostream>
#include <string>
#include <map>
#include <vector>
#define ll long long int

using namespace std;

int main() {
  int n, k, m;
  cin >> n >> k >> m;
  vector<string> words;
  map<string, int> word_groups;
  
  for (int i = 0; i < n; i++) {
    string tmp;
    cin >> tmp;
    words.push_back(tmp);
  }
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int min_groups[k];
  for (int i = 0; i < k; i++) {
    int x;
    cin >> x;
    int min = 1000000000;
    for (int j = 0; j < x; j++) {
      int word_index;
      cin >> word_index;
      word_index--;
      word_groups.insert(make_pair(words[word_index], i));
      if (a[word_index] < min) min = a[word_index];
    }
    min_groups[i] = min;
  }
  ll score = 0;
  for (int i = 0; i < m; i++) {
    string word;
    cin >> word;
    int group = word_groups.find(word)->second;
    score += min_groups[group];
  }
  cout << score;
}
