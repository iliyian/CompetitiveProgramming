#include <bits/stdc++.h>
#define int long long

void solve() {
  std::string str;
  std::cin >> str;
  int ans = 0;
  int mp[128]{};
  mp['A'] = 1;
  mp['B'] = 10;
  mp['C'] = 100;
  mp['D'] = 1000;
  mp['E'] = 10000;
  int anspos = -1, ansch = 0;
  for (int pos = 0; pos < str.size(); pos++) {
    auto cur = str;
    for (int ch = 'A'; ch <= 'E'; ch++) {
      cur[pos] = ch;
      int res = 0;
      int vis[128]{};
      for (int i = cur.size() - 1; i >= 0; i--) {
        bool f = false;
        for (int j = cur[i] + 1; j <= 'E'; j++) {
          if (vis[j]) {
            f = true;
            break;
          }
        }
        if (f) {
          res -= mp[cur[i]];
        } else {
          res += mp[cur[i]];
        }
        vis[cur[i]] = 1;
      }
      if (res > ans) {
        ans = res;
        anspos = pos + 1;
        ansch = ch;
      }
    }
  }
  std::cout << ans << ' ' << anspos << ' ' << char(ansch) << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}