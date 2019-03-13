#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

int a[500005];
int b[500005];

int main() {
    int m, k, n, s;
    cin >> m >> k >> n >> s;

    for (int i = 0; i < m; i++) cin >> a[i];
    for (int i = 0; i < s; i++) cin >> b[i];

    map<int, int> schematic;
    int types = 0;
    for (int i = 0; i < s; i++) {
        if (schematic[b[i]] == 0) types++;
        schematic[b[i]]++;
    }

    map<int, int> cnts;
    int min_left = -1;
    int min_right = -1;
    int shortest = 500005;
    int left = 0;
    for (int right = 0; right < m; right++) {
        cnts[a[right]]++;
        if (cnts[a[right]] == schematic[a[right]]) {
            types--;
            if (types == 0) {
                while (left <= right && types == 0) {
                    cnts[a[left]]--;
                    if (cnts[a[left]] < schematic[a[left]]) types++;
                    left++;
                }

                int start = (left - 1) / k * k;
                int end = start + k - 1;
                int segment = (left - 1) / k;
                if (segment >= n) {
                    start = (n - 1) * k;
                }
                int d = right - start + 1;
                if (m - d + k >= n * k) {
                    int removal = max(0, d - k);
                    cout << removal << endl;
                    for (int i = start; i <= right; i++) {
                        if (!removal) break;
                        if (schematic[a[i]]) {
                            schematic[a[i]]--;
                        }
                        else {
                            cout << i + 1 << ' ';
                            removal--;
                        }
                    }
                    return 0;
                }
            }
        }
    }
    cout << -1;

}