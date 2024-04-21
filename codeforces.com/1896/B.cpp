#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  string str;
  cin >> str;
  int cur = 0, ans = 0;
  while (cur < n) {
    int cnt = 0;
    while (cur < n && str[cur] == 'A') {
      cnt++; cur++;
    }
    if (cur < n) {
      ans += cnt;
      while (cur < n && str[cur] == 'B') {
        cur++;
        if (cnt) ans++;
      }
    }
  }
  if (ans > 0) ans--;
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("B.in", "r", stdin);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}