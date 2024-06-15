#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    string str;
    cin >> str;
    for (int j = 0; j < m; j++) {
      if (str[j] == 'o') {
        a[i] ^= 1 << j;
      }
    }
  }
  int ans = n;
  for (int S = 0; S < (1 << n); S++) {
    int cur = 0;
    for (int i = 0; i < n; i++) {
      if (S >> i & 1) {
        cur |= a[i];
      }
    }
    if (cur == (1 << m) - 1) {
      ans = min(ans, (int)__builtin_popcount(S));
    }
  }
  cout << ans << '\n';

  return 0;
}