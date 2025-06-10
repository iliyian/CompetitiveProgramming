// date: 2025-05-01 21:06:09
// tag: 构造题的关键在于框架和给予的限制，这是土壤和根

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  std::vector<int> ans(n + 1);
  int f = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    if (a[i] == 1) {
      f = i & 1;
    }
  }
  std::vector<int> p;
  std::set<int> s;
  for (int i = 1; i <= n; i++) {
    s.insert(i);
  }
  for (int i = 1; i <= n; i++) {
    if ((i & 1) != f) {
      ans[i] = n + 2 - a[i];
      s.erase(ans[i]);
    } else {
      p.push_back(i);
    }
  }
  std::sort(p.begin(), p.end(), [&](const int &x, const int &y) {
    return a[x] > a[y];
  });
  for (int i : p) {
    ans[i] = *s.begin();
    s.erase(s.begin());
  }
  for (int i = 1; i <= n; i++) {
    std::cout << ans[i] << " \n"[i == n];
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