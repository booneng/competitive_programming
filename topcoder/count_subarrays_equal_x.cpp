#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

class CountSubarrays {

    static const int mod = 744444499;

    int inv(long long x) {
        int p = mod - 2;
        long long res = 1;
        while (p) {
            if (p & 1) {
                res = (res * x) % mod;
            }
            x = (x * x) % mod;
            p >>= 1;
        }
        return res;
    }

public:
    long long count(vector<int> Aprefix, int n, int a, int b, int m, int x) {
        vector<int> A(n);
        for (int i = 0; i < Aprefix.size(); i++)
            A[i] = Aprefix[i];
        for (int i = Aprefix.size(); i < n; i++)
            A[i] = ((long long)A[i - Aprefix.size()] * a + b) % m;

        vector<vector<int>> subarrays;
        vector<int> cur;
        for (int i = 0; i < n; i++) {
            if (A[i] == 0) {
                if (cur.size()) subarrays.push_back(cur);
                cur.clear();
            }
            else {
                cur.push_back(A[i]);
            }
        }

        if (cur.size()) subarrays.push_back(cur);

        if (x == 0) {
            long long total_subarrays = (long long)n * (n + 1) / 2;
            for (auto& subarray : subarrays) {
                long long num = subarray.size();
                total_subarrays -= num * (num + 1) / 2;
            }
            return total_subarrays;
        }

        int inv_x = inv(x);
        long long ans = 0;
        for (auto& subarray : subarrays) {
            map<int, int> cnts;
            cnts[1]++;
            long long cur = 1;
            for (int i = 0; i < subarray.size(); i++) {
                cur = (cur * subarray[i]) % mod;
                int comp = (cur * inv_x) % mod;
                ans += cnts[comp];
                cnts[cur]++;
            }
        }
        return ans;
    }
};

int main() {
    CountSubarrays sol;
    cout << sol.count({2, 1, 2}, 3, 5, 7, 11, 2) << endl;
}