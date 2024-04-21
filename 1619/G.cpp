// date: 2024-04-21 13:58:05
// tag: 二分，贪心，模拟

#include <bits/stdc++.h>
#define int long long
#define N 200005
using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> pa(n + 1), siz(n + 1, 1);
  siz[0] = 0;
  iota(pa.begin(), pa.end(), 0);

  vector<int> id(n + 1), x(n + 1), y(n + 1), mint(n + 1);
  iota(id.begin(), id.end(), 0);
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> y[i] >> mint[i];
  }

  auto find = [&](auto self, int x) -> int {
    return x == pa[x] ? x : pa[x] = self(self, pa[x]);
  };
  auto merge = [&](int x, int y) {
    x = find(find, x), y = find(find, y);
    if (x == y) return; // 否则siz会意外变成0
    if (siz[x] > siz[y]) swap(x, y);
    pa[x] = y;
    siz[y] += siz[x];
    siz[x] = 0;
    mint[x] = mint[y] = min(mint[x], mint[y]);
  };

  sort(id.begin() + 1, id.end(), [&](const int &a, const int &b) {
    return tie(y[a], x[a]) < tie(y[b], x[b]);
  });
  for (int i = 1; i <= n - 1; i++) {
    if (y[id[i + 1]] == y[id[i]] && x[id[i + 1]] - x[id[i]] <= k) {
      merge(id[i + 1], id[i]);
    }
  }

  sort(id.begin() + 1, id.end(), [&](const int &a, const int &b) {
    return tie(x[a], y[a]) < tie(x[b], y[b]);
  });
  for (int i = 1; i <= n - 1; i++) {
    if (x[id[i + 1]] == x[id[i]] && y[id[i + 1]] - y[id[i]] <= k) {
      merge(id[i + 1], id[i]);
    }
  }

  for (int i = 1; i <= n; i++) {
    int p = find(find, i);
    mint[p] = mint[i] = min(mint[p], mint[i]);
  }

  vector<int> v;
  for (int i = 1; i <= n; i++) {
    if (pa[i] == i) {
      v.push_back(mint[i]);
    }
  }
  int len = v.size();
  sort(v.begin(), v.end());
  auto lo = [&](int x) {
    return lower_bound(v.begin(), v.end(), x) - v.begin();
  };
  auto up = [&](int x) {
    return upper_bound(v.begin(), v.end(), x) - v.begin();
  };

  auto check = [&](int mid) {
    return len - up(mid) <= mid + 1;
  };

  int l = 0, r = (int)1e9, ans = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(mid)) r = mid - 1, ans = mid;
    else l = mid + 1;
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("G.in", "r", stdin);
  freopen("G.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}