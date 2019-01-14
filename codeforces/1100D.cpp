#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> board(1001, vector<int>(1001, 0));
int kx, ky;
pair<int, int> rooks[667];

void read() {
    int k, x, y;
    cin >> k >> x >> y;
    if (k <= 0) {
      exit(0);
    }
    int px = rooks[k].first;
    int py = rooks[k].second;
    board[px][py] = 0;
    board[x][y] = 1;
    rooks[k] = {x, y};
}


void move(int x, int y) {
  kx += x;
  ky += y;
  if (board[kx][ky]) kx -= x;
  cout << kx << ' ' << ky << endl;
  cout.flush();
  read();
}



int main() {
  cin >> kx >> ky;
  for (int i = 1; i < 667; i++) {
    int x, y;
    cin >> x >> y;
    board[x][y] = 1;
    rooks[i] = {x, y};
  }
  while (kx < 500) move(1, 0);
  while (kx > 500) move(-1, 0);
  while (ky < 500) move(0, 1);
  while (ky > 500) move(0, -1);

  vector<int> q(5);
  for (int i = 1; i < 667; i++) {
    if (rooks[i].first < 500 && rooks[i].second < 500) q[1]++;
    else if (rooks[i].first < 500 && rooks[i].second > 500) q[2]++;
    else if (rooks[i].first > 500 && rooks[i].second < 500) q[3]++;
    else if (rooks[i].first > 500 && rooks[i].second > 500) q[4]++;
  }

  int id = 1;
  for (int i = 2; i <= 4; i++) {
    if (q[i] < q[id]) id = i;
  }

  switch(id){
		case 1:{
			while(kx < 1000 && ky < 1000) move(1, 1);
			break;
		}
		case 2:{
			while(kx < 1000 && ky > 0) move(1, -1);
			break;
		}
		case 3:{
			while(kx > 0 && ky < 1000) move(-1, 1);
			break;
		}
		case 4:{
			while(kx > 0 && ky > 0) move(-1, -1);
			break;
		}
	}


}