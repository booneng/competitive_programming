#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class HungryCowsMedium {

bool check(vector<int>& appetites, vector<int>& barns, long long time) {

    int j = 0;
    long long t = 0;
    for (int i = 0; i < barns.size() && j < appetites.size(); i++) {
        if (appetites[j] > time - barns[i]) return false;
        t += time - barns[i];
        while (j < appetites.size() && t >= appetites[j]) {
            t -= appetites[j];
            j++;
        }
    }
    return j == appetites.size();
}


public:

    long long getWellFedTime(vector<int> appetites, vector<int> barns) {
        sort(barns.begin(), barns.end());
        sort(appetites.begin(), appetites.end(), greater<int>());

        long long left = 0;
        long long right = 305000000000;

        while (left < right) {
            long long mid = (left + right) / 2;
            if (check(appetites, barns, mid)) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return right;
    }
};