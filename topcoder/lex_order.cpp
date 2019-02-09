#include <string>
#include <iostream>

using namespace std;

class LexOrder {

public:
    string between(string A, string B) {
        if (A.size() == 50) {
            int i = 49;
            while (A[i] == 'z' && i >= 0) i--;
            A[i]++;
        }
        else {
            A += 'a';
        }

        if (A == B) return "IMPOSSIBLE";
        else return A;
    }
};