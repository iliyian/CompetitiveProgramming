#include <bits/stdc++.h>
#define int long long

constexpr int N = 1e6;

int mex(const std::set<int> &x) {
  for (int i = 1;; i++) {
    if (!x.count(i)) {
      return i;
    }
  }
}

void solve() {
  int n, m;
  int ans = 0;
  std::cin >> n >> m;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    std::set<int> s;
    for (int j = i; j <= n; j++) {
      s.insert(a[j]);
      ans = std::max(ans, (int)s.size() - mex(s));
    }
  }
  std::cout << ans << '\n';
}

signed main() {
  freopen("I.in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}