#include <bits/stdc++.h>

using namespace std;

const double PI = 3.14159265358979323846;

class ComplexNumber {
  double real;
  double img;

public:
  ComplexNumber(double r, double i) : real(r), img(i) {
  }

  ComplexNumber() : real(0), img(0) {}

  ComplexNumber operator+(ComplexNumber a) const {
    return ComplexNumber(a.real + real, a.img + img);
  }

  ComplexNumber operator*(ComplexNumber a) const {
    double r = a.real * real - a.img * img;
    double i = a.real * img + a.img * real;
    return ComplexNumber(r, i);
  }

  ComplexNumber operator-(ComplexNumber a) const {
    return ComplexNumber(real - a.real, img - a.img);
  }

  ComplexNumber operator/(double a) const {
    return ComplexNumber(real / a, img / a);
  }

  ostream& print(ostream& os) const {
    return os << '(' << real << " + " << img << "i)";
  }

  double get_real() const {
    return real;
  }

};

ostream& operator<<(ostream& os, ComplexNumber& n) {
  return n.print(os);
}

vector<ComplexNumber> FastFourierTransform(vector<ComplexNumber> a, ComplexNumber w) {
  int n = a.size();
  if (n == 1) {
    return {a[0]};
  }
  vector<ComplexNumber> aeven, aodd;
  for (int i = 0; i < a.size(); i++) {
    if (i % 2) aodd.push_back(a[i]);
    else aeven.push_back(a[i]);
  }

  vector<ComplexNumber> s = FastFourierTransform(aeven, w * w);
  vector<ComplexNumber> t = FastFourierTransform(aodd, w * w);

  vector<ComplexNumber> res(n, ComplexNumber(0, 0));
  ComplexNumber mul(1, 0);
  for (int i = 0; i < n / 2; i++) {
    res[i] = s[i] + mul * t[i];
    res[i + n / 2] = s[i] - mul * t[i];
    mul = mul * w;
  }
  return res;
}

vector<ComplexNumber> MultiplyPolynomials(vector<ComplexNumber> a, vector<ComplexNumber> b) {
  int n = max(a.size(), b.size());
  int twon = 1;
  while (twon < n) twon <<= 1;
  twon <<= 1;
  while (a.size() < twon) a.push_back(ComplexNumber(0, 0));
  while (b.size() < twon) b.push_back(ComplexNumber(0, 0));
  ComplexNumber w(cos(2 * PI / twon), sin(2 * PI / twon));
  vector<ComplexNumber> r = FastFourierTransform(a, w);
  vector<ComplexNumber> s = FastFourierTransform(b, w);
  vector<ComplexNumber> t;
  for (int i = 0; i < twon; i++) {
    t.push_back(r[i] * s[i]);
  }

  ComplexNumber winv(cos(2 * PI * (twon - 1) / twon), sin(2 * PI * (twon - 1) / twon));
  vector<ComplexNumber> tmp = FastFourierTransform(t, winv);
  vector<ComplexNumber> c;
  for (int i = 0; i < twon; i++) {
    c.push_back(tmp[i] / twon);
  }
  return c;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<ComplexNumber> a(n);
  vector<ComplexNumber> b(m);
  for (int i = 0; i < n; i++) {
    int r;
    cin >> r;
    a[i] = ComplexNumber(r, 0);
  }

  for (int i = 0; i < m; i++) {
    int r;
    cin >> r;
    b[i] = ComplexNumber(r, 0);
  }

  vector<ComplexNumber> c = MultiplyPolynomials(a, b);
  for (int i = 0; i < c.size(); i++) {
    cout << c[i] << endl;
  }
}
