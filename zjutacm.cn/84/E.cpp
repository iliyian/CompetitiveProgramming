#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  std::vector<int> st;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    while (!st.empty() && st.back() >= a[i]) {
      st.pop_back();
    }
    int cur = 0, money = a[i], p = st.size() - 1;
    while (!st.empty() && p != st.size() && money) {
      cur += money / st[p];
      money %= st[p];
      auto nxt = std::lower_bound(st.begin(), st.begin() + p, money) - st.begin();
      if (nxt == p) break;
      p = nxt;
      // std::cout << money << '\n';
    }
    ans = std::max(ans, cur);
    st.push_back(a[i]);
  }
  std::cout << ans << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}