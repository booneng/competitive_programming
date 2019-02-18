#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<string> vars(n);
    vector<string> target(n);
    for (int i = 0; i < n; i++) {
        cin >> vars[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> target[i];
    }

    vector<int> diffs;
    for (int i = 0; i < n; i++) {
        if (vars[i] != target[i]) {
            diffs.push_back(i);
        }
    }

    int m = diffs.size();
    vector<int> left(m);
    vector<int> right(m);

    int len;
    for (int i = 0; i < m; i++) {
        int idx = diffs[i];
        for (int j = 0; j < vars[idx].size(); j++) {
            if (vars[idx][j] != target[idx][j]) {
                right[i] = j;
            }
        }
        for (int j = vars[idx].size() - 1; j >= 0; j--) {
            if (vars[idx][j] != target[idx][j]) {
                left[i] = j;
            }
        }
        len = right[i] - left[i] + 1;
    }

    for (int i = 0; i < m; i++) {
        int tmp = right[i] - left[i] + 1;
        if (tmp != len) {
            cout << "NO";
            return 0;
        }
    }

    while (true) {
        bool can = true;
        for (int i = 0; i < m; i++) {
            if (left[i] == 0) {
                can = false;
                break;
            }
        }
        if (!can) break;

        char check = vars[diffs[0]][left[0] - 1];
        for (int i = 0; i < m; i++) {
            if (vars[diffs[i]][left[i] - 1] != check) {
                can = false;
                break;
            }
        }

        if (!can) break;

        for (int i = 0; i < m; i++) {
            left[i]--;
        }
    }

    while (true) {
        bool can = true;
        for (int i = 0; i < m; i++) {
            if (right[i] == vars[diffs[i]].size() - 1) {
                can = false;
                break;
            }
        }
        
        if (!can) break;

        char check = vars[diffs[0]][right[0] + 1];
        for (int i = 0; i < m; i++) {
            if (vars[diffs[i]][right[i] + 1] != check) {
                can = false;
                break;
            }
        }

        if (!can) break;
        for (int i = 0; i < m; i++) {
            right[i]++;
        }
    }

    len = right[0] - left[0] + 1;
    string s = vars[diffs[0]].substr(left[0], len);
    string t = target[diffs[0]].substr(left[0], len);

    for (int i = 0; i < n; i++) {
        string &cur = vars[i];
        int pos = cur.find(s);
        if (pos != string::npos) {
            cur.replace(pos, s.size(), t);
        }
        if (cur != target[i]) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES" << endl;
    cout << s << endl;
    cout << t << endl;
}