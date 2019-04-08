#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

string solve() {
    int n, l;
    cin >> n >> l;
    
    vector<int> nums(l);
    for (int i = 0; i < l; i++) {
        cin >> nums[i];
    }

    int p1 = gcd(nums[0], nums[1]);
    int p2 = nums[0] / p1;

    vector<int> primes;
    primes.push_back(p1);

    bool can = true;
    for (int i = 0; i < l; i++) {
        if (nums[i] % p1 || p1 == 0) {
            can = false;
            break;
        }
        p1 = nums[i] / p1;
        primes.push_back(p1);
    }

    if (!can) {
        primes = vector<int>();
        primes.push_back(p2);
        for (int i = 0; i < l; i++) {
            p2 = nums[i] / p2;
            primes.push_back(p2);
        }
    }

    set<int> ordered;
    for (int i : primes) ordered.insert(i);

    map<int, int> pos;
    for (int i : ordered) {
        pos[i] = pos.size() - 1;
    }

    string s;
    for (int i : primes) {
        s += 'A' + pos[i];
    }
    
    return s;
}

int main() {
    int t;
    
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": " << solve() << endl;
    }
}