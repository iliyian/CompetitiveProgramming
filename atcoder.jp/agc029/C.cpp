// date: 2024-08-02 11:06:50
// tag: 构造，字符串

#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);

  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }

  std::stack<std::pair<int, int>> s;

  auto insert = [&](auto self, int p, int mid) -> void {
    while (!s.empty() && s.top().first > p) s.pop();
    if (s.top().first == p) {
      s.top().second++;
    } else {
      s.push({p, 1});
    }
    if (s.top().second == mid) {
      s.pop();
      self(self, p - 1, mid);
    }
  };

  auto check = [&](int mid) -> bool {
    s.push({0, 0});
    for (int i = 1; i < n; i++) {
      if (a[i] >= a[i + 1]) {
        if (mid == 1) {
          while (!s.empty()) s.pop();
          return false;
        }
        insert(insert, a[i + 1], mid);
      }
    }
    while (s.size() > 1) s.pop();
    bool f = s.top().second; s.pop();
    return !f;
  };

  int l = 1, r = n, ans = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(mid)) r = mid - 1, ans = mid;
    else l = mid + 1;
  }
  std::cout << ans << '\n';

  return 0;
}