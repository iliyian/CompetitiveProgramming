#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  int p = 1;
  vector<int> a(n + 1);
  int l = 1, r = n;
  while (true) {
    cout << l++ << ' ';
    p++;
    if (p > n) break;
    cout << r-- << ' ';
    p++;
    if (p > n) break;
  }
  cout << '\n';
}
// 1 5 2 4 3

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}