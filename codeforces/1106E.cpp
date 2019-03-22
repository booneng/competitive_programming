#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstring>

using namespace std;

const int N = 100005;

struct Event {
    int d, w, t;

    bool operator<(const Event& e) const {
        return w > e.w || (w == e.w && d > e.d);
    }

    Event(int d, int w, int t)
        : d(d), w(w), t(t) {};
};

map<Event, int> event_count;
vector<Event> events[N];

int main() {
    int n, m, k;
    cin >> n >> m >> k;


    for (int i = 0; i < k; i++) {
        int s, t, d, w;
        cin >> s >> t >> d >> w;
        events[s].emplace_back(d, w, 1);
        events[t + 1].emplace_back(d, w, -1);
    }


    vector<Event> top_event(n + 1, Event(0, 0, 0));
    for (int i = 1; i <= n; i++) {
        for (Event& e : events[i]) {
            if (e.t == 1) {
                event_count[e]++;
            }
            else {
                event_count[e]--;
                if (event_count[e] == 0) {
                    event_count.erase(e);
                }
            }
        }

        if (event_count.empty()) {
            top_event[i] = {i, 0, 0};
        }
        else {
            top_event[i] = (*event_count.begin()).first;
        }
    }

    vector<vector<long long>> dp(m + 2, vector<long long>(n + 2, 4557430888798830399));
    dp[0][1] = 0;
    for (int j = 0; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            if (j > 0) dp[j][i] = min(dp[j - 1][i], dp[j][i]);
            dp[j + 1][i + 1] = min(dp[j + 1][i + 1], dp[j][i]);
            dp[j][top_event[i].d + 1] = min(dp[j][top_event[i].d + 1], dp[j][i] + top_event[i].w);
        }
    }
    cout << dp[m][n + 1];
}