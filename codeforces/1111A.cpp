#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

    if (s.size() != t.size()) {
        cout << "No";
    }
    else {
        bool can = true;
        for (int i = 0; i < s.size(); i++) {
            if (vowels.count(s[i]) && !vowels.count(t[i])) {
                can = false;
                break;
            }
            else if (vowels.count(t[i]) && !vowels.count(s[i])) {
                can = false;
                break;
            }
        }
        if (can) cout << "Yes";
        else cout << "No";
    }
}