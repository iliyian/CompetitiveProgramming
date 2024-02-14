#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, x, y;
  cin >> n >> x >> y;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int lca = x * y / gcd(x, y);
  
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }
  return 0;
}