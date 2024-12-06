// date: 2024-12-06 22:15:05
// tag: 贪心

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::string a, b, c, d;
  std::cin >> a >> b >> c >> d;
  a = '#' + a, b = '#' + b, c = '#' + c, d = '#' + d;
  std::vector<int> ida(n + 1), idb(n + 1);
  std::vector<std::array<int, 2>> cnta(n + 1), cntb(n + 1);
  int cnt0 = 0, cnt1 = 0, id = 0;
  for (int i = 1; i <= n; i++) {
    if (c[i] == '1') {
      cnta[id][a[i] - '0']++;
      ida[i] = id;
    } else {
      id++;
    }
  }
  id = cnt0 = cnt1 = 0;
  for (int i = 1; i <= n; i++) {
    if (d[i] == '1') {
      cntb[id][b[i] - '0']++;
      idb[i] = id;
    } else {
      id++;
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (c[i] == '1' && d[i] == '1') {
      if (cnta[ida[i]][0] && cntb[idb[i]][0]) {
        ans++;
        cnta[ida[i]][0]--;
        cntb[idb[i]][0]--;
      }
      else if (cnta[ida[i]][1] && cntb[idb[i]][1]) {
        ans++;
        cnta[ida[i]][1]--;
        cntb[idb[i]][1]--;
      }
    } else if (c[i] == '1') {
      if (cnta[ida[i]][b[i] - '0']) {
        cnta[ida[i]][b[i] - '0']--;
        ans++;
      }
    } else if (d[i] == '1') {
      if (cntb[idb[i]][a[i] - '0']) {
        cntb[idb[i]][a[i] - '0']--;
        ans++;
      }
    } else {
      ans += a[i] == b[i];
    }
  }
  std::cout << ans << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}