#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


class UnreliableRover {



public:
    long long getArea(string direction, vector<int> minSteps, vector<int> maxSteps) {
        int n = direction.size();
        long long w = 1;
        long long h = 1;
        vector<long long> heights = {0};
        for (int i = 0; i < n; i++) {
            if (direction[i] == 'S' || direction[i] == 'N') {
                h += maxSteps[i] - minSteps[i];
            }
            else if (direction[i] == 'E' || direction[i] == 'W') {
                w += maxSteps[i] - minSteps[i];
            }
            else {
                int H = heights.size();

                for (int j = 0; j < H; j++)
                    heights.push_back(heights[j] + maxSteps[i]);
                
                inplace_merge(heights.begin(), heights.begin() + H, heights.end());
            }
        }

        long long missing_area = 0;

        for (int i = 0; i + 1 < (int) heights.size(); i++) {
            missing_area += (heights.back() - heights[i]) * (heights[i + 1] - heights[i]);
        }

        long long rectangle_area = (h + 2 * heights.back()) * (w + 2 * heights.back());
        return rectangle_area - 4 * missing_area;
    }

};

int main() {
    UnreliableRover sol;
    cout << sol.getArea("??E?", {0, 0, 3, 0}, {2, 3, 4, 2}) << endl;
    cout << sol.getArea("NSS?W?S?S?NNWSN?S?E?S??WWW?ENEW?WS??????NSWWE", {7881817, 3333237, 2145408, 0, 2292772, 0, 5772285, 0, 6582719, 0, 4366165, 7447752, 7581, 1911523, 3474331, 0, 6194963, 0, 4433342, 0, 2356165, 0, 0, 8237332, 1388749, 1251660, 0, 7609994, 9174864, 7994513, 167559, 0, 556695, 2526098, 0, 0, 0, 0, 0, 0, 2066080, 372689, 1486272, 3087276, 904158}, {9315818, 4388746, 5988514, 8936961, 9485564, 9556658, 8119267, 8848322, 9441179, 6635017, 4477254, 8714070, 3706708, 2053125, 6946942, 6373115, 8143640, 4246962, 9362408, 2503198, 7447177, 3039682, 8584197, 9177013, 3374710, 8299601, 8862981, 8577097, 9455731, 9518335, 7308372, 6133391, 2938064, 4446187, 9117482, 7915658, 5284706, 3934278, 9679124, 6354020, 3546111, 5804318, 7241674, 5078938, 2964155}) << endl;
    cout << sol.getArea("NNSS??NW?NEW?ESNNSSW??WNW?S??S????NNWS?WN?", {5251095, 6048677, 387007, 5868354, 0, 0, 6574276, 4494844, 0, 3011514, 4860791, 718001, 0, 3044424, 1307492, 7389557, 5325962, 918906, 2605109, 7746426, 0, 0, 74896, 2333546, 1221150, 0, 6528230, 0, 0, 1719787, 0, 0, 0, 0, 5648155, 1713078, 1443457, 3934389, 0, 9235918, 1749240, 0}, {7149219, 9307845, 842971, 6363944, 9975898, 9886858, 9979779, 7748155, 9366947, 3533463, 6325250, 3509916, 7801429, 5025010, 7469973, 8136183, 6895759, 1011173, 3765139, 9735592, 8048028, 6675538, 461770, 7092448, 7673943, 9398457, 7346373, 4323859, 6448652, 8377327, 7635710, 6261262, 2847896, 8577311, 6718984, 8347149, 7147041, 7051304, 8444905, 9567507, 8610657, 4414106}) << endl;
}
