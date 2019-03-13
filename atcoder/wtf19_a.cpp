#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> ans;
    int last = -1;
    int pos = 0;
    for (int i = 0; i <= k; i++) {
        int mi = 1e9;
        for (int j = 0; j < n; j++) {
            if (j != last && a[j] < mi) {
                mi = a[j];
                pos = j;
            }
        }

        for (int j = 0; j < n; j++) {
            if (j != last && j != pos) {
                ans.push_back(j);
                a[j]--;
            }
        }

        last = pos;
        ans.push_back(last);
        a[last]--;
        if (a[last] < 0) {
            cout << -1;
            return 0;
        }
    }

    cout << ans.size() << endl;
    for (int i : ans) cout << i + 1 << ' ';
}
