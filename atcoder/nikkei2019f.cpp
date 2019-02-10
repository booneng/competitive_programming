#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<long long, long long>> tmp(n);
    map<int, int> cnts;

    for (int i = 0; i < n; i++) {
        long long c, v;
        cin >> c >> v;
        tmp[i] = {c, v * 2};
        cnts[c]++;
    }

    vector<pair<long long, long long>> jewels;

    for (int i = 0; i < n; i++) {
        if (cnts[tmp[i].first] > 1) {
            jewels.emplace_back(tmp[i].first, tmp[i].second);
        }
    }

    sort(jewels.begin(), jewels.end(), greater<pair<long long, long long>>());


    map<int, long long> top_two_sum;
    map<int, long long> top_three_sum;
    map<int, long long> top_one_sum;

    for (int i = 0; i < n; i++) {
        int color = jewels[i].first;
        top_one_sum[color] = jewels[i].second;
        top_two_sum[color] = jewels[i].second + jewels[i + 1].second;
        if (i < n - 2 && jewels[i + 2].first == color) {
            top_three_sum[color] = jewels[i].second + jewels[i + 1].second + jewels[i + 2].second;
        }
        int avg = (jewels[i].second + jewels[i + 1].second) / 2;
        jewels[i].second = avg;
        jewels[i + 1].second = avg;
        while (jewels[i] == jewels[i + 1]) {
            i++;
        }
    }
    
    for (int i = 0; i < n; i++) {
        jewels[i] = {jewels[i].second, jewels[i].first};
    }

    sort(jewels.begin(), jewels.end(), greater<pair<int, int>>());

    bool used[100005];
    memset(used, false, sizeof(used));

    long long ans = 0;
    // value of used not in top two
    set<long long> P;
    // sum of used top two
    set<long long> Q;
    for (int i = 0; i < n - 1; i++) {
        ans += jewels[i].first;
        if (!used[jewels[i].second]) {
            ans += jewels[i + 1].first;
            i++;
            used[jewels[i].second] = true;
            Q.insert(jewels[i].first * 2);
        }
        else {
            P.insert(jewels[i].first);
        }
    }

    if (used[jewels[n - 1].second]) {
        ans += jewels[n - 1].first;
    }
    else {
        if (!P.empty()) {
            ans -= *P.rbegin();
            ans += jewels[n].second * 2;
        }


    }

    cout << ans / 2;
}