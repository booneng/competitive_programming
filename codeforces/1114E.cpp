#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <numeric>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}



int main() {
    int n;
    cin >> n;
    random_device rd;
    mt19937 gen(rd());
    int left = 0;
    int right = 1000000000;

    int q = 0;
    while (left < right) {
        int mid = (left + right) / 2;
        cout << "> " << mid << endl;
        cout.flush();
        int res;
        cin >> res;
        if (res) {
            left = mid + 1;
        }
        else {
            right = mid;
        }
        q++;
    }

    int max_value = right;
    vector<int> elems;
    vector<int> indices(n);
    iota(indices.begin(), indices.end(), 1);
    for (int i = 0; i < n && q < 60; i++, q++) {
        uniform_int_distribution<> dis(0, n - 1 - i);
        int ind = dis(gen);
        cout << "? " << indices[ind] << endl;
        cout.flush();
        swap(indices[ind], indices[n - 1 - i]);
        int a;
        cin >> a;
        elems.push_back(a);
    }

    sort(elems.begin(), elems.end());
    int g = elems[1] - elems[0];
    for (int i = 2; i < elems.size(); i++) {
        g = gcd(g, elems[i] - elems[i - 1]);
    }

    int min_elem = max_value - (n - 1) * g;
    cout << "! " << min_elem << " " << g << endl;
    cout.flush();

}