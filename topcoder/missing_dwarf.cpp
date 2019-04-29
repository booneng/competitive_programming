#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


class MoreSquares {
public:
	int countLocations(int N, int SX, int SY, vector <int> Xprefix, vector <int> Yprefix) {
		vector<int> X(N);
        vector<int> Y(N);

        for (int i = 0; i < Xprefix.size(); i++) {
            X[i] = Xprefix[i];
            Y[i] = Yprefix[i];
        }

        for (int i = Xprefix.size(); i < N; i++) {
            X[i] = (X[i - 1] * 47 + 42) % SX;
            Y[i] = (Y[i - 1] * 47 + 42) % SY;
        }

        set<pair<int, int>> S;
        for (int i = 0; i < N; i++) {
            S.insert({X[i], Y[i]});
        }

        vector<int> Xs;
        vector<int> Ys;


        for (auto p : S) {
            Xs.push_back(p.first);
            Ys.push_back(p.second);
        }

        set<pair<int, int>> extras;
        for (int i = 0; i < Xs.size(); i++) {
            for (int j = i + 1; j < Xs.size(); j++) {
                int x1 = Xs[i];
                int y1 = Ys[i];
                int x2 = Xs[j];
                int y2 = Ys[j];
                
                int xdiff = x2 - x1;
                int ydiff = y2 - y1;
                pair<int, int> p1(x1 - ydiff, y1 + xdiff);
                pair<int, int> p2(x2 - ydiff, y2 + xdiff);

                pair<int, int> p3(x1 + ydiff, y1 - xdiff);
                pair<int, int> p4(x2 + ydiff, y2 - xdiff);

                if (S.count(p1) || S.count(p2)) {
                    if (S.count(p1) && S.count(p2)) {
                        continue;
                    }
                    
                    if (S.count(p1)) {
                        extras.insert(p2);
                    }
                    else {
                        extras.insert(p1);
                    }
                }

                if (S.count(p3) || S.count(p4)) {
                    if (S.count(p3) && S.count(p4)) {
                        continue;
                    }

                    if (S.count(p3)) {
                        extras.insert(p4);
                    }
                    else {
                        extras.insert(p3);
                    }

                }
            }
        }

        return extras.size();
	}
};


//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!

int main() {
    MoreSquares sol;
    cout << sol.countLocations(18, 7, 15, {3, 3, 2, 2, 4, 6, 6, 3, 4, 1, 0, 4, 0, 3, 5, 6, 3, 6}, {0, 6, 12, 9, 8, 12, 1, 12, 12, 4, 12, 11, 7, 8, 1, 12, 3, 5});
}