#include <bits/stdc++.h>

using namespace std;

const int MAX_STORES = 41;
const int MAX_ITEMS = 101;
const int INF = 1000000001;

int num_items[MAX_STORES];
int savings[MAX_STORES];
bool must[MAX_STORES];
int items[MAX_STORES][MAX_ITEMS];

int covered[MAX_ITEMS];
bool skipped[MAX_ITEMS];

int num_covered;
int n, m, k;
int j;
int cost;


inline void cover_item(int i) {
  if (!covered[i]) num_covered++;
  covered[i]++;
}

inline void uncover_item(int i) {
  covered[i]--;
  if (!covered[i]) num_covered--;
}

inline void skip_item(int i) {
  skipped[i] = true;
}

inline void unskip_item(int i) {
  skipped[i] = false;
}

int brute_force() {
  if (j == m || k == 0) {
    return (num_covered == n ? cost : INF);
  }

  // take store
  int ans_take = INF;
  if (num_items[j] > 0) {

    for (int i = 0; i < num_items[j]; i++) {
      cover_item(items[j][i]);
    }
    
    cost -= savings[j];
    k--;
    j++;
    ans_take = brute_force();
    j--;
    k++;
    cost += savings[j];
    
    for (int i = 0; i < num_items[j]; i++) {
      uncover_item(items[j][i]);
    }
  }

  // skip store
  int ans_skip = INF;
  bool can_skip = true;
  for (int i = 0; i < num_items[j]; i++) {
    if (skipped[items[j][i]]) can_skip = false;
  }

  if (can_skip && !must[j]) {
    for (int i = 0; i < num_items[j]; i++) {
      skip_item(items[j][i]);
    }
    
    j++;
    ans_skip = brute_force();
    j--;

    for (int i = 0; i < num_items[j]; i++) {
      unskip_item(items[j][i]);
    }
  }

  return min(ans_skip, ans_take);
}


void add_item(int store1, int price1, int store2, int price2, int itemidx) {
  items[store1][num_items[store1]++] = itemidx;
  items[store2][num_items[store2]++] = itemidx;
  savings[store1] += max(0, price2 - price1);
  savings[store2] += max(0, price1 - price2);
}

int main() {
  cin >> n >> m >> k;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int a, p, b, q;
    cin >> a >> p >> b >> q;
    a--;
    b--;
    
    ans += max(p, q);
    add_item(a, p, b, q, i);
    if (a == b) must[a] = true;
  }

  ans += brute_force();
  if (ans >= INF) cout << -1;
  else cout << ans;
}
