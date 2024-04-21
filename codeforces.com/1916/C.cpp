#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  int sum = 0, cnt = 0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    sum += a, cnt += a & 1;
    if (i == 0) cout << sum;
    else cout << sum - cnt / 3 - ((cnt % 3) & 1);
    cout << " \n"[i == n - 1];
  }
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}