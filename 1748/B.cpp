#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  string str;
  cin >> str;
  str = '#' + str;
  int ans = 0;
  for (int len = 1; len <= 100; len++) {
    for (int i = 1; i <= n - len + 1; i++) {
      int j = i + len - 1;
      int cnt[10], distinct = 0;
      memset(cnt, 0, sizeof(cnt));
      for (int k = i; k <= j; k++)
        cnt[str[k] - '0']++;
      int maxl = -1;
      for (int i = 0; i <= 9; i++) {
        if (cnt[i])
          distinct++;
        maxl = max(maxl, cnt[i]);
      }
      ans += (maxl <= distinct);
    }
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}