// date: 2025-04-17 21:32:22
// tag: 数学推论题，还是挺欣慰自己还是做出来了的，不考虑时间因素的话......，其实只要一步一步推理即可，然后再上点正难则反的技巧？

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<std::pair<int, int>> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i].second;
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i].first;
  }
  std::sort(a.begin() + 1, a.end(), std::greater<>());
  std::vector<int> s(n + 2);
  for (int i = n; i >= 1; i--) {
    s[i] = s[i + 1] + std::max(0ll, a[i].first - a[i].second);
  }
  int ans = 0, sum = 0;
  std::priority_queue<int> q;
  for (int i = 1; i <= n; i++) {
    if (i > k) {
      ans = std::max(ans, s[i] - sum);
    }
    q.push(a[i].second);
    sum += a[i].second;
    if (q.size() > k) {
      sum -= q.top(); q.pop();
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