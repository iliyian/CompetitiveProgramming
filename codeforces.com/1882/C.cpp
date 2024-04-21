#include <bits/stdc++.h>
#define N 200005
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (i >= 3)
      sum += max(0ll, a[i]);
  }
  if (n == 1) {
    cout << max(0ll, a[1]) << '\n';
    return;
  }
  
  cout << sum + max(0ll, a[1] + max(a[2], 0ll)) << '\n';
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}