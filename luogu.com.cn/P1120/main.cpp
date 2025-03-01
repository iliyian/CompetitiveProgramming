// date: 2024-03-02 18:26:30
// tag: 
// tle#01: 剪枝不足
// wa#02: 剪枝过多
// tle#03: 依然优化不够
// tle#04: 依然优化不够
// tle#05: 依然优化不够
// tle#06: 依然优化不够
// tle#07: 依然优化不够
// wa#08: 剪过头了
// 破案了，upper_bound没有根本没有用上last参数...

#include <bits/stdc++.h>
// #define int long long
using namespace std;

void solve() {
  int n, sum = 0;
  cin >> n;
  vector<int> a(n + 1), p(60), nxt(60);
  bitset<100> vis;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] > 50) {
      i--, n--;
      continue;
    }
    sum += a[i];
  }

  sort(a.begin() + 1, a.end());

  for (int i = 1; i <= n; i++) {
    if (a[i] != a[i - 1]) {
      nxt[a[i]] = p[a[i - 1]];
      p[a[i]] = i;
    }
  }

  auto dfs = [&](auto self, int last, int rest, int cnt, int tot) -> bool {
    if (cnt == tot) {
      return true;
    }
    if (rest == 0) {
      // for (int i = n; i >= 1; i--)
      //   if (!vis[i]) {
      //     vis[i] = true;
      //     bool f = self(self, i, sum / tot - a[i], cnt + 1, tot);
      //     vis[i] = false;
      //     return f;
      //   }
      return self(self, n + 1, sum / tot, cnt + 1, tot);
    }
    for (int i = upper_bound(a.begin() + 1, a.begin() + last, rest) - a.begin() - 1;
       i >= 1; i--) {
      if (!vis[i]) {
        vis[i] = true;
        bool f = self(self, i, rest - a[i], cnt, tot);
        vis[i] = false;
        if (f) return true;
        else if (a[i] == rest || rest == sum / tot && rest != 45) return false;
        else i = nxt[a[i]] + 1;
      }
    }
    return false;
  };

  for (int i = a[1]; i <= sum; i++) {
    if (sum % i == 0) {
      // fill(vis.begin(), vis.end(), false);
      // vis.reset();
      if (dfs(dfs, n + 1, i, 0, sum / i)) {
        cout << i << '\n';
        return;
      }
    }
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int _ = 1;

  while (_--) {
    solve();
  }

  return 0;
}