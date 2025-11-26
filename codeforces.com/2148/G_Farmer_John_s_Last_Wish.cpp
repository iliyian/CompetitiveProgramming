#include <bits/stdc++.h>
#define int long long

constexpr int N = 2e5;
std::vector<std::vector<int>> fac(N + 1);

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  std::vector<int> cnt(n + 1);
  int ans = 0;
  std::vector<int> v, vis(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    std::vector<int> cur;
    for (int j : fac[a[i]]) {
      cnt[j]++;
      vis[j] = 1;
      if (cnt[j] == i) {
        cur.push_back(j);
      } else {
        ans = std::max(ans, cnt[j]);
      }
    }
    for (int j : v) {
      if (!vis[j]) {
        ans = i - 1;
      }
    }
    for (int j : fac[a[i]]) {
      vis[j] = 0;
    }
    v = cur;
    std::cout << ans << ' ';
  }
  std::cout << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  for (int i = 1; i <= N; i++) {
    for (int j = i; j <= N; j += i) {
      fac[j].push_back(i);
    }
  }

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}