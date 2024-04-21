#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("L.in", "r", stdin);
  freopen("L.out", "w", stdout);

  string str;
  cin >> str;
  int ans = 0, cnt = 0;
  for (int i = 0; i < str.size(); i++) {
    if (str[i] == '0') {
      cnt = 0;
      ans -= 12;
    } else {
      cnt++;
      ans += (cnt > 6 ? 5 : cnt - 1);
      ans += 3;
    }
  }
  cout << ans << '\n';

  return 0;
}