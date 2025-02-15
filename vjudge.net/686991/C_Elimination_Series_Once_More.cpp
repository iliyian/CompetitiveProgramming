#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, K;
  std::cin >> n >> K;
  std::vector<int> a(1 << n), tmp(1 << n);
  for (int i = 0; i < (1 << n); i++) {
    std::cin >> a[i];
    // a[i]--;
    tmp[i] = a[i];
  }
  std::vector<int> ans(1 << n | 1);
  auto work = [&](auto &&self, int l, int r, int dep) {
    if (l + 1 == r) return;
    int mid = (l + r) / 2;
    self(self, l, mid, dep - 1);
    self(self, mid, r, dep - 1);
    int i = l, j = mid, k = 0;
    std::vector<int> b(r - l);
    while (i < mid && j < r) {
      if (a[i] < a[j]) {
        b[k++] = a[i++];
      } else {
        b[k++] = a[j++];
      }
    }
    while (i < mid) b[k++] = a[i++];
    while (j < r) b[k++] = a[j++];
    for (int i = 0; i < r - l; i++) {
      if (r - l - 1 - i <= K && b[i] >= (1 << dep)) {
        ans[b[i]] = std::max(ans[b[i]], dep);
      }
      a[l + i] = b[i];
    }
  };
  work(work, 0, 1 << n, n);
  for (int i = 0; i < (1 << n); i++) {
    std::cout << ans[tmp[i]] << " ";
  }
  std::cout << "\n";
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