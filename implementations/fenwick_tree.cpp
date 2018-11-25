#include <bits/stdc++.h>

using namespace std;

class FenwickTree {

private:
  int size;
  vector<int> arr;

public:

  FenwickTree(int n) : size(n), arr(n + 1, 0) {}

  void update(int i, int delta) {
    while (i <= size) {
      arr[i] += delta;
      i += i & -i;
    }
  }

  int sum(int i) {
    int ret = 0;
    while (i > 0) {
      ret += arr[i];
      i -= i & -i;
    }
    return ret;
  }

  int rangeSum(int i, int j) {
    return sum(j) - sum(i - 1);
  }
};

int main() {

  // array = [1, 5, 1, 3, 15, 8, 9, 10, 100, 6]
  FenwickTree fw(10);
  fw.update(1, 1);
  fw.update(2, 5);
  fw.update(3, 1);
  fw.update(4, 3);
  fw.update(5, 15);
  fw.update(6, 8);
  fw.update(7, 9);
  fw.update(8, 10);
  fw.update(9, 100);
  fw.update(10, 6);
  for (int i = 1; i <= 10; i++) {
    cout << fw.sum(i) << endl;
  }
}
