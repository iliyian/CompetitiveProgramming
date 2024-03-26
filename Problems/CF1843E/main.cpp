// date: 2024-03-26 11:33:04
// tag: 前缀和，思维

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n + 1), sm(n + 1);
  vector<tuple<int, int>> ranges(m + 1);
  for (int i = 1; i <= m; i++) {
    auto &[l, r] = ranges[i];
    cin >> l >> r;
  }
  int q;
  cin >> q;
  vector<int> qs(q + 1);
  for (int i = 1; i <= q; i++) {
    cin >> qs[i];
  }
  int l = 0, r = q, ans = -1;

  auto check = [&](int mid) -> bool {
    for (int i = 1; i <= m; i++) {
      auto &[l, r] = ranges[i];
      if (sm[r] - sm[l - 1] >= (r - l + 1) / 2 + 1) {
        return true;
      }
    }
    return false;
  };

  while (l <= r) {
    int mid = (l + r) / 2;
    fill(a.begin() + 1, a.end(), 0);
    for (int i = 1; i <= mid; i++) {
      a[qs[i]] = 1;
    }
    for (int i = 1; i <= n; i++) {
      sm[i] = sm[i - 1] + a[i];
    }
    if (check(mid)) {
      r = mid - 1, ans = mid;
    } else {
      l = mid + 1;
    }
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}