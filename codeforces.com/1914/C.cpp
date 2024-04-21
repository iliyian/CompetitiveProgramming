#include <bits/stdc++.h>
#define N 200005
#define int long long
using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n + 1), b(n + 1), maxb(n + 1), suma(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> a[i], suma[i] = suma[i - 1] + a[i];
  for (int i = 1; i <= n; i++)
    cin >> b[i], maxb[i] = max(maxb[i - 1], b[i]);
  int ans = -0x3f3f3f3f3f3f3f3f;
  for (int i = 1; i <= min(k, n); i++) {
    int r = k - i;
    int cur = suma[min(k, i)] + r * maxb[i];
    ans = max(ans, cur);
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}