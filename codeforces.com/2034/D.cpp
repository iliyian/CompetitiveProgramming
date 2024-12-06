// date: 2024-12-04 23:34:14
// tag: 不寻常的TLE，往往是某个地方死循环了，如check，如二分
// 模拟，贪心，构造

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  std::array<int, 3> cnt = {0, 0, 0};
  std::array<std::set<int>, 3> s;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    cnt[a[i]]++;
    s[a[i]].insert(i);
  }

  std::vector<std::pair<int, int>> ans;
  auto check = [&]() {
    if (!s[0].empty() && !s[2].empty()) {
      if (*s[0].rbegin() < *s[1].begin() && *s[1].rbegin() < *s[2].begin()) {
        return true;
      }
    } else if (s[0].empty() && !s[2].empty()) {
      if (*s[1].rbegin() < *s[2].begin()) {
        return true;
      }
    } else if (s[2].empty() && !s[0].empty()) { 
      if (*s[0].rbegin() < *s[1].begin()) {
        return true;
      }
    } else {
      return true;
    }
    return false;
  };
  while (!check()) {
    while (!s[0].empty() && !s[1].empty()) {
      int x = *s[0].rbegin(), y = *s[1].begin();
      if (x > y) {
        ans.push_back({x, y});
        s[0].erase(x);
        s[1].erase(y);
        s[0].insert(y);
        s[1].insert(x);
      } else break;
    }
    while (!s[1].empty() && !s[2].empty()) {
      int x = *s[1].rbegin(), y = *s[2].begin();
      if (x > y) {
        ans.push_back({x, y});
        s[1].erase(x);
        s[2].erase(y);
        s[1].insert(y);
        s[2].insert(x);
      } else break;
    }
  }
  std::cout << ans.size() << '\n';
  for (auto [x, y] : ans) {
    std::cout << x << ' ' << y << '\n';
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