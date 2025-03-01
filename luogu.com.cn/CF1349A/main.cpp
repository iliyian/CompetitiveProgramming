// date: 2024-03-26 12:27:16
// tag: gcd的类积性与后缀gcd

#include <bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n;
  cin >> n;
  vector<int> a(n + 1);
  int g = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    g = gcd(g, a[i]);
  }
  for (int i = 1; i <= n; i++) {
    // a[i] /= g;
    cerr << a[i] / g << " \n"[i == n];
  }
  vector<int> sgcd(n + 2);
  for (int i = n; i >= 1; i--) {
    sgcd[i] = gcd(sgcd[i + 1], a[i]);
  }
  int gg = 0;
  for (int i = 1; i <= n; i++) {
    gg = gcd(gg, a[i] * sgcd[i + 1]);
  }
  cout << gg / g << '\n';

  return 0;
}