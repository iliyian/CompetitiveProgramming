#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int a, b, c;
  cin >> a >> b >> c;
  int cnt = 0;
  if (a + b < c) cnt++;
  if (a + c < b) cnt++;
  if (b + c < a) cnt++;
  cout << cnt << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);

  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}