// date: 2025-03-26 14:56:41
// tag: 最讨厌做这种分类讨论的题目了，真就全是分讨，贪心

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 2);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  int l = 0, r = 0, ans = 0;
  for (int i = 1; i <= n; i++) {
    if (!a[i]) {
      l = 0, r = 0;
      continue;
    }
    if (a[i] <= 2) {
      r = 0;
      if (l) {
        l = 0;
        continue;
      }
      l = 1, ans++;
      continue;
    }
    if (a[i] <= 4) {
      if (l && r) continue;
      if (!l && !r) {
        ans++;
        continue;
      }
      l ^= 1, r ^= 1;
      ans++;
    } else {
      ans++;
      l = 0, r = 0;
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