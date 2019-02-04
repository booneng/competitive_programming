#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cstring>
#include <climits>
#include <map>
#include <unordered_set>

using namespace std;

long long n, k, A, B;
vector<long long> a;

pair<long long, long long> find(long long left, long long right, long long pos) {
    if (pos == k || a[pos] > right) {
        return {A, pos};
    }

    if (left == right) {
        int cnt = 0;
        while (a[pos] == left) {
            pos++;
            cnt++;
        }
        return {B * cnt, pos};
    }

    long long mid = (left + right) / 2;
    pair<long long, long long> left_res = find(left, mid, pos);
    pair<long long, long long> right_res = find(mid + 1, right, left_res.second);
    long long cur = B * (right_res.second - pos) * (right - left + 1);
    return {min(cur, left_res.first + right_res.first), right_res.second};
}

int main() {

    cin >> n >> k >> A >> B;

    for (int i = 0; i < k; i++) {
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
    }

    sort(a.begin(), a.end());

    pair<long long, long long> ans = find(1LL, 1LL << n, 0LL);
    cout << ans.first;

}