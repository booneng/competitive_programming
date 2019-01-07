#include <iostream>

using namespace std;

int board[25][25];

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int r, c, w;
    cin >> r >> c >> w;
    int score = r * (c / w);
    score += w - 1;
    if (c % w) score++;
    cout << "Case #" << t << ": " << score << endl;
  }
  
}
