#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int dx[100005];
int dy[100005];

int main() {
    memset(dx, 0, sizeof(dx));
    memset(dy, 0, sizeof(dy));
    long long x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    x2 -= x1;
    y2 -= y1;

    int n;
    cin >> n;
    string s;
    cin >> s;

    for (int i = 1; i <= n; i++) {
        dx[i] = dx[i - 1];
        dy[i] = dy[i - 1];
        if (s[i - 1] == 'U') {
            dy[i]++;
        }
        else if (s[i - 1] == 'D') {
            dy[i]--;
        }
        else if (s[i - 1] == 'R') {
            dx[i]++;
        }
        else {
            dx[i]--;
        }
    }

    long long left = 0;
    long long right = 1LL << 60;

    while (left <= right) {
        long long mid = (left + right) / 2;
        long long x = dx[n] * (mid / n) + dx[mid % n];
        long long y = dy[n] * (mid / n) + dy[mid % n];

        long long dist = abs(x2 - x) + abs(y2 - y);
        if (dist <= mid) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    if (right == 1LL << 60) cout << -1;
    else cout << left;
}