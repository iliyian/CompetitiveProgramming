#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  string str;
  cin >> n >> str;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (str[i] == '*' && str[i - 1] =='*') {
      cout << ans << '\n';
      return;
    }
    if (str[i] == '@') {
      ans++;
    }
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}