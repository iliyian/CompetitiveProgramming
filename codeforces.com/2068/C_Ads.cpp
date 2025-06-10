// date: 2025-03-15 19:35:04
// tag: 神奇贪心，分组问题，依次考虑两个条件

#include <bits/stdc++.h>
#define int long long

void solve(int t) {
  int n, k;
  std::cin >> n >> k;
  std::multiset<int> s;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    s.insert(a[i]);
  }
  // if (t == 591) {
    // assert(*s.begin() >= k);
    // assert(n == 3);
  // }
  int ans = -1;
  while (s.size() >= 3) {
    auto x = *s.begin();
    auto p = s.lower_bound(k - x);
    if (p == s.begin()) break;
    p = std::prev(p);
    if (p == s.begin()) break;
    s.erase(p);
    s.erase(std::prev(s.end()));
    s.erase(s.begin());
    ans++;
  }
  while (s.size() >= 2) {
    if (*s.begin() >= k) break;
    s.erase(s.begin());
    s.erase(std::prev(s.end()));
    ans++;
  }
  ans += s.size();
  std::cout << ans << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  for (int i = 1; i <= t; i++) {
    solve(i);
  }
  return 0;
}