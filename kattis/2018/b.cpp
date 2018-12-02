#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <sstream>


using namespace std;

vector<string> sentence;

void add(string word, set<string>& wordset) {
  if (word[word.size() - 1] == '.' || word[word.size() - 1] == ',') {
    word = word.substr(0, word.size() - 1);
  }
  wordset.insert(word);
}

int main() {
  string s;
  getline(cin, s);
  size_t pos = 0;
  const string ws = " \t\r\n";
  while (pos != s.size()) {
    size_t from = s.find_first_not_of(ws, pos);
    if (from == string::npos) {
      break;
    }
    size_t to = s.find_first_of(ws, from+1);
    if (to == string::npos) {
        to = s.size();
    }
    pos = to;
    sentence.push_back(s.substr(from, to - from));
  }
  
  set<string> comma_before;
  set<string> comma_after;
  for (int i = 0; i < sentence.size(); i++) {
    string word = sentence[i];
    if (word[word.size() - 1] == ',') {
      add(word, comma_after);
      add(sentence[i + 1], comma_before);
    }
  }
  
  for (int i = 0; i < sentence.size() - 1; i++) {
    string word = sentence[i];
    if (word[word.size() - 1] == '.' || word[word.size() - 1] == ',') {
    }
    else if (comma_after.find(word) != comma_after.end()) {
      word += ',';
    }
    else if (comma_before.find(sentence[i + 1]) != comma_before.end()) {
      word += ',';
    }
    cout << word << ' ';
  }
  cout << sentence[sentence.size() - 1];
}
