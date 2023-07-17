#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

const int BASE = 1000000000;
const int WIDTH = 9;

struct Big:vector<long long> {
  Big(long long num = 0) {
    push_back(num);
    check();
  }
  Big& check() {
    if (empty()) return *this;
    while (!back() && size() >= 2) pop_back();
    for (int i = 1; i < size(); i++) {
      (*this)[i] += (*this)[i-1] / BASE;
      (*this)[i-1] %= BASE;
    }
    while (back() >= BASE) {
      push_back(back() / BASE);
      (*this)[size()-2] %= BASE;
    }
    return *this;
  }
  Big& operator = (const string &str) {
    clear();
    int x, len = (str.length() - 1) / WIDTH + 1;
    for (int i = 0; i < len; i++) {
      int end = str.length() - i * WIDTH;
      int start = max(0, end - WIDTH);
      push_back(stoll(str.substr(start, end - start)));
    }
    return (*this);
  }
};

istream& operator >> (istream &is, Big &x) {
  string str;
  is >> str;
  x = str;
  return is;
}

ostream& operator << (ostream &os, const Big &x) {
  os << x.back();
  for (int i = x.size() - 2; i >= 0; i--)
    os << setfill('0') << setw(WIDTH) << x[i];
  return os;
}

Big& operator += (Big &a, const Big &b) {
  if (a.size() < b.size()) a.resize(b.size());
  for (int i = 0; i < a.size(); i++) a[i] += b[i];
  return a.check();
}

Big operator + (Big a, const Big &b) {
  return a += b;
}

Big operator * (const Big &a, const Big &b) {
  Big c;
  c.assign(a.size() + b.size(), 0);
  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < b.size(); j++) {
      c[i + j] += a[i] * b[j];
      if (c[i + j] >= BASE) {
        c[i + j + 1] += c[i + j] / BASE;
        c[i + j] %= BASE;
      }
    }
  }
  while (!c.back() && c.size() >= 2) c.pop_back();
  return c;
}

int main() {
  Big a, b;
  cin >> a >> b;
  Big c = a * b;
  cout << c;
  return 0;
}