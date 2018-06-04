#include <iostream>
#include <vector>

using namespace std;

int r, b;
const int MAX = 502;
const int inf = (int) 1e9;
const int MAGIC = 31;
vector< vector<int> > dp(MAX, vector<int>(MAX, -inf));

int main() {
  dp[0][0] = 0;
  for (int x = 0; x <= MAGIC; x++) {
    for (int y = 0; y <= MAGIC; y++) {
      if (x + y == 0) {
        continue;
      }
      for (int i = MAX - 1 - x; i >= 0; i--) {
        for (int j = MAX - 1 - y; j >= 0; j--) {
          dp[i + x][j + y] = max(dp[i + x][j + y], dp[i][j] + 1);
        }
      }
    }
  }

  int t;
  cin >> t;
  
  for (int i = 1; i <= t; i++) {
    cin >> r >> b;
    cout << "Case #" << i << ": " << dp[r][b] << endl;
  }

}
