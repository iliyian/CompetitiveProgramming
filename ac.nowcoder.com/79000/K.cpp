#include <bits/stdc++.h>
#define int long long
#define p 998244353
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] %= p;
  }
  int ans = 0, cnt = n;
  for (int i = 1; i <= n / 2; i++) {
    ans += cnt % p * (a[i] % p + a[n - i + 1] % p) % p;
    ans %= p;

    cnt += (n - i * 2) % p;
    cnt %= p;
  }
  if (n & 1) {
    ans += cnt % p * a[(n + 1) / 2] % p;
    ans %= p;
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("K.in", "r", stdin);
  freopen("K.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}