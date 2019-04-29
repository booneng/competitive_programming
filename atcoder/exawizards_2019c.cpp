#include <iostream>

using namespace std;

const int N = 200005;
const int Q = 200005;

string s;
int n, q;

char letters[Q];
char dir[Q];

int main() {
    cin >> n >> q;
    cin >> s;
    for (int i = 0; i < q; i++) {
        cin >> letters[i] >> dir[i];
    }

    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        int pos = mid;
        for (int i = 0; i < q; i++) {
            if (letters[i] == s[pos]) {
                if (dir[i] == 'L') pos--;
                else pos++;
            }
            if (pos == -1) {
                break;
            }
        }

        if (pos == -1) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    int ans_left = right;

    left = 0;
    right = n - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        int pos = mid;
        for (int i = 0; i < q; i++) {
            if (letters[i] == s[pos]) {
                if (dir[i] == 'L') pos--;
                else pos++;
            }
            if (pos == n || pos == -1) {
                break;
            }
        }

        if (pos == n) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    int ans_right = left;

    cout << n - (ans_left + 1) - (n - ans_right);

}