#include <bits/stdc++.h>

using namespace std;

int n, t;

void solve() {
    string s = "AAAAA";
    map<string, int> cnts;
    map<string, int> order;
    int idx = 0;
    for (int i = 0; i < 50; i++) {
        cout << s << endl;
        cout.flush();
        string res;
        cin >> res;
        if (res == "-1") exit(0);
        if (!cnts.count(s + res)) {
            order[s + res] = idx++;
        }
        cnts[s + res]++;
        s = res;
    }

    int most = 0;
    for (auto it : cnts) {
        if (it.second > most || (it.second == most && order[it.first] > order[s])) {
            most = it.second;
            s = it.first;
        }
    }

    string hi = s.substr(0, 5);
    string low = s.substr(5);
    string random = "AAAAA";
    while (random == low || random == hi) {
        random[0]++;
    }

    for (int i = 0; i < 25; i++) {
        cout << hi << endl;
        cout.flush();
        cin >> s;
        if (s == "-1") exit(0);
        cout << random << endl;
        cout.flush();
        cin >> s;
        if (s == "-1") exit(0);
    }

    cout << hi << endl;
    cout.flush();
}

int main() {
    cin >> t >> n;

    for (int i = 1; i <= t; i++) {
        solve();
    }
}
