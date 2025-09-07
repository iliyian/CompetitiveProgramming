#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, a, b;
  std::cin >> n >> a >> b;
  int m;
  std::cin >> m;
  int acnt = 0, bcnt = 0;
  int cnt[100] {}, solved[100] {};
  for (int i = 1; i <= m; i++) {
    int t;
    char p;
    std::string v;
    std::cin >> t >> p >> v;
    if (v == "ac") {
      if (solved[t]) continue;
      acnt++;
      bcnt += t + cnt[p] * 20;
    } else {
      cnt[p]++;
    }
  }
  
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