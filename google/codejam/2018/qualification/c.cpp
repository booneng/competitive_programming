#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

class CompareDist {
public:
  bool operator()(vector<int> n1, vector<int> n2) {
    return n1[0] < n2[0];
  }
};

int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    int a;
    cin >> a;
    int length = 3;
    int height = 3;
    while (height * length < a) {
      height++;
    }

    int r = 0;
    int c = 0;
    int rf, cf;
    priority_queue<vector<int>, vector<vector<int> >, CompareDist> pq;
    bool filled[1000][1000];
    for (int j = 0; j < 1000; j++) {
      for (int k = 0; k < 1000; k++) {
	filled[j][k] = false;
      }
    }
    int choice_counts[height - 2][length - 2];
    for (int j = 0; j < height - 2; j++) {
      for (int k = 0; k < length - 2; k++) {
	choice_counts[j][k] = 9;
	vector<int> counts(3);
	counts[0] = choice_counts[j][k];
	counts[1] = j;
	counts[2] = k;
	pq.push(counts);
      }
    }
    while (1) {
      vector<int> top = pq.top();
      int r = top[1];
      int c = top[2];
      while (choice_counts[r][c] < top[0]) {
      	pq.pop();
      	top = pq.top();
      	r = top[1];
      	c = top[2];
      }
      cout << 2 + r << ' ' << 2 + c << endl;
      cout.flush();
      cin >> rf >> cf;
      if (rf == 0 && cf == 0) {
	break;
      }
      else if (rf == -1 && cf == -1) {
	return 0;
      }
      if (!filled[rf][cf]) {
	pq.pop();
	filled[rf][cf] = true;
	for (int l = rf - 3; l < rf; l++) {
	  for (int m = cf - 3; m < cf; m++) {
	    if (l >= 0 && l < height - 2 && m >= 0 && m < length - 2) {
	      choice_counts[l][m]--;
	      if (choice_counts[l][m] > 0) {
		vector<int> counts(3);
		counts[0] = choice_counts[l][m];
		counts[1] = l;
		counts[2] = m;
		pq.push(counts);
	      }
	    }
	  }
	}
      }
    }
  }
}
