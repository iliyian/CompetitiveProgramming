#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::string s, t;
  std::cin >> s >> t;
  s = '#' + s;
  t = '#' + t;
  std::set<int> st;
  for (int i = 1; i <= m - n + 1; i++) {
    st.insert(i);
  }
  if (m < n) {
    std::cout << 0 << '\n';
    return;
  }
  for (int i = 1; i <= n; i++) {
    std::set<int> tt;
    for (auto j : st) {
      if (t[j + i - 1] == (s[i] ^ 1)) {
        tt.insert(j);
      }
    }
    if (tt.empty()) {
      tt = st;
    } else {
      st = tt;
    }
  }
  int ans = 0;
  int ini = *st.begin();
  for (int i = ini; i <= ini + n - 1; i++) {
    ans += s[i - ini + 1] != t[i];
  }
  std::cout << ans << '\n';
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