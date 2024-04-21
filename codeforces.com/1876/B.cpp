#include <bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int i = 1; i <= n; i++) {
    for (int j = i * 2; j <= n; j += i) {
      a[i] = max(a[i], a[j]);
    }
  }
  int ans = 0;
  int p = 1;
  sort(a.begin(), a.end());
  for (int i = 1; i <= n; i++) {
    ans = (ans + p * a[i] % mod) % mod;
    p = p * 2 % mod;
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);
  // int _; cin >> _;
  int _ = 1;
  while (_--) solve();
}