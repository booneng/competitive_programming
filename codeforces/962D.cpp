#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <set>

#define ll long long int

using namespace std;

bool sortFunc(pair<ll, int> a, pair<ll, int> b) {
  return a.second < b.second;
}

int main() {
  int n;
  cin >> n;
  map<ll, set<int> > m;
  set<pair<ll, ll> > en;
  for (int i = 0; i < n; i++) {
    ll temp;
    cin >> temp;
    m[temp].insert(i);
  }

  while(m.size()) {
    auto a = *m.begin();
    m.erase(m.begin());
    while (a.second.size() >= 2) {
      a.second.erase(a.second.begin());
      m[2 * a.first].insert(*a.second.begin());
      a.second.erase(a.second.begin());
    }
    if (a.second.size() == 1) en.insert(make_pair(*a.second.begin(), a.first));
  }
  cout << en.size() << endl;
  for (auto a: en) cout << a.second << ' ';
}
