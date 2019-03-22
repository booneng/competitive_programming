#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    double tmp = (-1 + sqrt(1 + 8LL * (a + b))) / 2;
    int highest = tmp;
    vector<int> p;
    vector<int> q;
    int cur = highest;
    while (cur > 0) {
        if (a > b) {
            a -= cur;
            p.push_back(cur);
        }
        else {
            b -= cur;
            q.push_back(cur);
        }
        cur--;
    }

    cout << p.size() << endl;
    for (int i : p) {
        cout << i << ' ';
    }

    cout << endl;
    cout << q.size() << endl;
    for (int i : q) {
        cout << i << ' ';
    }
}