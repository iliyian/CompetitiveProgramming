#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n), cnt(n + 1), ans(n + 2);
  int mex = 0;
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    cnt[a[i]]++;
  }
  while (cnt[mex]) mex++;
  for (int i = 0; i <= mex; i++) {
    ans[cnt[i]]++;
    ans[n - i + 1]--;
  }
  for (int i = 1; i <= n; i++) {
    ans[i] += ans[i - 1];
  }
  for (int i = 0; i <= n; i++) {
    std::cout << ans[i] << " \n"[i == n];
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