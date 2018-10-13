#include <iostream>
#include <map>

using namespace std;

int main() {
  int q;
  cin >> q;
  int l = -1;
  int r = 1;
  map<int, int> books;
  char type;
  int id;
  cin >> type >> id;
  books[id] = 0;
  q--;
  while (q--) {
    cin >> type >> id;
    if (type == 'L') {
      books[id] = l;
      l--;
    }
    else if (type == 'R') {
      books[id] = r;
      r++;
    }
    else {
      int pos = books[id];
      cout << min(r - pos - 1, pos - l - 1) << endl;
    }
  }
}
