#include <iostream>
#include <string>

using namespace std;

int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    int counts[26] = {0};
    string s;
    cin >> s;
    int numbers[10] = {0};
    for (int j = 0; j < s.length(); j++) {
      counts[s[j] - 'A']++;
      char c = s[j];
      if (s[j] == 'Z') numbers[0]++;
      else if (s[j] == 'W') numbers[2]++;
      else if (s[j] == 'U') numbers[4]++;
      else if (s[j] == 'X') numbers[6]++;
      else if (s[j] == 'G') numbers[8]++;
    }
    counts['H' - 'A'] -= numbers[8];
    counts['F' - 'A'] -= numbers[4];
    counts['S' - 'A'] -= numbers[6];
    counts['O' - 'A'] -= numbers[2] + numbers[4] + numbers[0];
    numbers[1] = counts['O' - 'A'];
    numbers[3] = counts['H' - 'A'];
    numbers[5] = counts['F' - 'A'];
    numbers[7] = counts['S' - 'A'];
    counts['I' - 'A'] -= numbers[5] + numbers[6] + numbers[8];
    numbers[9] = counts['I' - 'A'];
    cout << "Case #" << i << ": ";
    for (int j = 0; j < 10; j++) {
      for (int k = 0; k < numbers[j]; k++) {
	cout << j;
      }
    }
    cout << endl;
  }
}
