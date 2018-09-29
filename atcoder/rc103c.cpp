#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  int max_even = 0;
  int max_odd = 0;
  int second_max_even = 0;
  int second_max_odd = 0;
  int max_even_val, max_odd_val, second_max_even_val, second_max_odd_val;
  unordered_map<int, int> even_counts;
  unordered_map<int, int> odd_counts;
  for (int i = 0; i < n; i+=2) {
    even_counts[v[i]]++;
    int cur_count = even_counts[v[i]];
    if (cur_count > max_even) {
      if (max_even_val != v[i]) {
	second_max_even = max_even;
	second_max_even_val = max_even_val;
      }
      max_even_val = v[i];
      max_even = cur_count;
    }
    else if (even_counts[v[i]] > second_max_even) {
      second_max_even = even_counts[v[i]];
      second_max_even_val = v[i];
    }
  }
  for (int i = 1; i < n; i+=2) {
    odd_counts[v[i]]++;
    int cur_count = odd_counts[v[i]];
    if (cur_count > max_odd) {
      if (max_odd_val != v[i]) {
	second_max_odd = max_odd;
	second_max_odd_val = max_odd_val;
      }
      max_odd_val = v[i];
      max_odd = cur_count;
    }
    else if (odd_counts[v[i]] > second_max_odd) {
      second_max_odd = odd_counts[v[i]];
      second_max_odd_val = v[i];
    }
  }
  int fixed = max_even + max_odd;
  if (max_even_val == max_odd_val) {
    fixed = max(max_even + second_max_odd, max_odd + second_max_even);
  }
  cout << n - fixed;
  

}
