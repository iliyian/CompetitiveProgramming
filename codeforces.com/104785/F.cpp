#include <bits/stdc++.h>
#define int long long

signed main() {
  freopen("F.in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n * 2 + 1), s(n * 2 + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    a[i + n] = a[i];
  }
  for (int i = 1; i <= n * 2; i++) {
    s[i] = s[i - 1] + a[i];
  }
  std::vector<std::array<int, 21>> nxt(n * 2 + 1);
  for (auto &s : nxt) {
    s.fill(INT_MAX);
  }
  for (int i = 1; i <= n; i++) {
    int p = std::lower_bound(s.begin() + 1, s.end(), s[i - 1] + m) - s.begin();
    nxt[i][0] = p + 1;
    nxt[i + n][0] = p + n + 1;
  }
  for (int i = 1; i <= 20; i++) {
    for (int j = 1; j <= n * 2; j++) {
      if (nxt[j][i - 1] <= n * 2) {
        nxt[j][i] = nxt[nxt[j][i - 1]][i - 1]; 
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    int t = i, ans = 0;
    for (int j = 20; j >= 0; j--) {
      if (nxt[t][j] < i + n) {
        ans += 1 << j;
        t = nxt[t][j];
      }
    }
    // while (nxt[t][0] < i + n) {
    //   ans++, t = nxt[t][0];
    // }
    std::cout << ans << ' ';
  }
  std::cout << '\n';
  return 0;
}