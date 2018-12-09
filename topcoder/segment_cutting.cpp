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

const double PI = 3.14159265358979323846;

class SegmentCutting {

  vector<long long> xl;
  vector<long long> xr;
  vector<long long> yl;
  vector<long long> yr;
  
  vector<int> x;
  vector<int> y;
  
  bool sameSide(double theta1, double theta2) {
    if (theta1 < 0) theta1 += 2 * PI;
    if (theta2 < 0) theta2 += 2 * PI;
    return abs(theta1 - theta2) < PI;
  }

  long long eval() {
    return xr[0] * xl[2] - 2 * xl[1] * xr[1] + xl[0] * xr[2]
      + yr[0] * yl[2] - 2 * yl[1] * yr[1] + yl[0] * yr[2];
  }

  void move(int idx, bool dir) {
    int mult = dir ? -1 : 1;

    xl[0] += mult;
    xl[1] += mult * x[idx];
    xl[2] += mult * x[idx] * x[idx];

    xr[0] -= mult;
    xr[1] -= mult * x[idx];
    xr[2] -= mult * x[idx] * x[idx];

    yl[0] += mult;
    yl[1] += mult * y[idx];
    yl[2] += mult * y[idx] * y[idx];

    yr[0] -= mult;
    yr[1] -= mult * y[idx];
    yr[2] -= mult * y[idx] * y[idx];
  }

  void init() {
    xl = vector<long long>(3, 0);
    xr = vector<long long>(3, 0);
    yl = vector<long long>(3, 0);
    yr = vector<long long>(3, 0);

    for (int i = 0; i < x.size(); i++) {
      xl[0]++;
      xl[1] += x[i];
      xl[2] += x[i] * x[i];

      yl[0]++;
      yl[1] += y[i];
      yl[2] += y[i] * y[i];
    }
  }
public:
  long long maxValue(vector <int> x, vector <int> y) {
    this->x = x;
    this->y = y;
    
    int n =  x.size();
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      vector<pair<double, int> > angle_points;
      for (int j = 0; j < n; j++) {
	if (j == i) continue;
	int dx = x[j] - x[i];
	int dy = y[j] - y[i];
	angle_points.push_back(make_pair(atan2(dy, dx), j));
      }
			
      sort(angle_points.begin(), angle_points.end());
      angle_points.insert(angle_points.end(), angle_points.begin(), angle_points.end());
      for (int j = n - 1; j < angle_points.size(); j++) {
      	angle_points[j].first += 2 * PI;
      }
      init();

      int right = 0;
      for (int j = 0; j < n - 1; j++) {
	while (angle_points[right].first < angle_points[j].first + PI) {
	  move(angle_points[right].second, true);
	  right++;
	}

	ans = max(ans, eval());
	move(angle_points[j].second, false);
      }
    }
    return ans;
  }
};

int main() {
  SegmentCutting sg;

  vector<int> x;
  vector<int> y;

  // test case 1: 6
  x = {0,0,1,1};
  y = {0,1,0,1};
  cout << sg.maxValue(x, y) << endl;

  // test case 2: 25
  x = {0, 3};
  y = {0, 4};
  cout << sg.maxValue(x, y) << endl;

  // test case 3: 159
  x = {-6, 3, -4};
  y = {2, 0, 5};
  cout << sg.maxValue(x, y) << endl;

  // test case 4: 94640
  x = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  y = {1, 4, 9, 16, 25, 36, 49, 64, 81, 100};
  cout << sg.maxValue(x, y) << endl;

  // test case 5: 5887914054
  x = {-24,11,-235,49,13,-247,-575,80,35,29,1,-9,-1,-1,-27,-3,-20,13,-33,111,
       -36,30,-303,-645,-23,-5,393,227,89,145,6,515,234,271,-901,239,-368,-642,
       -3,125,-63,2,221,-113,1,6,3,-31,-6,-49,-785,314,363,-2,34,15,465,11,32,
       -72,394,20,-8,-448,429,-7,-88,-11,-42,-8,2,-707,-231,-143,76,-10,-152,
       -66,24,-73,778,-29,807,-63,722,-804,413,-21,-2,-131,26,3,-23,101,-551,
       -58,21,180,-15,-88,410,604,74,956,62,275,-352,-93,291,184,70,564,-594,
       -101,-391,18,115,-329,8,-4,-218,77,218,-145,27,-34,598,-87,-243,-323,34,
       211,7,-145,-49,528,-13,10,-778,184,-65,101,-232,503,-6,69,553,-14,25,26,
       854,955,-10,-490,-674,-4,9,-373,42,-121,-528,67,-32,23,74,81,-752,-7,
       -122,-464,-174,-722,46,961,57,-105,269,48,64,-585,-107,641,9,27,297,5,
       -44,107,-600,113,468,-24,-104,277,10,5,75,106,-591,38};
  y = {-1,-2,62,-8,-1,28,-47,241,-10,-3,3,-41,1,95,111,-4,-114,503,1,19,3,
       -26,615,762,7,-52,399,-174,-987,30,-49,165,67,551,-214,-36,-108,-242,
       -967,69,698,-120,-298,20,-43,32,-171,2,-9,8,50,948,-2,-30,-3,53,-411,
       410,141,-8,292,41,71,-523,-329,-284,8,84,34,559,-160,2,73,12,276,-16,
       -33,-63,119,869,127,47,963,-7,-995,146,-161,775,17,-5,-167,-315,59,
       -345,10,766,-10,-6,850,12,-5,-17,295,-89,14,71,-11,-305,13,-524,181,
       -279,-11,15,437,349,20,10,-749,82,25,336,-6,-794,-944,895,-52,72,198,
       194,-988,641,-59,-434,-524,-381,368,6,-14,125,-55,319,-666,-610,-274,
       359,-39,206,28,-719,-150,51,-366,-341,89,13,-635,-287,56,35,665,103,-81,
       156,-4,888,-48,96,-48,340,61,396,272,-16,335,219,-388,15,324,24,-194,9,
       -310,7,-25,5,39,-342,118,-92,425,-336,796,950,-419,-812,-488,428,-32,-9};
  cout << sg.maxValue(x, y) << endl;
}
