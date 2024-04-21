#include <bits/stdc++.h>
#define int long long
using namespace std;

// 1 3 6 10 15
vector<int> mi(151, 0x3f3f3f3f);
int d[5] = {1, 3, 6, 10, 15};

void solve() {
  int n;
  cin >> n;
  int ans = 0;
  map<int, int> cnt;

  map<int, int> vis;
  auto dfs = [&](auto self, int last, int rest) {
    if (rest == 0) {
      // ans = min(ans, cnt);
      return;
    }
    // if (vis[rest] && vis[rest] < cnt) return;
    // vis[rest] = cnt;
    if (rest < d[last]) {
      self(self, last - 1, rest);
      return;
    }
    int use = rest / d[last];
    ans += use;
    cnt[d[last]] += use;
    self(self, last - 1, rest - use * d[last]);
    // for (int i = 1; i <= use; i++) {
    //   self(self, last > 0 ? last - 1 : 0, rest - i * d[last], cnt + i);
    // }
  };
  dfs(dfs, 4, n);
  int c = 0, s = 0;
  for (auto [k, v]: cnt) {
    if (k < 15) {
      c += v;
      s += k * v;
    }
  }
  if (cnt[15] != 0) {
    ans -= c + 1;
    ans += mi[s + 15];
  }
  if (n < 151) ans = min(ans, mi[n]);
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);

  int _;
  cin >> _;


  auto dfs0 = [&](auto self, int dep, int sum) {
    if (dep == 10) {
      return;
    }
    mi[sum] = min(mi[sum], dep);
    for (int i = 0; i < 5; i++) {
      self(self, dep + 1, sum + d[i]);
    }
  };
  dfs0(dfs0, 0, 0);

  while (_--) {
    solve();
  }

  return 0;
}