#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    set<pair<int, int> > two_cycles;
    int n;
    cin >> n;
    int bffs[n + 1];
    vector<int> rbffs[n + 1];
    for (int j = 1; j <= n; j++) {
      cin >> bffs[j];
      rbffs[bffs[j]].push_back(j);
    }
  
    for (int j = 1; j <= n; j++) {
      if (j == bffs[bffs[j]]) {
	int b = max(j, bffs[j]);
	int s = min(j, bffs[j]);
	two_cycles.insert(make_pair(b, s));
      }
    }


    int max_cycle = 0;
    for (int j = 1; j <= n; j++) {
      bool checked[n + 1];
      for (int j = 1; j <= n; j++) {
	checked[j] = false;
      }
      if (!checked[j]) {
	int counter[n + 1];
	int count = 1;
	checked[j] = true;
	counter[j] = count;
	int bff = bffs[j];
	while (true) {
	  count++;
	  if (checked[bff]) {
	    int length = count - counter[bff];
	    if (length > max_cycle) max_cycle = length;
	    break;
	  }
	  checked[bff] = true;
	  counter[bff] = count;
	  bff = bffs[bff];
	}
      }
    }
    set<pair<int, int> >::iterator it;
    int length = 0;
    for (it = two_cycles.begin(); it != two_cycles.end(); it++) {
      pair<int, int> bff = *it;
      int b = bff.first;
      int s = bff.second;
      int chain_length = 2;
      vector<int> sbffs = rbffs[s];
      queue<pair<int, int> > chain;
      chain.push(make_pair(b, 0));
      int max_count = 0;
      while (!chain.empty()) {
	pair<int, int> top = chain.front();
	chain.pop();
	int kid = top.first;
	int current = top.second;
	if (current > max_count) max_count = current;
	vector<int> bbffs = rbffs[kid];
	for (int j = 0; j < bbffs.size(); j++) {
	  if (bbffs[j] != s) chain.push(make_pair(bbffs[j], current + 1));
	}
      }

      chain_length += max_count;
      max_count = 0;
      chain.push(make_pair(s, 0));
      while (!chain.empty()) {
	pair<int, int> top = chain.front();
	chain.pop();
	int kid = top.first;
	int current = top.second;
	if (current > max_count) max_count = current;
	vector<int> bbffs = rbffs[kid];
	for (int j = 0; j < bbffs.size(); j++) {
	  if (bbffs[j] != b) chain.push(make_pair(bbffs[j], current + 1));
	}
      }
      chain_length += max_count;
      length += chain_length;
    }
    cout << "Case #" << i << ": " <<  max(length, max_cycle) << endl;
  }
}
