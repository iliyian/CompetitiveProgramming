// date: 2025-03-27 17:41:35
// tag: 什么水题我都能做出来，性质观察题，交换操作，蹭点哈希

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> a(n + 1, std::vector<int>(m + 1));
  std::vector<std::vector<int>> aa(m + 1, std::vector<int>(n + 1));
  std::vector<std::vector<int>> b(n + 1, std::vector<int>(m + 1));
  std::vector<std::vector<int>> bb(m + 1, std::vector<int>(n + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      std::cin >> a[i][j];
      aa[j][i] = a[i][j];
    }
    std::sort(a[i].begin() + 1, a[i].end());
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      std::cin >> b[i][j];
      bb[j][i] = b[i][j];
    }
    std::sort(b[i].begin() + 1, b[i].end());
  }
  std::vector<int> pa(n + 1), pb(n + 1);
  std::vector<int> pa2(m + 1), pb2(m + 1);
  std::iota(pa.begin() + 1, pa.end(), 1);
  std::iota(pb.begin() + 1, pb.end(), 1);
  std::sort(pa.begin() + 1, pa.end(), [&](const int &x, const int &y) {
    return a[x][1] < a[y][1];
  });
  std::sort(pb.begin() + 1, pb.end(), [&](const int &x, const int &y) {
    return b[x][1] < b[y][1];
  });
  for (int i = 1; i <= n; i++) {
    if (a[pa[i]] != b[pb[i]]) {
      std::cout << "NO\n";
      return;
    }
  }
  std::iota(pa2.begin() + 1, pa2.end(), 1);
  std::iota(pb2.begin() + 1, pb2.end(), 1);
  for (int j = 1; j <= m; j++) {
    std::sort(aa[j].begin() + 1, aa[j].end());
    std::sort(bb[j].begin() + 1, bb[j].end());
  }
  std::sort(pa2.begin() + 1, pa2.end(), [&](const int &x, const int &y) {
    return aa[x][1] < aa[y][1];
  });
  std::sort(pb2.begin() + 1, pb2.end(), [&](const int &x, const int &y) {
    return bb[x][1] < bb[y][1];
  });
  for (int j = 1; j <= m; j++) {
    if (aa[pa2[j]] != bb[pb2[j]]) {
      std::cout << "NO\n";
      return;
    }
  }
  std::cout << "YES\n";
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