#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, f, a, b;
  cin >> n >> f >> a >> b;
  int sum = 0, prev, x;
  cin >> prev;
  sum += min(prev * a, b);
  for (int i = 1; i < n; i++) {
    cin >> x;
    sum += min((x - prev) * a, b);
    prev = x;
  }
  cout << (sum < f ? "YES" : "NO") << '\n';
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}