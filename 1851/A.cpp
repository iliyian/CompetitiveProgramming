#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, m, k, H;
  cin >> n >> m >> k >> H;
  vector<int> h(n + 1);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    cin >> h[i];
    h[i] = abs(h[i] - H);
    if (h[i] && h[i] % k == 0 && h[i] / k <= (m - 1)) {
      ans++;
    }
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}