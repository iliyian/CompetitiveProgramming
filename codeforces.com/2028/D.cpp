// date: 2024-11-11 19:10:43
// tag: 贪心

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  std::cin >> n;
  std::array<std::vector<int>, 3> a, b, p;
  for (int i = 0; i < 3; i++) {
    a[i].resize(n + 1);
    b[i].resize(n + 1);
    p[i].resize(n + 1);
    for (int j = 1; j <= n; j++) {
      std::cin >> a[i][j];
      // p[i][a[i][j]] = j;
      p[i][j] = a[i][j];
    }
  }
  std::string qkj = "qkj";
  std::vector<std::pair<int, int>> ans;

  std::vector<int> mn(3);
  std::vector<std::pair<int, int>> nxt(n + 1, {-1, -1});
  for (int i = 0; i < 3; i++) {
    mn[i] = n;
  }
  for (int k = n - 1; k >= 1; k--) {
    int mnn = -1;
    for (int i = 0; i < 3; i++) {
      if (p[i][k] > p[i][mn[i]]) {
        mnn = i;
      }
    }
    if (mnn == -1) {
      continue;
    }
    nxt[k] = {mnn, mn[mnn]};
    for (int i = 0; i < 3; i++) {
      if (p[i][k] < p[i][mn[i]]) {
        mn[i] = k;
      }
    }
  }
  if (nxt[1].first == -1) {
    std::cout << "NO\n";
    return;
  }
  ans.push_back(nxt[1]);
  while (nxt[ans.back().second].second > 0) {
    ans.push_back(nxt[ans.back().second]);
  }
  std::cout << "YES\n";
  std::cout << ans.size() << '\n';
  for (auto [i, k] : ans) {
    std::cout << qkj[i] << ' ' << k << '\n';
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