#include <iostream>
#include <string>

using namespace std;

bool IsPalindrome(const string& s) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != s[s.size() - 1 - i]) return false;
    }
    return true;
}

int main() {
    string s;
    cin >> s;
    bool can = false;
    for (int i = 0; i < s.size() / 2; i++) {
        if (s[i] != s[0]) {
            can = true;
            break;
        }
    }

    if (!can) {
        cout << "Impossible";
        return 0;
    }

    
    if (s.size() % 2) {
        cout << 2;
        return 0;
    }


    for (int i = 1; i < s.size(); i++) {
        string check = s.substr(i) + s.substr(0, i);
        if (IsPalindrome(check) && check != s) {
            cout << 1;
            return 0;
        }
    }
    cout << 2;

}