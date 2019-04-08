#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> songs(n);

    for (int i = 0; i < n; i++) {
        cin >> songs[i].second >> songs[i].first;
    }

    sort(songs.begin(), songs.end());
    multiset<int> lengths;
    long long sum = 0;
    long long ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        lengths.insert(songs[i].second);
        sum += songs[i].second;
        while (lengths.size() > k) {
            auto it = lengths.begin();
            sum -= *it;
            lengths.erase(it);
        }

        ans = max(ans, sum * songs[i].first);
    }

    cout << ans;
}