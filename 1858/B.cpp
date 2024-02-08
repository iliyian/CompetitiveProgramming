#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m, d;
  cin >> n >> m >> d;
  vector<int> a(n + 1);
  int ans1 = 0;
  bool f = false;
  for (int i = 1; i <= m; i++) {
    cin >> a[i];
    if ((a[i] - 1) % d) {
      ans1++;
      f = true;
    }
  }
  ans1 += (n - 1) / d - f;
  cout << ans1 << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}