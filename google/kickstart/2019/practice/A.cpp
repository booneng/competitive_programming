#include <iostream>

using namespace std;

void solve() {
    int left, right;
    cin >> left >> right;
    
    left++;
    int n;
    cin >> n;
    
    while (left <= right) {
        int mid = (left + right) / 2;
        cout << mid << endl;
        cout.flush();
        string res;
        cin >> res;
        if (res == "CORRECT") return;
        else if (res == "TOO_SMALL") {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}