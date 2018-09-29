#include <iostream>
#include <climits>
#include <map>
#include <set>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  map<int, int> counts;
  set<int> elems;
  for (int i = 0; i < n; i++) {
    int s;
    cin >> s;
    elems.insert(s);
    counts[s]++;
  }
  int nice = 0;
  bool not_nice = false;
  for (int i : elems) {
    if (counts[i] == 1) nice++;
    else if (counts[i] > 2) {
      not_nice = true;
    }
  }
  if (nice % 2 == 0 || not_nice) {
    cout << "YES" << endl;
  }
  else {
    cout << "NO" << endl;
    return 0;
  }

  map<int, bool> mark_a;
  int nice_marked = 0;
  if (nice > 1) {
    for (int i : elems) {
      if (counts[i] == 1) {
	nice_marked++;
	mark_a[i] = true;
	if (nice_marked == nice / 2) break;
      }
    }
  }

  bool mark_one_not_nice = false;
  if (nice % 2) mark_one_not_nice = true;
  for (int i : s) {
    if (mark_a[i]) {
      cout << "A"; 
    }
    else if (mark_one_not_nice && counts[i] > 2) {
      mark_one_not_nice = false;
      cout << "A";
    }
    else {
      cout << "B";
    }
  }


}
