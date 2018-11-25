#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    long long n, m;
    cin >> n >> m;
    long long total = n * m;
    long long white = total / 2;
    long long black = total / 2;
    if (total % 2) white++;

    long long x1, y1, x2, y2;
    long long x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;
    long long area1 = (x2 - x1 + 1) * (y2 - y1 + 1);
    long long black1 = area1 / 2;
    long long white1 = area1 / 2;
    if (area1 % 2) {
      if (((x1 + y1) % 2) == 0) white1++;
      else black1++;
    }

    long long overlap = 0;
    long long overlapwhite = 0;
    long long overlapblack = 0;
    if (!(x1 > x4 || x3 > x2 || y1 > y4 || y3 > y2)) {
    // if (x3 <= x2 && y3 <= y2) {
      long long ox1 = max(x1, x3);
      long long ox2 = min(x2, x4);
      long long oy1 = max(y1, y3);
      long long oy2 = min(y2, y4);
      overlap = (ox2 - ox1 + 1) * (oy2 - oy1 + 1);
      overlapwhite = overlap / 2;
      overlapblack = overlap / 2;
      if (overlap % 2) {
	if (((ox1 + oy1) % 2) == 0) overlapwhite++;
	else overlapblack++;
      }
    }
    
    long long area2 = (x4 - x3 + 1) * (y4 - y3 + 1);
    long long black2 = area2 / 2;
    long long white2 = area2 / 2;
    if (area2 % 2) {
      if (((x3 + y3) % 2) == 0) white2++;
      else black2++;
    }

    white -= white1 + white2 - overlapwhite;
    white += area1 - overlap;
    black -= black1 + black2 - overlapblack;
    black += area2;
    cout << white << ' ' << black << endl;
    
  }

}
