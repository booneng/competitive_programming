#include <vector>
#include <map>
#include <set>
#include <iostream>

using namespace std;

class SimulateBST {

public:
    int checksum(int n, vector<int> Sprefix, int a, int m) {
        map<int, int> depths;
        map<int, int> ranges;


        long long mod = 1000000007;

        long long ans = 0;
        long long power = 100000;
        vector<int> S(n);
        S[0] = Sprefix[0];
        depths[S[0]] = 0;
        ranges[S[0]] = 0;
        ranges[-1] = 0;
        ranges[m] = 0;
        for (int i = 1; i < n; i++) {

            if (i < Sprefix.size()) {
                S[i] = Sprefix[i];
            }
            else {
                S[i] = ((long long)a * S[i - Sprefix.size()] + depths[S[i - 1]] + 1) % m;
            }
            
            if (!depths.count(S[i])) {
                auto it = ranges.upper_bound(S[i]);
                it--;
                int depth = it->second;
                ranges[S[i]] = depth + 1;
                depths[S[i]] = depth + 1;
                ranges[it->first]++;
            }
            ans = (ans + depths[S[i]] * power) % mod;
            power = (power * 100000) % mod;
        }
        return ans;
    }
};

int main() {
    SimulateBST sol;
    cout << sol.checksum(9, {40, 20, 60, 70, 80, 30, 10, 30, 90}, 0, 100) << endl;
}