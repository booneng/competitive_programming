#include <bits/stdc++.h>


class ModInt {
private:
  static int MOD;

public:
  int val;

  static void SetMod(int m) {
    MOD = m;
  }

  explicit ModInt(int num) 
      : val(num)
  {
    while (val < 0) {
      val += MOD;
    }
    val %= MOD;
    assert(val >= 0 && val < MOD);
  }

  ModInt(const ModInt& num) 
      : val(num.val) {}

  ModInt operator+(const ModInt& b) const {
    return ModInt((val + b.val) % MOD);
  }

  ModInt operator*(const ModInt& b) const {
    return ModInt((val * 1LL * b.val) % MOD);
  }

  ModInt operator-(const ModInt& b) const {
    return ModInt((val + (MOD - b.val)) % MOD);
  }

  void operator+=(const ModInt& b) {
    (*this) = (*this) + b;
  }

  void operator*=(const ModInt& b) {
    (*this) = (*this) * b;
  }

  bool operator==(const ModInt& b) const {
    return val == b.val;
  }

  bool operator!=(const ModInt& b) const {
    return !((*this) == b);
  }

};

std::ostream& operator<<(std::ostream& stream, const ModInt& num) {
  stream << num.val << std::endl;
  return stream;
}

int ModInt::MOD = 0;

void Print(ModInt i) {
  std::cout << i << std::endl; 
}

int main() {
  ModInt::SetMod(1000000007);
  ModInt a(1000000000);
  ModInt b(100);
  a += b;
  std::cout << a + b;
}