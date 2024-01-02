#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  long long ans = 0;
  sort(a.begin() + 1, a.end());
  for (int i = n; i >= 3; i -= 3) {
    ans += a[i] + a[i - 1];
  }
  for (int i = 1; i <= n % 3; i++)
    ans += a[i];
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);
  // int _; cin >> _;
  int _ = 1;
  while (_--) solve();
}