#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), siz(n + 1);
  std::set<int> s;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    s.insert(a[i]);
    siz[i] = s.size();
  }
  s.clear();
  int r = n, ans = 0;
  for (int i = n; i >= 1; i--) {
    s.insert(a[i]);
    if (s.size() == siz[r]) {
      s.clear();
      ans++;
      r = i - 1;
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