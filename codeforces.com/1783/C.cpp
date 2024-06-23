// date: 2024-06-21 00:19:54
// tag: 贪心

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n + 1), id(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    id[i] = i;
  }
  sort(id.begin() + 1, id.end(), [&](const int &x, const int &y) {
    return a[x] < a[y];
  });
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (m < a[id[i]]) {
      break;
    }
    m -= a[id[i]];
    ans++;
  }
  if (ans != 0 && ans != n && m - a[ans + 1] + a[id[ans]] >= 0) ans++;
  cout << n + 1 - ans << '\n';
}

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}