#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    bool win = false;
    stack<char> st;
    for (int i = 0; i < s.size(); i++) {
        if (!st.empty() && s[i] == st.top()) {
            st.pop();
            win = win ? false : true;
        }
        else {
            st.push(s[i]);
        }
    }

    if (win) cout << "Yes";
    else cout << "No";
}