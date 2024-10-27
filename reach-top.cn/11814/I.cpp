#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::vector<int> a(n + 1), cnt(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    cnt[a[i]]++;
  }
  for (int i = 1; i <= n; i++) {
    cnt[i] += cnt[i - 1];
  }
  std::vector<int> ans(n + 1);
  auto query = [&](int l, int r) {
    if (l <= 0) return cnt[r];
    if (r > n) r = n;
    return cnt[r] - cnt[l - 1];
  };
  auto check = [&](int m, int mid) -> int {
    int c = 0;
    for (int i = 0; i <= n; i += m) {
      c += query(i, i + mid);
    }
    return c;
  };
  for (int m = 1; m <= n; m++) {
    int l = 0, r = m - 1, anss = -1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (check(m, mid) > n / 2) r = mid - 1, anss = mid;
      else l = mid + 1;
    }
    ans[m] = anss;
  }
  while (q--) {
    int x;
    std::cin >> x;
    std::cout << ans[x] << ' ';
  }
  std::cout << '\n';
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