#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  n %= m;
  int a = n / gcd(n, m), b = m / gcd(n, m);
  if (__builtin_popcount(b) > 1) cout << "-1\n";
  else {
    // 每次多一个，总共有多少个大小不同的块
    cout << m * __builtin_popcount(a) - n << '\n';
  }
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}