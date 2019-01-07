#include <iostream>
#include<queue>

using namespace std;

class CompareDist {
public:
    bool operator()(pair<int,int> n1,pair<int,int> n2) {
        return n1.first < n2.first;
    }
};


void solve() {
  int n;
  cin >> n;
  priority_queue<pair<int, int> , vector<pair<int, int> >,  CompareDist> pq;
  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;
    pq.push(make_pair(temp, i));
  }
  while(!pq.empty()) {
    pair<int, int> highest = pq.top();
    int number = highest.first;
    int letter = highest.second;
    pq.pop();
    cout << (char)(65 + letter);
    int minus = 1;
    if (!pq.empty()) {
      pair<int, int> second_highest = pq.top();
      int number2 = second_highest.first;
      int letter2 = second_highest.second;
      if (number2 == number) {
	pq.pop();
	bool added = false;
	if (pq.empty() || pq.top().first != number2) {
	  cout << (char)(65 + letter2);
	  if (number2 > 1) pq.push(make_pair(number2 - 1, letter2));
	  added = true;
	}
	else {
	  pq.push(make_pair(number2, letter2));
	}
      }
      else if (number - number2 > 1) {
	cout << (char)(65 + letter);
	minus = 2;
      }
    }
    total -= minus;
    if (number > minus) {
      pq.push(make_pair(number - minus, letter));
    }
    cout << ' ';
  }
  
}
int main() {
  int t;
  cin >> t;
  for(int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
    cout << endl;
  }

}
