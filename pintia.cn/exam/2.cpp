#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<long long> a(60);
  if (n < 1 || n > 50) {
    cout << "Wrong Input!" << '\n';
    return;
  }
  a[1] = a[2] = 1;
  for (int i = 3; i <= n; i++)
    a[i] = a[i - 1] + a[i - 2];
  cout << "F(" << n << ")=" << a[n] << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  // freopen("2.in", "r", stdin);
  // freopen("2.out", "w", stdout);
  // int _; cin >> _;
  int _ = 1;
  while (_--) solve();
}