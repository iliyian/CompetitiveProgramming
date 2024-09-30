// date: 2023/12/25 19:16:41
// tag: 暴力标记

#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, k, d;
  cin >> n >> k >> d;
  vector<int> a(n + 1), v(k + 1), cnt(min(n * 2, d - 1) + 1);
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int i = 1; i <= k; i++)
    cin >> v[i];
  for (int i = 1; i <= n; i++)
    cnt[0] += a[i] == i;
  for (int i = 1; i <= min(n * 2, d - 1); i++) {
    for (int j = 1; j <= v[(i - 1) % k + 1]; j++)
      a[j]++;
    for (int j = 1; j <= n; j++)
      cnt[i] += a[j] == j;
  }
  int ans = -0x3f3f3f3f;
  for (int i = 0; i <= min(n * 2, d - 1); i++)
    ans = max(ans, cnt[i] + (d - i - 1) / 2);
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}