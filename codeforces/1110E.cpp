#include <iostream>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[100005], b[100005];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    bool can = a[0] == b[0];
    map<int, int> diffs;
    for (int i = 0; i < n - 1; i++) {
        diffs[a[i + 1] - a[i]]++;
    }

    for (int i = 0; i < n - 1; i++) {
        diffs[b[i + 1] - b[i]]--;
        if (diffs[b[i + 1] - b[i]] < 0) {
            can = false;
            break;
        }
    }

    if (can) cout << "Yes";
    else cout << "No";
}