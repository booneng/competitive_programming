#include <iostream>
#include <vector>
#include <bitset>
#include <map>
#include <cstring>
#include <algorithm>

using namespace std;

static const int mod = 1000000007;

static vector<int> primes;
static vector<int> inverse_primes;

int mul(int a, int b) {
    return (1LL * a * b) % mod;
}

int fpow(int a, int p) {
    int res = 1;
    while (p) {
        if (p & 1) {
            res = mul(res, a);
        }

        p >>= 1;
        a = mul(a, a);
    }
    return res;
}

int inv(int a) {
    return fpow(a, mod - 2);
}



class SegmentTree {

private:
    int n;
    vector<int> product_tree;
    vector<bitset<70>> prime_tree;
    vector<int> hi;
    vector<int> lo;
    vector<int> delta;
    vector<bitset<70>> delta_primes;


    void prop(int i) {
        if (delta[i] > 1) {
            product_tree[i] = mul(product_tree[i], fpow(delta[i], hi[i] - lo[i] + 1));
            if (hi[i] > lo[i]) {
                delta[2 * i + 1] = mul(delta[2 * i + 1], delta[i]);
                delta[2 * i + 2] = mul(delta[2 * i + 2], delta[i]);
            }
            delta[i] = 1;
        }
        prime_tree[i] |= delta_primes[i];
        if (hi[i] > lo[i]) {
            delta_primes[2 * i + 1] |= delta_primes[i];
            delta_primes[2 * i + 2] |= delta_primes[i];
        }
        delta_primes[i].reset();
    }

    void addValue(int i, int left, int right, int val, bitset<70>& prime_mask) {
        if (left > hi[i] || right < lo[i]) {
            return;
        }

        prop(i);

        if (left <= lo[i] && right >= hi[i]) {
            delta[i] = val;
            delta_primes[i] = prime_mask;
            return;
        }

        addValue(2 * i + 1, left, right, val, prime_mask);
        addValue(2 * i + 2, left, right, val, prime_mask);
        prime_tree[i] = prime_tree[2 * i + 1] | delta_primes[2 * i + 1] | prime_tree[2 * i + 2] | delta_primes[2 * i + 2];
        product_tree[i] = mul(product_tree[i], fpow(val, min(right, hi[i]) - max(left, lo[i]) + 1));
    }

    int getProduct(int i, int left, int right) {
        if (left > hi[i] || right < lo[i]) {
            return 1;
        }

        prop(i);

        if (left <= lo[i] && right >= hi[i]) {
            return product_tree[i];
        }

        int left_val = getProduct(2 * i + 1, left, right);
        int right_val = getProduct(2 * i + 2, left, right);
        return mul(left_val, right_val);
    }

    bitset<70> getPrimes(int i, int left, int right) {
        if (left > hi[i] || right < lo[i]) {
            return bitset<70>();
        }

        if (left <= lo[i] && right >= hi[i]) {
            return prime_tree[i];
        }

        bitset<70> left_primes = getPrimes(2 * i + 1, left, right);
        bitset<70> right_primes = getPrimes(2 * i + 2, left, right);
        bitset<70> res = left_primes | right_primes;
        return res;
    }

    void init(vector<int>& nums, int i, int left, int right) {
        lo[i] = left;
        hi[i] = right;
        
        if (left == right) {
            product_tree[i] = nums[left];
            for (int j = 0; j < primes.size(); j++) {
                int p = primes[j];
                if (nums[left] % p == 0) {
                    prime_tree[i].set(j);
                }
            }
            return;
        }

        int mid = (left + right) / 2;

        init(nums, 2 * i + 1, left, mid);
        init(nums, 2 * i + 2, mid + 1, right);
        product_tree[i] = mul(product_tree[2 * i + 1], product_tree[2 * i + 2]);
        prime_tree[i] = prime_tree[2 * i + 1] | prime_tree[2 * i + 2];
    }

public:
    SegmentTree(vector<int>& nums) 
        : n(nums.size())
    {
        product_tree = vector<int>(4 * n, 1);
        prime_tree = vector<bitset<70>>(4 * n);
        hi = vector<int>(4 * n);
        lo = vector<int>(4 * n);
        delta = vector<int>(4 * n, 1);
        delta_primes = vector<bitset<70>>(4 * n);
        init(nums, 0, 0, n - 1);
    }

    int totient(int left, int right) {
        int product = getProduct(0, left, right);
        bitset<70> prime_mask = getPrimes(0, left, right);
        for (int i = 0; i < primes.size(); i++) {
            if (prime_mask[i]) {
                product = mul(product, mul(primes[i] - 1, inverse_primes[i]));
            }
        }
        return product;
    }

    void addValue(int left, int right, int val) {
        bitset<70> prime_mask;
        for (int i = 0; i < primes.size(); i++) {
            int prime = primes[i];
            if (val % prime == 0) {
                prime_mask.set(i);
            }
        }

        addValue(0, left, right, val, prime_mask);
    }

};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    bool check[305];
    memset(check, true, sizeof(check));
    for (int i = 2; i < 301; i++) {
        if (check[i]) {
            primes.push_back(i);
            inverse_primes.push_back(inv(i));
            for (int j = i * i; j < 301; j += i) {
                check[j] = false;
            }
        }
    }

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    SegmentTree st(nums);

    for (int i = 0; i < q; i++) {
        string s;
        cin >> s;
        if (s == "MULTIPLY") {
            int l, r, val;
            cin >> l >> r >> val;
            l--;
            r--;
            st.addValue(l, r, val);
        }
        else {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            cout << st.totient(l, r) << endl;
        }
    }
}
