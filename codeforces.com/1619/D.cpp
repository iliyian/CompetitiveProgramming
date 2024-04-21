// date: 2024-04-20 19:21:09
// tag: 二分，容斥

#include <bits/stdc++.h>
#define int long long
#define N 100005
using namespace std;

vector<int> cnt(N);

void solve() {
  int m, n;
  cin >> m >> n;
  vector<vector<int>> a(m + 1, vector<int>(n + 1));
  int r = 0;
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
      r = max(r, a[i][j]);
    }
  }
  auto check = [&](int mid) {
    bool f1 = false;
    fill(cnt.begin() + 1, cnt.begin() + m + 1, 0);
    for (int j = 1; j <= n; j++) {
      bool f2 = false;
      for (int i = 1; i <= m; i++) {
        if (a[i][j] >= mid) {
          cnt[i]++;
          f1 |= cnt[i] >= 2;
          f2 = true;
        }
      }
      if (!f2) {
        return false;
      }
    }
    return f1;
  };
  int l = 1, ans = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(mid)) l = mid + 1, ans = mid;
    else r = mid - 1;
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}