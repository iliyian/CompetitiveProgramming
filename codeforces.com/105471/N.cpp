#include <bits/stdc++.h>
#define int long long

void solve() {
  std::string str;
  std::cin >> str;
  std::string I, J;
  std::string range, in;
  std::cin >> str >> I >> in >> range;
  int dot1 = range.find(','), a, b, c;
  int l = range.find('('), r = range.find(')');
  a = std::stoll(range.substr(l + 1, dot1 - l - 1));
  int dot2 = range.find(',', dot1 + 1);
  if (dot2 == range.npos) {
    b = std::stoll(range.substr(dot1 + 1, r - dot1 - 1));
    c = 1;
  } else {
    b = std::stoll(range.substr(dot1 + 1, dot2 - dot1 - 1));
    c = std::stoll(range.substr(dot2 + 1, r - dot2 - 1));
  }
  
  std::cin >> str >> J >> in >> range;
  int d, e, f;

  l = range.find('('), r = range.find(')');
  dot1 = range.find(',');
  dot2 = range.find(',', dot1 + 1);

  int ans = 0;
  for (int i = a; (c > 0 ? i < b : i > b); i += c) {
    std::string x = range.substr(l + 1, dot1 - l - 1), y, z;

    if (dot2 == range.npos) {
      y = range.substr(dot1 + 1, r - dot1 - 1);
      z = "1";
    } else {
      y = range.substr(dot1 + 1, dot2 - dot1 - 1);
      z = range.substr(dot2 + 1, r - dot2 - 1);
    }

    int d = (x == I ? i : std::stoll(x));
    int e = (y == I ? i : std::stoll(y));
    int f = (z == I ? i : std::stoll(z));
    // std::cout << d << ' ' << e << ' ' << f << '\n';

    if (d < e && f < 0 || d >= e && f > 0) continue;
    int t = std::ceil(double(e - d) / f);
    int to = d + (t - 1) * f;
    // std::cout << to << ' ' << d << ' ' << t << '\n';
    ans += (to + d) * t / 2;
    // std::cout << (to + d) * t / 2 << '\n';
  }
  std::cin >> str;
  std::cin >> str;
  std::cout << ans << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}