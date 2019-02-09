#include <iostream>
#include <vector>
#include <cstring>


using namespace std;

class VisitN {

    bool visited[30][30];
    int n;
    int visited_count;
    bool check(int r, int c) {
        if (!visited[r][c]) {
            visited[r][c] = true;
            visited_count++;
            if (visited_count == n) return true;
        }
        return false;
    }

public:

    string visit(int n, int r, int c) {
        string seq;

        memset(visited, false, sizeof(visited));
        this->n = n;
        visited_count = 0;

        if (check(r, c)) return seq;

        while (r > 0 || c > 0) {
            if (r > 0) {
                seq += 'N';
                r--;
            }
            else if (c > 0) {
                seq += 'W';
                c--;
            }
            if (check(r, c)) return seq;

        }

        if (visited_count == n) return seq;
        for (; r < 30;) {
            for (; c < 29; ) {
                seq += 'E';
                c++;
                if (check(r, c)) return seq;
            }

            seq += 'S';
            r++;
            if (check(r, c)) return seq;


            for (; c > 0;) {
                seq += 'W';
                c--;
                if (check(r, c)) return seq;
            }

            seq += 'S';
            r++;
            if (check(r, c)) return seq;

        }
        return seq;
    }

    void print() {
        int cnt = 0;
        for (int i = 0; i < 30; i++) {
            for (int j = 0; j < 30; j++) {
                cout << visited[i][j] << ' ';
                if (visited[i][j]) cnt++;
            }
            cout << endl;
        }
        cout << cnt;
    }

};

int main() {
    VisitN sol;
    cout << sol.visit(900, 29, 29) << endl;
    sol.print();
}