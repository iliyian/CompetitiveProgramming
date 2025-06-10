// date: 2025-04-04 12:50:09
// tag: 由于各不相同，因此最多O(n^0.5)，因此可以直接用集合，顺便还保证了外层O(n^2)的正确性

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k, e;
  std::cin >> n >> k >> e;
  std::vector<int> a(e + 1), s(k + 1);
  for (int i = 1; i <= n; i++) {
    int x;
    std::cin >> x;
    a[x] = 1;
  }
  for (int i = 1; i <= k; i++) {
    std::cin >> s[i];
  }
  std::sort(s.begin() + 1, s.end());
  std::vector<std::vector<int>> f(e + 1, {LLONG_MIN / 3});
  f[0] = {};
  std::vector<int> prv(e + 1, -1);
  for (int i = 1; i <= e; i++) {
    if (a[i]) continue;
    for (int j = 1; j <= k && s[j] <= i; j++) {
      if (!a[i - s[j]]) {
        auto tmp = f[i - s[j]];
        if (tmp.size() == 1 && tmp.front() == LLONG_MIN / 3) continue;
        tmp.push_back(s[j]);
        std::sort(tmp.begin(), tmp.end(), std::greater<>());
        if (tmp > f[i]) {
          f[i] = tmp;
          prv[i] = i - s[j];
          // std::cerr << i << ' ' << i - s[j] << '\n';
        }
      }
    }
  }
  int cur = e;
  std::stack<int> st;
  while (cur > 0) {
    st.push(cur);
    cur = prv[cur];
  }
  if (cur != 0) {
    std::cout << -1 << '\n';
    return;
  }
  std::cout << st.size() << '\n';
  while (!st.empty()) {
    std::cout << st.top() << ' '; st.pop();
  }
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