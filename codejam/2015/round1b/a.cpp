#include <iostream>

#define ll long long int

using namespace std;

ll flip(ll s) {
  string s2 = to_string(s);
  string s3 = s2;
  for (int i = 0; i < s2.length(); i++) {
    s3[i] = s2[s2.length() - i - 1];
  }
  return stoll(s3);
}

string flip(string s) {
  string new_s;
  for (int i = s.length() - 1; i >= 0; i--) {
    new_s += s[i];
  }
  return new_s;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    string n;
    cin >> n;
    int count = 0;
    int digits = n.length();
    if (digits == 1) {
      cout << "Case #" << t << ": " << n << endl;
      continue;
    }
    int cur = 1;
    int steps = 1;
    while (cur < digits) {
      string add;
      if (cur > 1) add += '1';
      if (cur <= 2) add += '9';
      else {
	if (cur % 2 == 0) add += '9';
	else add += '0';
	for (int i = 0; i < (cur - 1) / 2; i++) {
	  add += '9';
	}
      }
      steps += stoi(add);
      cur++;
    }
    string left_half = n.substr(0, digits / 2);
    string right_half = n.substr(digits / 2);
    string flip_left = flip(left_half);
    bool flipped = false;
    if (flip_left.length() > 0 && stoi(flip_left) > 1) {
      if (stoi(right_half) == 0) {
	left_half = to_string(stoi(left_half) - 1);
	flip_left = flip(left_half);
	string add;
	for (int i = 0; i < right_half.length(); i++) {
	  add += '9';
	}
	if (stoi(flip_left) > 1) flipped = true;
	steps += stoi(add);
      }
      else {
	flipped = true;
      }
      steps += stoi(flip_left);
    }
    if (right_half.length() > 0) {
      if (stoi(right_half) > 0) {
	steps += stoi(right_half);
	if (flipped) steps--;
      }
    }
    if (flipped) steps++;
    // if stoi right half > 0
    cout << "Case #" << t << ": " << steps << endl;
  }

}
