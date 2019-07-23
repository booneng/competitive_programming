#include <bits/stdc++.h>

using namespace std;

string solve() {
    int n;
    cin >> n;
    vector<string> bots(n);
    int highest = 0;
    for (int i = 0; i < n; i++) {
        cin >> bots[i];
        highest = max((int)bots[i].size(), highest);
    }

    string ans;
    for (int i = 0; i <= highest; i++) {
        bool has_r = false, has_p = false, has_s = false;
        for (auto& bot : bots) {
            int sz = bot.size();
            if (bot[i % sz] == 'R') has_r = true;
            else if (bot[i % sz] == 'P') has_p = true;
            else has_s = true;
        }

        if (has_r && has_p && has_s) return "IMPOSSIBLE";
        vector<string> newbots;
        char pick;
        if (has_r) {
            pick = 'P';
            if (has_s) pick = 'R';
        }
        else {
            pick = 'S';
            if (!has_p) pick = 'R';
        }
        ans += pick;
        for (auto& bot : bots) {
            int sz = bot.size();
            if (bot[i % sz] == pick) newbots.push_back(bot);
        }
        bots = newbots;
        if (bots.empty()) return ans;
    }

    return ans;


}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": " << solve() << endl;
    }
}