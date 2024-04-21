#include <bits/stdc++.h>
#define BASE 10000
#define LEN 4
#define Complex complex<double>
using namespace std;

const double pi = acos(-1);

void init(vector<Complex> x) {
  int len = x.size();
  vector<int> rev(len, 0);
  for (int i = 0; i < len; i++) {
    rev[i] = rev[i >> 1] >> 1;
    if (i & 1)
      rev[i] |= len >> 1;
  }
  for (int i = 0; i < len; i++)
    if (i < rev[i])
      swap(x[i], x[rev[i]]);
}

void fft(vector<Complex> &x, int f) {
  init(x);
  int len = x.size();
  for (int i = 2; i <= len; i <<= 1) {
    Complex wn(BASE * cos(2 * pi / i), BASE * sin(2 * f * pi / i));
    for (int j = 0; j < len; j += i) {
      Complex w(BASE, 0);
      for (int k = j; k < j + i / 2; k++) {
        Complex u = x[k], t = w * x[k + i / 2];
        x[k] = u + t;
        x[k + i / 2] = u - t;
        w *= wn;
      }
    }
  }
  if (f == -1) {
    for (int i = 0; i < len; i++)
      x[i] /= len;
  }
}

void change(const Big &a, vector<Complex> &b);

struct Big:vector<int> {
  Big operator * (const Big &p) {
    int maxlen = max(size(), p.size());
    int len = 1;
    while (len < 2 * maxlen - 1) len <<= 1;

    vector<Complex> a(len, 0), b(len, 0);
    change(*this, a);
    change(p, b);

    fft(a, 1);
    fft(b, 1);

    for (int i = 0; i < len; i++)
      a[i] *= b[i];

    fft(a, -1);

    Big ans;
    ans.assign(len, 0);
    for (int i = 0; i < len; i++) {
      ans[i] += int(a[i].real() + 0.5);
      if (ans[i] >= BASE) {
        ans[i + 1] += ans[i] / BASE;
        ans[i] %= BASE;
      }
    }
  
    return ans;
  }
};

void change(const Big &a, vector<Complex> &b) {
  for (int i = 0; i < a.size(); i++)
    b[i] = Complex(a[i], 0);
  for (int i = a.size(); i < b.size(); i++)
    b[i] = Complex(0, 0);
}

istream& operator >> (istream &is, Big &b) {
  string str;
  is >> str;
  int len = (str.size() - 1) / LEN + 1;
  b.clear();
  for (int i = 0; i < len; i++) {
    int l = i * LEN;
    int r = min(l + LEN, int(str.size()));
    b.push_back(stoi(str.substr(l, r - l)));
  }
  return is;
}

ostream& operator << (ostream& os, const Big &b) {
  cout << b.back();
  for (int i = b.size() - 2; i >= 0; i--)
    cout << setw(LEN) << setfill('0') << b[i];
  return os;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  Big a, b;
  cout << a * b;
  return 0; 
}