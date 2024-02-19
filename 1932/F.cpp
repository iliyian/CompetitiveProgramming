#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> d(n + 2), a(n + 2);
  for (int i = 0; i < k; i++) {
    int l, r;
    cin >> l >> r;
    d[l]++, d[r + 1]--;
  }
  for (int i = 1; i <= n; i++) {
    a[i] = a[i - 1] + d[i];
    cout << a[i] << " \n"[i == n];
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("F.in", "r", stdin);
  freopen("F.out", "w", stdout);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}