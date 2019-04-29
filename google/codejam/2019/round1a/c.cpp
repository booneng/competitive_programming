#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int n;
string w[N];

struct TrieNode {
    TrieNode* nodes[26];
    int number;
    bool root;
    bool end;

    TrieNode() {
        for (int i = 0; i < 26; i++) {
            nodes[i] = nullptr;
        }
        end = false;
    }

    void insert(string word, bool root = false) {
        this->root = root;
        if (word.size() == 0) {
            end = true;
            return;
        }

        char c = word[0];
        if (!nodes[c - 'A']) {
            nodes[c - 'A'] = new TrieNode();
        }
        nodes[c - 'A']->insert(word.substr(1));
    }

    int count() {
        int cnt = 0;
        if (end) cnt++;
        for (int i = 0; i < 26; i++) {
            if (nodes[i]) {
                cnt += nodes[i]->count();
            }
        }
        if (cnt > 1 && !root) cnt -= 2;
        return cnt;
    }
};


int solve() {
    cin >> n;
    TrieNode* root = new TrieNode();
    for (int i = 0; i < n; i++) {
        cin >> w[i];
        reverse(w[i].begin(), w[i].end());
        root->insert(w[i], true);
    }
    return n - root->count();
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": " << solve() << endl;
    }
}