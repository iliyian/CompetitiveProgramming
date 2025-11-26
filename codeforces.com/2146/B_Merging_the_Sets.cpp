#include <bits/stdc++.h>
#define int long long

void solve() {
  int m, n;
  std::cin >> m >> n;
  std::vector<std::vector<int>> a(m + 1);
  std::vector<int> cnt(n + 1);
  for (int i = 1; i <= m; i++) {
    int l;
    std::cin >> l;
    for (int j = 1; j <= l; j++) {
      int x;
      std::cin >> x;
      a[i].push_back(x);
      cnt[x]++;
    }
  }
  if (*std::min_element(cnt.begin() + 1, cnt.end()) == 0) {
    std::cout << "NO" << '\n';
    return;
  }
  int ans = 0;
  for (int i = 1; i <= m; i++) {
    bool f = true;
    for (auto j : a[i]) {
      cnt[j]--;
      if (cnt[j] == 0) {
        f = false;
      }
    }
    ans += f;
    for (auto j : a[i]) {
      cnt[j]++;
    }
  }
  std::cout << (ans >= 2 ? "YES" : "NO") << '\n';
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