#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class IdenticalBags {

    bool check(long long nbags, vector<long long>& candy, long long bagSize) {
        long long size = 0;
        for (int i = 0; i < candy.size(); i++) {
            size += candy[i] / nbags;
            if (size >= bagSize) return true;
        }
        return false;
    }

public:
    long long makeBags(vector<long long> candy, long long bagSize) {
        long long left = 1;
        long long right = 1000000000000000001;

        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (check(mid, candy, bagSize)) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return right;
    }
};

int main() {
    IdenticalBags sol;
    cout << sol.makeBags({10, 11, 12}, 3) << endl;
}