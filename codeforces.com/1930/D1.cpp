#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  string str;
  cin >> str;
  str = '#' + str;
  int ans = 0;
  for (int l = 1; l <= n; l++) {
    int last1 = -3, sum = 0;
    for (int i = l; i <= n; i++) {
      if (str[i] == '1' && last1 < i - 2) {
        last1 = i;
        sum++;
        // ans++;
      }
      ans += sum;
    }
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("D1.in", "r", stdin);
  freopen("D1.out", "w", stdout);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}