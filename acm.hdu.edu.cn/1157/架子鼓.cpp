#include <bits/stdc++.h>
#define int long long

struct Frac {
  int a, b;
  Frac operator+(const Frac &c) {
    int aa = a * c.b + b * c.a;
    int bb = b * c.b;
    int g = std::gcd(aa, bb);
    return {aa / g, bb / g};
  }
  bool operator == (Frac c) {
    return a == c.a && b == c.b;
  }
  bool operator != (Frac c) {
    return !(*this == c);
  }
  bool operator < (Frac c) {
    return a * c.b < c.a * b;
  }
};

void solve() {
  int n1, n2;
  std::cin >> n1 >> n2;
  std::vector<Frac> a, b;
  Frac s = {0, 0};
  for (int i = 1; i <= n1; i++) {
    int p, q;
    std::cin >> p >> q;
    a.push_back(s);
    if (i == 1) {
      s = {p, q};
    } else {
      s = s + Frac{p, q};
    }
  }
  s = {0, 0};
  for (int i = 1; i <= n2; i++) {
    int p, q;
    std::cin >> p >> q;
    b.push_back(s);
    if (i == 1) {
      s = {p, q};
    } else {
      s = s + Frac{p, q};
    }
  }
  int ans = 0;
  for (int l = 0, r = 0; l < a.size(); l++) {
    while (r < b.size() && b[r] < a[l]) {
      r++;
    }
    if (r < b.size() && a[l] == b[r]) {
      ans++;
      r++;
    }
  } 
  std::cout << ans << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}