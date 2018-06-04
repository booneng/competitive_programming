#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int rps[15][4][4];
string order[14][4];

string csort(string lineup) {
  string ans;
  vector<string> chunks;
  if (lineup.length() == 2) {
    return lineup;
  }
  for (int cs = 2; cs <= lineup.length() / 2; cs *= 2) {
    chunks.clear();
    for (int i = 0; i < lineup.length() / cs; i++) {
      chunks.push_back(lineup.substr(i * cs, cs));
    }
    for (int i = 0; i < chunks.size(); i += 2) {
      if (chunks[i] > chunks[i + 1]) {
	string temp = chunks[i];
	chunks[i] = chunks[i + 1];
	chunks[i + 1] = temp;
      }
    }
    string temp;
    for (int i = 0; i < chunks.size(); i++) {
      temp += chunks[i];
    }
    lineup = temp;
  }
  for (int i = 0; i < chunks.size(); i++) {
    ans += chunks[i];
  }
  return ans;
}

int main() {
  int T;
  cin >> T;
  for (int i = 0; i < 15; i++) {
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 4; k++) {
	rps[i][j][k] = 0;
      }
    }
  }
  char tops[3] = {'P', 'R', 'S'};
  for (int w = 0; w < 3; w++) {
    char c = tops[w];
    queue<pair<char, int> > cq;
    cq.push(make_pair(c, 1));
    order[1][w].push_back(c);
    rps[1][w][w] = 1;
    while (!cq.empty()) {
      pair<char, int> top = cq.front();
      cq.pop();
      char cur = top.first;
      int depth = top.second + 1;
      if (depth > 13) continue;
      char left, right;
      int in, in2;
      if (cur == 'P') {
	left = 'P';
	right = 'R';
	in = 0;
	in2 = 1;
      }
      else if (cur == 'R') {
	left = 'R';
	right = 'S';
	in = 1;
	in2 = 2;
      }
      else if (cur == 'S') {
	left = 'P';
	right = 'S';
	in = 0;
	in2 = 2;
      }
      order[depth][w] += left;
      order[depth][w] += right;
      rps[depth][w][in]++;
      rps[depth][w][in2]++;
      cq.push(make_pair(left, depth));
      cq.push(make_pair(right, depth));
    }
  }

  for (int t = 1; t <= T; t++) {
    int n, r, p, s;
    cin >> n >> r >> p >> s;
    bool possible = false;
    n++;
    cout << "Case #" << t << ": ";
    for (int i = 0; i < 3; i++) {
      if (p == rps[n][i][0] && r == rps[n][i][1] && s == rps[n][i][2]) {
	possible = true;
	cout << csort(order[n][i]) << endl;
      }
    }
    if (!possible) {
      cout << "IMPOSSIBLE" << endl;
    }
  }
}
