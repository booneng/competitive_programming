#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  int costs[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> costs[i];
  }
  int q;
  cin >> q;
  vector<int> ends[n + 1];
  int lefts[q];
  vector<int> ans(q);
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    ends[r].push_back(i);
    lefts[i] = l;
  }
  
  vector<int> last_for_bit(30);
  vector<int> position(30);
  for (int r = 1; r <= n; r++) {
    int x = costs[r];
    int p = r;
    for (int b = 20; b >= 0; b--) {
      if ((1 << b) & x) {
        if (!last_for_bit[b]) {
          last_for_bit[b] = x;
          position[b] = p;
          break;
        }
        if (position[b] < p) {
          swap(last_for_bit[b], x);
          swap(position[b], p);
        }
        x ^= last_for_bit[b];
      }
    }

    for (int i : ends[r]) {
      for (int b = 20; b >= 0; b--) {
        if (lefts[i] <= position[b]) {
          ans[i] = max(ans[i], ans[i] ^ last_for_bit[b]);
        }
      }
    }
  }

  for (int i = 0; i < q; i++) {
    cout << ans[i] << endl;
  }
}