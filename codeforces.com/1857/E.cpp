// date: 2024/02/06 20:36:09
// tag: 这种需要标记大小顺序的，似乎用pair也不错

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, s1 = 0, s2 = 0;
  cin >> n;
  vector<int> a(n + 1), sum(n + 1), id(n + 1), ans(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> a[i], s2 += a[i];
  iota(id.begin() + 1, id.end(), 1);
  sort(id.begin() + 1, id.end(), [&](const int &x, const int &y) {
    return a[x] < a[y];
  });
  for (int i = 1; i <= n; i++) {
    s1 += a[id[i]], s2 -= a[id[i]];
    ans[id[i]] = n + a[id[i]] * (2 * i - n) - s1 + s2;
  }
  for (int i = 1; i <= n; i++)
    cout << ans[i] << " \n"[i == n];
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}