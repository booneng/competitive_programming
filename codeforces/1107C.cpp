#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    string s;
    cin >> s;

    long long ans = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(a[0]);
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) {
            pq.push(a[i]);
            if (pq.size() > k) pq.pop();
        }
        else {
            while (!pq.empty()) {
                ans += pq.top();
                pq.pop();
            }
            pq.push(a[i]);
        }
    }

    while (!pq.empty()) {
        ans += pq.top();
        pq.pop();
    }

    cout << ans;
}