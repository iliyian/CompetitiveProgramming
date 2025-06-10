#include <bits/stdc++.h>
#define int long long

int d[] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int isleap(int n) {
  return n % 4 == 0 && n % 100 != 0 || (n % 400 == 0);
}

int getd(int y, int m) {
  if (m == 2 && isleap(y)) return 29;
  return d[m];
}

struct Date {
  int y, m, d, h, min, s;
  Date() {}
  Date(const std::string &str) {
    y = stoll(str.substr(0, 4));
    m = stoll(str.substr(5, 2));
    d = stoll(str.substr(8, 2));
    h = stoll(str.substr(11, 2));
    min = stoll(str.substr(14, 2));
    s = stoll(str.substr(17, 2));
  };
  void addHour() {
    h++;
    if (h == 24) {
      h = 0;
      d++;
      if (d == getd(y, m) + 1) {
        d = 1;
        m++;
        if (m == 13) {
          y++;
          m = 1;
        }
      }
    }
  }
  bool operator < (const Date &x) const {
    return std::tie(y, m, d, h, min, s) < std::tie(x.y, x.m, x.d, x.h, x.min, x.s);
  }
  bool operator <= (const Date &x) const {
    return std::tie(y, m, d, h, min, s) <= std::tie(x.y, x.m, x.d, x.h, x.min, x.s);
  }
};

void solve() {
  std::string s, t;
  std::cin >> s >> t;
  Date x(s), y(t);
  for (int i = 0; i < 8; i++) {
    x.addHour();
  }
  if (x <= y) {
    std::cout << "Yes\n";
  } else {
    std::cout << "No\n";
  }
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