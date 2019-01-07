#include <iostream>

using namespace std;

int r, c, n;


int remove_tenants(int &k, int max_remove, int remove_cost) {
  int removed = min(k, max_remove);
  k -= removed;
  return removed * remove_cost;
}

int get_score(int all, int corners, int inners) {
  int sides = all - corners - inners;
  int k = r * c - n;
  int unhappiness = r * c * 2 - r - c;
  unhappiness -= remove_tenants(k, inners, 4);
  unhappiness -= remove_tenants(k, sides, 3);
  unhappiness -= remove_tenants(k, corners, 2);
  return unhappiness;
}

int min_unhappiness() {
  if (n <= (r * c + 1) / 2) return 0;
  if (r == 1) {
    int k = r * c - n;
    int unhappiness = c - 1;
    int remove_cost = 2;
    return unhappiness - k * remove_cost;
  }

  if (r % 2 && c % 2) {
    int pattern1 = get_score((r * c + 1) / 2, 4, ((r - 2) * (c - 2) + 1) / 2);
    int pattern2 = get_score((r * c) / 2, 0, ((r - 2) * (c - 2)) / 2);
    return min(pattern1, pattern2);
  }

  return get_score((r * c + 1) / 2, 2, ((r - 2) * (c - 2) + 1) / 2);
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cin >> r >> c >> n;
    if (r > c) swap(r, c);
    cout << "Case #" << t << ": " << min_unhappiness() << endl;
  }

}
