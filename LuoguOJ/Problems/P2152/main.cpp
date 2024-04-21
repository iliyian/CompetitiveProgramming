// date: 2024-03-06 17:37:05
// tag: MLE#01:爆了，没压位，
// MLE#02: 万进制还是爆了
// MLE#03: 1e9进制还是爆了
// AC，感情是没传引用
// 但是考虑到辗转相减不涉及高精度下的高效竖式除法需要的试商，压位实际上不难

#include <bits/stdc++.h>
#define int long long
// 9e18
#define BASE 1000000000
#define WIDTH 9
using namespace std;

struct Big:vector<int> {
  Big() {
    clear();
  }
  Big(int x) {
    (*this) = to_string(x);
  }
  Big(int n, int x) {
    clear();
    assign(n, x);
  }
  void operator = (const string &b) {
    int len = (b.size() - 1) / WIDTH + 1;
    clear();
    for (int i = 0; i < len; i++) {
      int end = b.size() - i * WIDTH;
      int begin = max(0ll, end - WIDTH);
      push_back(stoll(b.substr(begin, end - begin)));
    }
  }
  bool operator < (const Big &b) {
    if (size() != b.size()) return size() < b.size();
    for (int i = size() - 1; i >= 0; i--) {
      if ((*this)[i] != b[i]) {
        return (*this)[i] < b[i];
      }
    }
    return false;
  }
  bool operator != (int x) {
    return (*this) != Big(x);
  }
  bool operator == (int x) {
    return !((*this) != x);
  }
  bool operator != (const Big &b) {
    return ((*this) < b) || (b < (*this));
  }
  bool mod2() {
    return (*this)[0] % 2;
  }
  void div2() {
    for (int i = size() - 1; i > 0; i--) {
      if ((*this)[i] % 2) {
        (*this)[i - 1] += BASE;
        (*this)[i]--;
      }
      (*this)[i] /= 2;
    }
    (*this)[0] /= 2;
    while (size() >= 2 && !back()) pop_back();
  }
  Big operator * (const Big &b) {
    Big c(b.size() + size() + 1, 0);
    for (int i = 0; i < size(); i++) {
      for (int j = 0; j < b.size(); j++) {
        c[i + j] += (*this)[i] * b[j];
        if (c[i + j] >= BASE) {
          c[i + j + 1] += c[i + j] / BASE;
          c[i + j] %= BASE;
        }
      }
    }
    while (c.size() >= 2 && !c.back()) c.pop_back();
    return c;
  }
  Big operator * (int x) {
    Big c = (*this) * Big(x);
    return c;
  }
  Big operator - (const Big &b) {
    Big a = (*this);
    for (int i = 0; i < b.size(); a[i] -= b[i], i++) {
      if (a[i] < b[i]) {
        int j = i + 1;
        while (!a[j]) j++;
        while (j > i) {
          --a[j];
          a[--j] += BASE;
        }
      }
    }
    while (a.size() >= 2 && !a.back()) a.pop_back();
    return a;
  }
  void operator -= (const Big &b) {
    (*this) = (*this) - b;
  }
};

istream& operator >> (istream &is, Big &b) {
  string str;
  is >> str;
  b = str;
  return is;
}

ostream& operator << (ostream &os, const Big &b) {
  os << b.back();
  for (int i = b.size() - 2; i >= 0; i--) {
    os << setw(WIDTH) << setfill('0') << b[i];
  }
  return os;
}

Big gcd(Big &a, Big &b, Big &p) {
  if (b == 0) return a;
  while (!a.mod2() && !b.mod2()) {
    a.div2();
    b.div2();
    p = p * 2;
  }
  while (!a.mod2()) {
    a.div2();
  }
  while (!b.mod2()) {
    b.div2();
  }
  if (a < b) swap(a, b);
  a -= b;
  return gcd(b, a, p);
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  Big a, b, c(1);
  cin >> a >> b;

  Big g = gcd(a, b, c);
  cout << g * c << '\n';

  return 0;
}