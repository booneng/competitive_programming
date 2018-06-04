#include <iostream>
#include <string>
#define ll long long int

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        ll a, b, n;
	cin >> a >> b >> n;
	cin.ignore();
	a++;
	ll mid = (a + b) / 2;
	while(n--) {
	  cout << mid << '\n';
	  cout.flush();
	  string resp;
	  cin >> resp;
	  if (resp.compare("CORRECT") == 0) {
	    break;
	  }
	  else if (resp.compare("TOO_SMALL") == 0) {
	    a = mid + 1;
	  }
	  else if (resp.compare("TOO_BIG") == 0) {
	    b = mid - 1;
	  }
	  mid = (a + b) / 2;
	}
    }
}

