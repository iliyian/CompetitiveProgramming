#include <bits/stdc++.h>
#define int long long

void solve() {
  int a, b;
  std::cin >> a >> b;
  std::vector<int> v;
  std::string str;
  std::cin >> str;
  int c1 = 0, c2 = 0, c = 0;
  while (b > 1) c++, b >>= 1;
  for (int i = 1; i <= str.size(); i++) {
    if (i == str.size() || str[i] == 'x') {
      if (c1 != 0) {
        if (c1 == 1) {
          v.push_back(-1);
        } else {
          v.push_back(0);
        }
      } else {
        v.push_back(-c2 - 2);
      }
      c1 = c2 = 0;
    } else if (str[i] == '-') {
      c1++;
    } else {
      c2++;
    }
  }
  std::ranges::sort(v);
  std::map<int, int> mp;
  for (int i : v) {
    mp[i + c]++;
  }
  for (auto [k, v] : mp) {
    std::cerr << k << ' ' << v << '\n';
  }
  std::cerr << '\n';
  int s = 0;
  for (auto &[k, v] : mp) {
    if (v % 2) {
      if (k < 0) {
        std::cout << "ITS MY OWN INVENTION" << '\n';
        std::cerr << s << '\n';
        return;
      }
      s += v << k;
      if (k >= 60 || s > a) {
        std::cout << "ITS MY OWN INVENTION" << '\n';
        std::cerr << s << '\n';
        return;
      }
    } else {
      mp[k + 1] += v / 2;
      v = 0;
    }
  }
  // for (auto [k, v] : mp) {
  //   std::cout << k << ' ' << v << '\n';
  // }
  std::cout << "LIVE HAPPILY" << '\n';
  std::cerr << s << '\n';
  // std::cout << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  // std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}