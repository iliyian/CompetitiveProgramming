// date: 2024-05-14 17:49:41
// tag: 暴力，位运算

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  vector<int> cnt(n << 2);
  int ans = n * (n + 1) / 2;
  cnt[0] = 1;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] ^= a[i - 1];

    for (int j = 0; j * j <= (n << 1); j++) {
      ans -= cnt[a[i] ^ (j * j)];
    }
    cnt[a[i]]++;
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}