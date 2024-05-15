// date: 2024-05-14 18:19:54
// tag: st表，单调队列优化二分
// 注意别mle
// 直接前缀和即可

#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  int lg = __lg(n) + 1;
  vector<vector<int>> a(n + 1, vector<int>(m + 1));
  vector<vector<vector<int>>> st(m + 1, vector<vector<int>>(n + 1, vector<int>(lg + 1, INT_MAX)));
  auto querymin = [&](int c, int l, int r) {
    int len = __lg(r - l + 1);
    return min(st[c][l][len], st[c][r - (1 << len) + 1][len]);
  };
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  for (int c = 1; c <= m; c++) {
    auto &s = st[c];
    for (int i = 1; i <= n; i++) {
      s[i][0] = a[i][c];
    }
    for (int len = 1; len <= lg; len++) {
      for (int i = 1; i + (1 << (len - 1)) <= n; i++) {
        s[i][len] = min(s[i][len - 1], s[i + (1 << (len - 1))][len - 1]);
      }
    }
  }
  auto check = [&](int mid) {
    for (int row = 1; row + mid - 1 <= n; row++) {
      deque<int> q;
      for (int i = 1; i <= m; i++) {
        while (!q.empty() && q.front() < i - mid + 1) {
          q.pop_front();
        }
        int cur = querymin(i, row, row + mid - 1);
        while (!q.empty() && querymin(q.back(), row, row + mid - 1) >= cur) {
          q.pop_back();
        }
        q.push_back(i);

        if (i >= mid && querymin(q.front(), row, row + mid - 1) >= mid) {
          return true;
        }
      }
    }
    return false;
  };
  int l = 1, r = min(n, m), ans = -1;
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