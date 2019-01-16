#include <bits/stdc++.h>


class ModInt {
private:
  static int MOD;

public:
  int val;

  static void SetMod(int m) {
    MOD = m;
  }

  ModInt(int num) 
    : val(num) {}

  ModInt operator+(const ModInt& b) {
    return ModInt((val + b.val) % MOD);
  }

  ModInt operator*(const ModInt& b) {
    return ModInt((val * 1LL * b.val) % MOD);
  }

  ModInt operator-(const ModInt& b) {
    return ModInt((val + (MOD - b.val)) % MOD);
  }

  void operator+=(const ModInt& b) {
    (*this) = (*this) + b;
  }

  void operator*=(const ModInt& b) {
    (*this) = (*this) * b;
  }

};

std::ostream& operator<<(std::ostream& stream, const ModInt& num) {
  stream << num.val << std::endl;
  return stream;
}

int ModInt::MOD = 1000000007;

int main() {
  ModInt a(1000000000);
  ModInt b(100);
  a += b;
  std::cout << a + b;
}