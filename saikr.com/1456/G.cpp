#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  int ans = 1;
  for (int i = 1; i <= n; i++){
    cin >> a[i];
    ans = ans * a[i];
  }
  if (ans > 0) {
    cout << 1 << '\n';
    cout << 1 << ' ' << 0 << '\n';
  } else {
    cout << 0 << '\n';
  }
  cout << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("G.in", "r", stdin);
  freopen("G.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}