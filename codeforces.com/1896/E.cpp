#include <bits/stdc++.h>
#define int long long
#define lc p << 1
#define rc p << 1 | 1
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n * 2 + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i + n] = a[i] + n;
  }
  vector<int> h(n * 2 + 1);
  for (int i = 1; i <= n; i++) {
    h[i] = (a[i] - i + n) % n;
    // if (a[i] >= i) {
    //   h[i] = a[i] - i;
    // } else {
    //   h[i] = a[i] + n - i;
    // }
  }

  vector<int> d((n * 2 + 5) << 2);

  auto pushup = [&](int p) {
    d[p] = d[lc] + d[rc];
  };

  auto add = [&](auto self, int x, int s, int t, int p) -> void {
    if (s == t && s == x) {
      d[p]++;
      return;
    }
    int mid = s + (t - s >> 1);
    if (x <= mid) self(self, x, s, mid, lc);
    else self(self, x, mid + 1, t, rc);
    pushup(p);
  };

  auto query = [&](auto self, int l, int r, int s, int t, int p) -> int {
    if (l <= s && t <= r) return d[p];
    int mid = s + (t - s >> 1), ans = 0;
    if (l <= mid) ans += self(self, l, r, s, mid, lc);
    if (r > mid) ans += self(self, l, r, mid + 1, t, rc);
    return ans;
  };

  for (int i = 1; i <= n; i++) {
    if (a[i] >= i) { // a[i] do not cycle
      add(add, a[i], 1, n * 2, 1);
      add(add, a[i + n], 1, n * 2, 1);
    } else {
      add(add, a[i] + n, 1, n * 2, 1);
    }
  }

  vector<int> ans(n + 1);
  for (int i = 1; i <= n; i++) {
    // if (h[i] <= 1) {
    //   ans[a[i]] = h[i];
    //   continue;
    // }
    ans[a[i]] = h[i] - query(query, i + 1, i + h[i] - 1, 1, n * 2, 1);
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << " \n"[i == n];
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}