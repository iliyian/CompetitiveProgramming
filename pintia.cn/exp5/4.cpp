#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, c;
  cin >> n >> c;
  vector<int> w(n), v(n), f(c + 1, 0);
  for (int i = 0; i < n; i++)
    cin >> w[i] >> v[i];
  for (int i = 0; i < n; i++)
    for (int j = c; j >= 0; j--)
      if (j >= w[i])
        f[j] = max(f[j], f[j - w[i]] + v[i]);
  cout << f[c] << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("4.in", "r", stdin);
  freopen("4.out", "w", stdout);
  // int _; cin >> _;
  int _ = 1;
  while (_--) solve();
}