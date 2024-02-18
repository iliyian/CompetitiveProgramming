#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n * 2 + 1);
  for (int i = 1; i <= n * 2; i++) {
    cin >> a[i];
  }
  sort(a.begin() + 1, a.end());
  int ans = 0;
  for (int i = 1; i <= n * 2; i += 2) {
    ans += a[i];
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}