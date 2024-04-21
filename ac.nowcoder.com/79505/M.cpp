#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1), pa(n * 2 + 1), siz(n * 2 + 1);
  iota(pa.begin(), pa.end(), 0);
  fill(siz.begin(), siz.end(), 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  auto find = [&](auto self, int x) -> int {
    return x == pa[x] ? x : pa[x] = self(self, pa[x]);
  };
  auto merge = [&](int x, int y) {
    x = find(find, x), y = find(find, y);
    pa[x] = y;
  };
  for (int i = 1; i <= n; i++) {
    if (find(find, i) == find(find, i + n)) {
      cout << -1 << '\n';
      return;
    }
    if (a[i] > i * 2 - 1 || a[i] > (n - i + 1) * 2 - 1) {
      cout << -1 << '\n';
      return;
    }
    if (a[i] > 1) {
      int j;
      for (j = 0; j < a[i] / 2; j++) {
        if (find(find, j) == find(find, j + n)) {
          cout << -1 << '\n';
          return;
        }
        int l = i - j - 1, r = i + j + 1;
        merge(l, r);
        merge(l + n, r + n);
      }
      int l = i - j - 1, r = i + j + 1;
      if (l >= 1 && r <= n) {
        merge(r + n, l);
        merge(r, l + n);
      }
    } else if (a[i] == 1 && i != 1 && i != n) {
      merge(i + 1 + n, i - 1);
      merge(i + 1, i - 1 + n);
    }
  }
  vector<int> ans(n + 1);
  for (int i = 1; i <= n; i++) {
    if (find(find, i) == find(find, i + n)) {
      cout << -1 << '\n';
      return;
    }
    if (find(find, i) <= n) {
      ans[i] = 1;
    } else {
      ans[i] = 0;
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[i];
  }
  cout << '\n';
  // cout << "OK" << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("M.in", "r", stdin);
  freopen("M.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}