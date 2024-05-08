// date: 2024-05-05 22:31:27
// tag: 数学

#include <bits/stdc++.h>
#define int long long
#define N (int)2e5
using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n + 1), id(n + 1);
  iota(id.begin() + 1, id.end(), 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(id.begin() + 1, id.end(), [&](const int &x, const int &y) {
    return -a[x] + n - x < -a[y] + n - y;
  });
  bitset<N + 5> skip;
  for (int i = 1; i <= k; i++) {
    skip[id[i]] = true;
  }
  int cnt = 0, ans = 0;
  for (int i = 1; i <= n; i++) {
    if (skip[i]) cnt++;
    else ans += a[i] + cnt;
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}