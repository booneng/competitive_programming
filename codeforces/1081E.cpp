#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

static const int xmax = 200000;

int main() {
    cout << "HEL";
    int n;
    long long sq[100005];
    cin >> n;
    memset(sq, 0, (n + 1) * sizeof(long long));
    vector<pair<long long, long long>> v[xmax + 10];
    for (long long i = 1; i <= xmax; i++) {
        if (2 * i  + 1 > xmax) break;
        for (long long j = i + 1; j * j - i * i <= xmax; j++) {
            v[j * j - i * i].emplace_back(i, j);
        }
    }
    for (auto i : v[15]) cout << i.first << ' ' << i.second << endl;
    for (int i = 2; i <= n; i += 2) {
        long long x;
        cin >> x;
        for (auto t : v[x]) {
            if (sq[i - 2] < t.first) {
                sq[i - 1] = t.first;
                sq[i] = t.second;
                break;
            }
        }
        if (!sq[i - 1]) {
            cout << "No";
            return 0;
        }
    }

    cout << "Yes" << endl;
    for (int i = 1; i <= n; i++) {
        cout << (sq[i] * sq[i] - sq[i - 1] * sq[i - 1]) << ' ';
    }
}