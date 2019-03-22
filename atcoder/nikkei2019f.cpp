#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<pair<long long, int>> jewels(n);
    vector<vector<long long>> colors(k + 1);

    for (int i = 0; i < n; i++) {
        long long c, v;
        cin >> c >> v;
        colors[c].push_back(v * 2);
    }

    multiset<long long> top_one;
    multiset<long long> top_two;
    multiset<long long> top_three;
    for (int color = 1; color <= k; color++) {
        sort(colors[color].begin(), colors[color].end(), greater<long long>());
        int nc = colors[color].size();
        top_two.emplace(colors[color][0] + colors[color][1]);
        if (nc > 2) {
            top_three.emplace(colors[color][0] + colors[color][1] + colors[color][2]);
        }
        long long avg = (colors[color][0] + colors[color][1]) / 2;
        jewels.emplace_back(avg, color);
        jewels.emplace_back(avg, color);
        for (int i = 2; i < nc; i++) {
            jewels.emplace_back(colors[color][i], color);
        }
    }

    sort(jewels.begin(), jewels.end(), greater<pair<long long, int>>());


    long long sum = 0;
    vector<int> cnts(k + 1, 0);
    long long min_pair = 1LL << 60;
    long long min_one = 1LL << 60;
    for (int i = 0; i < n; i++) {
        long long color = jewels[i].second;
        long long value = jewels[i].first;
        long long ans = -2;
        if (cnts[color] == 0) {
            if (!top_one.empty()) {
                ans = max(ans, sum + *top_one.rbegin());
            }

            if (!top_two.empty()) {
                ans = max(ans, sum - min_one + *top_two.rbegin());
            }

            if (!top_three.empty()) {
                ans = max(ans, sum - min_pair + *top_three.rbegin());
            }

            
            // erase from top two and three
            top_two.erase(top_two.find(colors[color][0] + colors[color][1]));
            if (colors[color].size() > 2) {
                top_three.erase(top_three.find(colors[color][0] + colors[color][1] + colors[color][2]));
            }
        }
        else {
            ans = sum + value;
            if (cnts[color] == 1) {
                
                for (int i = 2; i < colors[color].size(); i++) {
                    top_one.emplace(colors[color][i]);
                }
                min_pair = min(min_pair, colors[color][0] + colors[color][1]);
            }
            else {
                top_one.erase(top_one.find(value));
                min_one = min(min_one, value);
            }
        }
        cnts[color]++;
        sum += value;
        cout << ans / 2 << endl;
    }
}