// date: 2024-04-24 17:52:08
// tag: 

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1), s(n + 1);
  vector<vector<int>> val(n + 1, vector<int>(n + 1));
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    s[i] = s[i - 1] + a[i];
  }
  vector<vector<int>> f(n + 1, vector<int>(n + 1));
  for (int l = 1; l <= n; l++) {
    for (int r = l; r <= n; r++) {
      val[l][r] = max((r - l + 1) * (r - l + 1), s[r] - s[l - 1]);
      f[l][r] = val[l][r];
    }
  }
  vector<vector<int>> prv(n + 1, vector<int>(n + 1));
  for (int len = 2; len <= n; len++) {
    for (int l = 1; l + len - 1 <= n; l++) {
      int r = l + len - 1;
      for (int mid = l + 1; mid <= r; mid++) {
        int t = f[l][mid - 1] + f[mid][r];
        if (f[l][r] < t) {
          f[l][r] = t;
          prv[l][r] = mid;
        }
      }
    }
  }
  vector<pair<int, int>> ans;
  vector<int> cnt(n + 1);
  auto mex = [&](int l, int r) {
    for (int i = l; i <= r; i++) {
      cnt[a[i]]++;
    }
    for (int i = 0;; i++) {
      if (!cnt[i]) {
        for (int i = l; i <= r; i++) {
          cnt[a[i]] = 0;
        }
        return i;
      }
    }
  };
  auto change = [&](auto self, int l, int r) -> void {
    // if (mex(l, r) == r - l + 1) return;
    if (r == l) {
      return;
    }
    self(self, l, r - 1);
    ans.push_back({l, r});
    ans.push_back({l, l});
    self(self, l, r - 1);
  };
  auto dfs = [&](auto self, int l, int r) -> void {
    int mid = prv[l][r];
    if (mid) {
      self(self, l, mid - 1);
      self(self, mid, r);
    }
    int len = r - l + 1;
    if (len * len == f[l][r] && s[r] - s[l - 1] != f[l][r]) {
      for (int i = l; i <= r; i++) {
        if (a[i]) {
          ans.push_back({i, i});
        }
      }
      change(change, l, r);
      ans.push_back({l, r});
    }
  };
  dfs(dfs, 1, n);
  cout << f[1][n] << ' ' << ans.size() << '\n';
  for (auto [l, r] : ans) {
    cout << l << ' ' << r << '\n';
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  solve();

  return 0;
}