#include <bits/stdc++.h>
#define int long long

int a[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool check(std::string s) {
  auto t = s;
  std::reverse(s.begin(), s.end());
  if (s != t) return false;
  int m = std::stoll(s.substr(4, 2));
  int d = std::stoll(s.substr(6, 2));
  if (m >= 1 && m <= 12 && d >= 1 && d <= a[m]) {
    return true;
  }
  return false;
}

void solve() {
  std::string str;
  std::cin >> str;
  int y = std::stoll(str.substr(0, 4));
  if (check(str)) {
    std::cout << str << '\n';
    return;
  }
  while (1) {
    y++;
    std::stringstream ss;
    ss << std::setw(4) << std::setfill('0') << y;
    std::string s;
    ss >> s;
    auto t = s;
    std::reverse(t.begin(), t.end());
    if (check(s + t)) {
      std::cout << (s + t) << '\n';
      return;
    }
  }
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}