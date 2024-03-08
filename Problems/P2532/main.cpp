// date: 2024-03-07 14:19:29
// tag: wa#01:循环i写成n，高精度写错
// wa#02:高精度/低精度循环方向写错，高精度*低精度没有用新变量存

#include <bits/stdc++.h>
// #define int long long
#define BASE 10000
#define WIDTH 4
using namespace std;

struct Big:vector<int> {
  Big(int x) {
    clear();
    push_back(x);
  }
  Big(int n, int x) {
    clear();
    assign(n, x);
  }
  Big operator * (int x) {
    Big c(size(), 0);
    for (int i = 0; i < size() - 1; i++) {
      c[i] += (*this)[i] * x;
      c[i + 1] += c[i] / BASE;
      c[i] %= BASE;
    }
    c.back() += back() * x;
    while (c.back() >= BASE) {
      c.push_back(c.back() / BASE);
      c[c.size() - 2] %= BASE;
    }
    return c;
  }
  Big operator / (int x) {
    Big c(size(), 0);
    int down = 0;
    for (int i = size() - 1; i >= 0; i--) {
      int t = (*this)[i] + down * BASE;
      c[i] = t / x;
      down = t - c[i] * x;
    }
    while (c.size() >= 2 && !c.back()) c.pop_back();
    return c;
  }
};

ostream& operator << (ostream &os, const Big &b) {
  os << b.back();
  for (int i = b.size() - 2; i >= 0; i--) {
    os << setw(WIDTH) << setfill('0') << b[i];
  }
  return os;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n;
  cin >> n;

  Big ans(1), pre(1);
  for (int i = 2; i <= n; i++) {
    ans = pre * (4 * i - 2) / (i + 1);
    pre = ans;
  }
  cout << ans << '\n';

  return 0;
}