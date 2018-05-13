#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

#define ll long long int

const ll MAX = 3 * 1e18 + 1;
using namespace std;

int main() {
  int n;
  cin >> n;
  set<ll> numbers;
  set<ll> mult3;
  set<ll> mult2;
  ll max_div = 0;
  ll min_a = MAX;
  for (int i = 0; i < n; i++) {
    ll tmp;
    cin >> tmp;
    numbers.insert(tmp);
    if (tmp % 3 == 0) mult3.insert(tmp);
    else min_a = min(min_a, tmp);
  }

  vector<ll> threes;
  if (!mult3.empty()) {
    threes.push_back(*mult3.begin());
    mult3.erase(mult3.begin());
  }
  while (!mult3.empty()) {
    ll first = threes[0];
    if (first % 2 == 0 && mult3.find(first / 2) != mult3.end()) {
      threes.insert(threes.begin(), first / 2);
      mult3.erase(first / 2);
    }
    else if (mult3.find(first * 3) != mult3.end()) {
      threes.insert(threes.begin(), first * 3);
      mult3.erase(first * 3);
    }
    
    ll last = threes[threes.size() - 1];
    if (mult3.find(last * 2) != mult3.end()) {
      threes.push_back(last * 2);
      mult3.erase(last * 2);
    }
    else if (mult3.find(last / 3) != mult3.end()) {
      threes.push_back(last / 3);
      mult3.erase(last / 3);
    }
  }

  vector<ll> rest;
  if (min_a < MAX) {
    rest.push_back(min_a);
    ll cur = min_a;
    while (true) {
      cur = cur * 2;
      if (numbers.find(cur) != numbers.end()) {
	rest.push_back(cur);
      }
      else break;
    }
  }
  for (int i = 0; i < threes.size(); i++) {
    cout << threes[i] << ' ';
  }
  for (int i = 0; i < rest.size(); i++) {
    cout << rest[i] << ' ';
  }
}
