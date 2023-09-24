// 屎山

#include <bits/stdc++.h>
using namespace std;

int c[500000], n, m, k;

int gen(int x, int y, int z) {
  for (int i = 1; i <= k; i++)
    if (i != x && i != y && i != z)
      return i;
  return z;
}

void solve() {
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }
  for (int i = 1; i < n - 1 && m; i++) {
    if (c[i] == c[i + 1] && c[i] == c[i - 1]) {
      c[i] = gen(c[i - 1], c[i + 1], c[i]);
      m--;
    }
  }
  for (int i = 0; i < n - 1 && m; i++) {
    if (c[i] == c[i + 1])
      c[i] = gen(c[i - 1], c[i + 1], c[i]), m--;
  }
  int ans = 1;
  for (int i = 0; i < n - 1; i++)
    if (c[i] != c[i + 1])
      ans++;
  cout << ans << '\n';
}

int main() {
  freopen("B.in", "r", stdin);
  ios::sync_with_stdio(false); cin.tie(0);
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}