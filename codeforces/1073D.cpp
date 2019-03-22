#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

int main() {
    int n;
    long long t;
    cin >> n >> t;

    list<int> a;
    int smallest = 1000000000;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        smallest = min(smallest, tmp);
        a.push_back(tmp);
    }

    long long ans = 0;

    while (t >= smallest) {
        long long cur_spent = 0;
        int bought = 0;

        // for (int i = 0; i < n; i++) {
        //     if (t >= a[i]) {
        //         cur_spent += a[i];
        //         t -= a[i];
        //         bought++;
        //     }
        // }

        for (list<int>::iterator it = a.begin(); it != a.end(); it++) {
            if (t >= *it) {
                cur_spent += *it;
                t -= *it;
                bought++;
            }
            else {
                it = a.erase(it);
                it--;
            }
        }

        ans += bought;

        ans += bought * (t / cur_spent);

        t %= cur_spent;
    }
    cout << ans;

}