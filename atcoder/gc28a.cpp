#include <iostream>
#include <string>

using namespace std;

long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  long long n, m;
  cin >> n >> m;
  string s1, s2;
  cin >> s1 >> s2;
  
  long long d = gcd(n, m);
  long long i1 = n / d;
  long long i2 = m / d;

  long long len = n * m / d;
  long long index1 = 0;
  long long index2 = 0;
  while (index1 < n && index2 < m) {
    if (s1[index1] != s2[index2]) {
      cout << -1;
      return 0;
    }
    index1 += i1;
    index2 += i2;
  }
  cout << len;
}
