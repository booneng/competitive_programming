#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
int r[200005];
int s[200005];
int s_count[200005];
vector<int> quarrels[200005];
vector<pair<int, int> > skill;

int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> r[i];
    skill.push_back(make_pair(r[i], i));
  }
  for (int i = 0; i < k; i++) {
    int x, y;
    cin >> x >> y;
    quarrels[x].push_back(y);
    quarrels[y].push_back(x);
  }
  
  sort(skill.begin(), skill.end());
  int prev_sk = -1;
  int prev_pro = 0;
  for (int i = 0; i < n; i++) {
    int sk = skill[i].first;
    int pro = skill[i].second;
    s_count[pro] = (prev_sk == sk) ? s_count[prev_pro] : i;
    s[pro] = sk;
    prev_pro = pro;
    prev_sk = sk;
  }

  for (int i = 1; i <= n; i++) {
    int ans = s_count[i];
    for (int j = 0; j < quarrels[i].size(); j++) {
      int pro = quarrels[i][j];
      if (s[pro] < s[i]) ans--;
    }
    cout << ans << ' ';
  }
}
