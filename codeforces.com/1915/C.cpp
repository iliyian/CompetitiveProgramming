#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    sum += a;
  }
  int sq = sqrt(sum);
  if (sum == sq * sq) {
    cout << "YES\n";
  } else cout << "NO\n";
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}