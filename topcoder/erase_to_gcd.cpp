#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class EraseToGCD {

const int mod = 1000000007;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

public:
    int countWays(vector<int> S, int goal) {
        int oldways[1001];
        memset(oldways, 0, sizeof(oldways));

        for (int s : S) {
            int newways[1001];
            memcpy(newways, oldways, sizeof(newways));
            for (int d = 1; d <= 1000; d++) {
                int g = gcd(d, s);
                newways[g] = (newways[g] + oldways[d]) % mod;
            }
            newways[s] = (newways[s] + 1) % mod;
            memcpy(oldways, newways, sizeof(oldways));
        }
        return oldways[goal];
    }
    
};