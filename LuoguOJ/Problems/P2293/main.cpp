// date: 2024-04-03 21:08:44
// tag: 高精度开根号，二分
// tle#01: 二分的初始范围太大了
// re#02: 没有特判0导致的二分减法出现小减大

#include <bits/stdc++.h>
#define int long long
#define WIDTH 8
#define BASE 100000000
using namespace std;

struct Big:vector<int> {
  Big() {push_back(0);}
  Big(int x) {
    push_back(x);
  }
  Big(int n, int x) {
    assign(n, x);
  }
  void operator = (const string &s) {
    clear();
    int len = (s.size() - 1) / WIDTH + 1;
    for (int i = 0; i < len; i++) {
      int r = s.size() - i * WIDTH;
      int l = max(0ll, r - WIDTH);
      push_back(stoi(s.substr(l, r - l)));
    }
  }
  void trim() {
    while (size() >= 2 && !back()) pop_back();
  }
  string str() const { // for better gdb debug
    string s = to_string(back());
    for (int i = size() - 2; i >= 0; i--) {
      string cur = to_string((*this)[i]);
      for (int j = 0; j < WIDTH - cur.size(); j++) {
        s.push_back('0');
      }
      s.append(cur);
    }
    return s;
  }
  Big operator + (const Big &b) {
    Big a(max(b.size(), size()) + 1, 0);
    for (int i = 0; i < a.size(); i++) {
      if (i < size()) a[i] += (*this)[i];
      if (i < b.size()) a[i] += b[i];
      a[i + 1] += a[i] / BASE;
      a[i] %= BASE;
    }
    a.trim();
    return a;
  }
  Big operator - (const Big &b) {
    // assert(b < *this);
    Big a = *this;
    for (int i = 0; i < b.size(); a[i] -= b[i], i++) {
      if (a[i] < b[i]) {
        int j = i + 1;
        while (!a[j]) j++;
        while (j > i) {
          --a[j--];
          a[j] += BASE; // what?
        }
      }
    }
    a.trim();
    return a;
  }
  Big operator * (const Big &b) {
    Big c(size() + b.size() + 1, 0);
    for (int i = 0; i < size(); i++) {
      for (int j = 0; j < b.size(); j++) {
        c[i + j] += (*this)[i] * b[j];
        c[i + j + 1] += c[i + j] / BASE;
        c[i + j] %= BASE;
      }
    }
    c.trim();
    return c;
  }
  Big operator / (int x) {
    Big c(size(), 0);
    int down = 0;
    for (int i = size() - 1; i >= 0; i--) {
      int cur = (*this)[i] + down * BASE;
      c[i] = cur / x;
      down = cur - c[i] * x;
    }
    c.trim();
    return c;
  }
  Big pow(int n) {
    Big ans(1), a(*this);
    while (n) {
      if (n & 1) ans = ans * a;
      a = a * a;
      n >>= 1;
    }
    return ans;
  }
  Big root(int x) {
    Big l(0), r(1), ans(0), n(*this);
    while (r.pow(x) <= n) {
      l = r;
      r = r * 2;
    }
    while (l <= r) {
      Big mid = (l + r) / 2;
      if (mid.pow(x) <= n) l = mid + Big(1), ans = mid;
      else r = mid - Big(1);
    }
    return ans;
  }
  bool operator < (const Big &b) const {
    if (size() != b.size()) return size() < b.size();
    for (int i = size() - 1; i >= 0; i--) {
      if ((*this)[i] != b[i]) {
        return (*this)[i] < b[i];
      }
    }
    return false;
  }
  bool operator <= (const Big &b) {
    return *this < b || *this == b;
  }
  bool operator > (const Big &b) {
    return !(*this <= b);
  }
  bool operator >= (const Big &b) {
    return !(*this < b);
  }
};

ostream& operator << (ostream &os, const Big &b) {
  os << b.str();
  return os;
}

istream& operator >> (istream &is, Big &b) {
  string s;
  is >> s;
  b = s;
  return is;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int m;
  Big n;
  cin >> m >> n;
  Big t = n.root(m);
  Big c(t.size() - 1, 0);
  c.push_back(pow(10, to_string(t.back()).size() - 1));
  cout << (t - c) / 2 << '\n';

  return 0;
}