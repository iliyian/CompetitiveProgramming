#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1), sumodd(n + 1), sumeven(n + 1), d(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (i & 1) {
      sumodd[i] = sumodd[max(i - 2, 0ll)] + a[i];
      sumeven[i] = sumeven[i - 1];
    } else {
      sumodd[i] = sumodd[i - 1];
      sumeven[i] = sumeven[i - 2] + a[i];
    }
    d[i] = sumodd[i] - sumeven[i];
  }
  sort(d.begin() + 1, d.begin() + n + 1);
  for (int i = 1; i < n; i++) {
    if (d[i] == 0 || d[i] == d[i + 1]) {
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}