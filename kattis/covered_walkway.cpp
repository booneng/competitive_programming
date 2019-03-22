#include <iostream>
#include <vector>
#include <deque>

using namespace std;

struct Sol {
    long long x;
    long long best;

    long long GetCost(long long y) {
        long long d = x - y;
        return d * d + best;
    }

    double GetCost(double y) {
        double d = x - y;
        return d * d + best;
    }

    double To(Sol rhs) {
        double lo = rhs.x;
        double hi = rhs.x;

        while (GetCost(hi) < rhs.GetCost(hi)) {
            lo = hi + 1;
            hi *= 2;
        }

        while (hi - lo > 1e-3) {
            double mid = (lo + hi) / 2;
            if (GetCost(mid) >= rhs.GetCost(mid)) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }

        return hi;
    }
};

int main() {
    long long n, c;
    cin >> n >> c;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    deque<Sol> dq;

    long long best = 0;
    for (int i = 0; i < n; i++) {
        Sol cur({a[i], best + c});
        while (dq.size() >= 2 && dq[dq.size() - 2].To(dq[dq.size() - 1]) >= dq[dq.size() - 2].To(cur)) {
            dq.pop_back();
        }

        dq.push_back(cur);

        while (dq.size() >= 2 && dq[0].GetCost(a[i]) >= dq[1].GetCost(a[i])) {
            dq.pop_front();
        }
        best = dq.front().GetCost(a[i]);
    }
    cout << best;
}