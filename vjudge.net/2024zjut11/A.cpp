#include <bits/stdc++.h>
#define int long long
#define lc p << 1
#define rc p << 1 | 1
using namespace std;

void solve() {
  int n, q;
  cin >> n >> q;
  vector<int> d((n + 5) << 2);
  auto add = [&](auto self, int x, int s, int t, int p, int c) {
    if (s == x && s == t) {
      d[p] += c;
      return;
    }
    int mid = s + (t - s >> 1);
    if (x <= mid) self(self, x, s, mid, lc, c);
    else self(self, x, mid + 1, t, rc, c);
    d[p] = d[lc] + d[rc];
  };
  auto query = [&](auto self, int l, int r, int s, int t, int p) ->int {
    if (l <= s && t <= r) return d[p];
    int mid = s + (t - s >> 1), ans = 0;
    if (l <= mid) ans += self(self, l, r, s, mid, lc);
    if (r > mid) ans += self(self, l, r, mid + 1, t, rc);
    return ans;
  };
  for (int t = 0; t < q; t++) {
    char op;
    int l, r, x;
    cin >> op;
    if (op == '+') {
      cin >> x;
      add(add, x, 1, n, 1, -1);
      // add(add, x + n, 1, n * 2, 1, 1);
    } else if (op == '-') {
      cin >> x;
      add(add, x, 1, n, 1, 1);
      // add(add, x + n, 1, n * 2, 1, -1);
    } else {
      cin >> l >> r;
      if (l > r) swap(l, r);
      int ans1 = query(query, l, r, 1, n, 1);
      int ans2 = query(query, 1, l, 1, n, 1) + query(query, r, n, 1, n, 1);
      if (!ans1 || !ans2) {
        cout << "possible\n";
      } else {
        cout << "impossible\n";
      }
    }
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);

  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}