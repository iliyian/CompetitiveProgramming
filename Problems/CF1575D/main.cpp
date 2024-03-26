// date: 2024-03-26 21:00:16
// tag: 暴力竟然能过？真就签到

#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  string str;
  cin >> str;
  if (str.size() == 1) {
    cout << (int)(str == "0" || str == "X" || str == "_") << '\n';
    return 0;
  }
  int n = pow(10, str.size()), ans = 0;
  for (int t = n / 10; t < n; t++) {
    if (t % 25) continue;
    string cur = to_string(t);
    bool f = true;
    int x = -1;
    for (int i = 0; i < str.size(); i++) {
      if (isdigit(str[i])) {
        if (str[i] != cur[i]) {
          f = false;
          break;
        }
      } else if (str[i] == 'X') {
        if (x != -1 && cur[i] != x) {
          f = false;
          break;
        }
        x = cur[i];
      }
    }
    ans += f;
  }
  cout << ans << '\n';

  return 0;
}