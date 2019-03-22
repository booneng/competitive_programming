#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
#include <cassert>

using namespace std;

struct Event {
    int dir;
    long long time;
};

struct Node {
    int startPos;
    long long startTime;

    long long GetTimeAt(int pos) const {
        return startTime + abs(pos - startPos);
    }

    bool operator<(const Node& n) const {
        return startTime < n.startTime;
    }

    bool operator==(const Node& n) const {
        return startTime == n.startTime;
    }
};


const unsigned int SIZE = 1000005;

vector<Event> events[SIZE];
set<Node> nodes;
long long lastTouched[SIZE];

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int h, w, n;

void UpdateLastTouched(int x, int y, int pos, int dir) {
    for (auto& e : events[x + h * y]) {
        if (e.dir == dir) {
            nodes.insert({pos, e.time});
        }
    }

    if (nodes.size()) {
        lastTouched[x + h * y] = max(lastTouched[x + h * y], (nodes.rbegin())->GetTimeAt(pos));
    }

    for (auto& e : events[x + h * y]) {
        if (e.dir == -dir - 1) {
            nodes.erase({1, e.time});
        }
    }
}


int main() {
    cin >> h >> w >> n;
    memset(lastTouched, 0, sizeof(int) * h * w);
    vector<string> grid(h);
    for (int i = 0; i < h; i++) {
        cin >> grid[i];
    }
    reverse(grid.begin(), grid.end());

    int x = 0;
    int y = 0;
    long long timer = 1;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int dir;
        if (s == "up") {
            dir = 0;
        }
        else if (s == "down") {
            dir = 2;
        }
        else if (s == "right") {
            dir = 1;
        }
        else {
            dir = 3;
        }
        int len;
        cin >> len;
        events[x + h * y].push_back({dir, timer});
        x += dx[dir] * len;
        y += dy[dir] * len;
        events[x + h * y].push_back({-dir - 1, timer});
        timer += len;
    }

    // right
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            UpdateLastTouched(i, j, j, 1);
        }
        assert(nodes.empty());
    }

    //left
    for (int i = 0; i < h; i++) {
        for (int j = w - 1; j >= 0; j--) {
            UpdateLastTouched(i, j, j, 3);
        }
        assert(nodes.empty());
    }

    //up
    for (int j = 0; j < w; j++) {
        for (int i = 0; i < h; i++) {
            UpdateLastTouched(i, j, i, 0);
        }
        assert(nodes.empty());
    }

    //down
    for (int j = 0; j < w; j++) {
        for (int i = h - 1; i >= 0; i--) {
            UpdateLastTouched(i, j, i, 2);
        }
        assert(nodes.empty());
    }


    bool can = true;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (lastTouched[i + h * j] == 0 && grid[i][j] == '#') {
                can = false;
                break;
            }
        }
        if (!can) break;
    }

    long long earliest = 0;
    long long latest = timer;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            // cout << lastTouched[i + w * j] << ' ';
            if (lastTouched[i + h * j] == 0) continue;
            if (grid[i][j] == '.') {
                latest = min(latest, lastTouched[i + h * j] - 1);
            }
            else {
                earliest = max(earliest, lastTouched[i + h * j]);
            }
        }
        // cout << endl;
    }
    if (earliest > latest) can = false;

    if (can) cout << earliest << ' ' << latest;
    else cout << -1 << ' ' << -1;
}