// date: 2024/02/22 15:20:28
// tag: 理论上时间复杂度是对的

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// #define int long long
#define lc p << 1
#define rc p << 1 | 1
using namespace std;
using namespace __gnu_pbds;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  // tree<int, null_type, less<int>, splay_tree_tag, tree_order_statistics_node_update> s;
  // for (int i = 1; i <= n; i++) {
  //   s.insert(i);
  // }
  vector<int> d(n + 5 << 2);
  auto build = [&d](auto self, int l, int r, int p) {
    if (l == r) {
      d[p] = 1;
      return;
    }
    int mid = l + (r - l >> 1);
    self(self, l, mid, lc);
    self(self, mid + 1, r, rc);
    d[p] = d[lc] + d[rc];
  };
  auto query = [&d](auto self, int l, int r, int s, int t, int p) {
    if (l <= s && t <= r) return d[p];
    int mid = s + (t - s >> 1), ans = 0;
    if (l <= mid) ans += self(self, l, r, s, mid, lc);
    if (r > mid) ans += self(self, l, r, mid + 1, t, rc);
    return ans;
  };
  auto add = [&d](auto self, int x, int s, int t, int p, int c) {
    if (s == x && s == t) {
      d[p] += c;
      return;
    }
    int mid = s + (t - s >> 1);
    if (x <= mid) self(self, x, s, mid, lc, c);
    else self(self, x, mid + 1, t, rc, c);
    d[p] = d[lc] + d[rc];
  };
  auto ask = [&](auto choice) {
    int l = 1, r = n, ans = -1;
    while (l <= r) {
      int mid = l + (r - l >> 1);
      if (query(query, 1, mid, 1, n, 1) >= choice)
        ans = mid, r = mid - 1;
      else l = mid + 1;
    }
    return ans;
  };
  for (int i = 1; i <= n / 2; i++) {
    cin >> a[i * 2 - 1];
  }
  for (int i = 1; i <= n / 2; i++) {
    cin >> a[i * 2];
  }
  build(build, 1, n, 1);
  vector<int> ans(n + 1);
  for (int i = 1; i <= n / 2; i++) {
    int k = ask(a[i * 2 - 1]);
    ans[i * 2 - 1] = k;
    add(add, k, 1, n, 1, -1);

    k = ask(a[i * 2]);
    ans[i * 2] = k;
    add(add, k, 1, n, 1, -1);
  }
  for (int i = 1; i <= n / 2; i++) {
    cout << ans[i * 2 - 1] << ' ';
  }
  cout << '\n';
  for (int i = 1; i <= n / 2; i++) {
    cout << ans[i * 2] << ' ';
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);

  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}