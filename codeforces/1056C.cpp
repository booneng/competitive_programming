#include <bits/stdc++.h>

using namespace std;

int pick(set<int>& first, vector<int>& p, const vector<pair<int, int>>& psort, int& pindex) {
  if (first.size() != 0) {
    auto it = first.begin();
    int ret = *it;
    first.erase(it);
    p[ret] = 0;
    return ret;
  }
  int pin = psort[pindex].second;
  while (p[pin] == 0) {
    pindex++;
    pin = psort[pindex].second;
  }
  p[pin] = 0;
  return pin;
}


int main() {
  int n, m;
  cin >> n >> m;
  vector<int> p(2 * n + 1);
  vector<pair<int, int>> psort(2 * n + 1);
  for (int i = 1; i <= 2 * n; i++) {
    cin >> p[i];
    psort[i] = {p[i], i};
  }

  sort(psort.begin(), psort.end(), greater<pair<int, int>>());
  vector<int> pairs(2 * n + 1, 0);
  set<int> first;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    pairs[a] = b;
    pairs[b] = a;
    if (p[a] > p[b]) first.insert(a);
    else first.insert(b);
  }

  int t;
  cin >> t;
  int opp;
  int pindex = 0;
  int rem = 2 * n;
  if (t == 1) {
    cout << pick(first, p, psort, pindex) << endl;
    cout.flush();
    rem--;
  }
  while (rem) {
    cin >> opp;
    p[opp] = 0;
    rem--;
    if (rem == 0) break;
    int comp = pairs[opp];
    if (p[comp] > 0) {
      first.erase(comp);
      first.erase(opp);
      p[comp] = 0;
      cout << comp << endl;
      cout.flush();
    }
    else {
      cout << pick(first, p, psort, pindex) << endl;
      cout.flush();
    }
    rem--;
  }
}
