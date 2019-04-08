#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 1; j < m; j++) {
            matrix[i][j] += matrix[i][j - 1];
        }
    }

    int ans = 0;
    for (int left = 0; left < m; left++) {
        for (int right = left; right < m; right++) {
            vector<int> arr(n);
            for (int i = 0; i < n; i++) {
                arr[i] = matrix[i][right];
                if (left > 0) arr[i] -= matrix[i][left - 1];
            }
            int cur = 0;
            for (int i = 0; i < n; i++) {
                cur += arr[i];
                if (cur <= 0) cur = 0;
                ans = max(ans, cur);
            }
        }
    }

    cout << ans;
}