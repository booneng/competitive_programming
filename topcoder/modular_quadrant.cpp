#include <iostream>
#include <algorithm>

using namespace std;

class ModularQuadrant {

public:
    long long cnt(int r, int c) {
        if (r > c) swap(r, c);
        long long x = r - r % 3;
        long long y = c - x;
        y -= y % 3;
        cout << x << ' ' << y << endl;
        return 4 * x / 3 + x * x + (r % 3 == 2) * (x + 1) + y * r + r * (c % 3 == 2);
    }

    long long sum(int r1, int r2, int c1, int c2) {
        return cnt(r2 + 1, c2 + 1) - cnt(r1, c2 + 1) - cnt(r2 + 1, c1) + cnt(r1, c1);
    }
};

int main() {
    ModularQuadrant sol;
    cout << sol.cnt(5, 5);
}