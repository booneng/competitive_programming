#include <iostream>

using namespace std;

int main() {
    int q;
    cin >> q;

    while (q--) {
        int a;
        cin >> a;
        if (a & (a + 1)) {
            int i = 1;
            while (i <= a) {
                i <<= 1;
            }
            cout << i - 1 << endl;
        }
        else {
            int div = 2;
            while (a % div) {
                if (div * div > a) {
                    div = a;
                    break;
                }
                div++;
            }
            cout << a / div << endl;
        }

    }
}