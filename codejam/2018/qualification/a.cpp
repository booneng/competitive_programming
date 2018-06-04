#include <iostream>
#include <string>

#define ll long long int

using namespace std;

int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    ll d;
    string moves;
    cin >> d;
    cin >> moves;
    ll damage = 0;
    ll current = 1;
    for (int j = 0; j < moves.length(); j++) {
      if (moves[j] == 'S') damage += current;
      else if (moves[j] == 'C') current <<= 1;
    }
    ll count = 0;
    for (int j = moves.length() - 1; j >= 0; j--) {
      if (damage <= d) {
	break;
      }
      if (moves[j] == 'C') {
	current >>= 1;
      }
      else if (j > 0 && moves[j] == 'S' && moves[j - 1] == 'C') {
	moves[j - 1] = 'S';
	moves[j] = 'C';
	damage -= current / 2;
	if (j < moves.length() - 1 && moves[j + 1] == 'S') j += 2;
	else current >>= 1;
	count++;
      }
    }
    cout << "Case #" << i << ": ";
    if (damage <= d) cout << count;
    else cout << "IMPOSSIBLE";
    cout << endl;
  }

}
