#include <iostream>
#include <string>
#include <set>
 
using namespace std;
 
string s;
int k;
set<string> substrings;
 
int main() {
  cin >> s;
  cin >> k;
  for (int i = 0; i < s.size(); i++) {
    for (int j = 1; j <= s.size() - i && j <= k; j++) {
      substrings.insert(s.substr(i, j));
    }
  }
  set<string>::iterator it = substrings.begin();
  for (int i = 1; i < k; i++) it++;
  cout << *it;
}
