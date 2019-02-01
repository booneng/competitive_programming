#include <iostream>
#include <string>

using namespace std;

string matrix[505];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> matrix[i];
    }

    int ans = 0;
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            if (matrix[i][j] == 'X') {
                if (matrix[i - 1][j - 1] == 'X' &&
                    matrix[i - 1][j + 1] == 'X' &&
                    matrix[i + 1][j - 1] == 'X' &&
                    matrix[i + 1][j + 1] == 'X') {
                        ans++;
                    }
            }
        }
    }
    cout << ans;
}