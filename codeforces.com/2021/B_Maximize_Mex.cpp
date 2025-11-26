#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, x;
  std::cin >> n >> x;
  std::map<int, int> cnt;
  for (int i = 1; i <= n; i++) {
    int x;
    std::cin >> x;
    cnt[x]++;
  }
  for (int i = 0;; i++) {
    if (!cnt.count(i)) {
      std::cout << i << '\n';
      return;
    }
    if (cnt[i] > 1) {
      cnt[i + x] += cnt[i] - 1;
    }
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