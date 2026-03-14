// date: 2025-02-18 20:01:11
// tag: 可行性背包的bitset优化
// 顺便带二进制优化版本

#include <bits/stdc++.h>
#define int long long

constexpr int N = 1e5;

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> pa(m + 1), siz(m + 1, 1);
  std::iota(pa.begin() + 1, pa.end(), 1);
  auto find = [&](this auto &&self, int x) -> int {return x == pa[x] ? x : pa[x] = self(pa[x]);};
  auto merge = [&](int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return false;
    if (siz[x] > siz[y]) std::swap(x, y);
    pa[x] = y;
    siz[y] += siz[x];
    return true;
  };
  std::vector<int> cyc(m + 1);
  for (int i = 1; i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    if (!merge(x, y)) {
      cyc[find(x)] = true;
    }
  }
  std::vector<int> x, y; // 环与链
  int sumx = 0;
  for (int i = 1; i <= m; i++) {
    if (find(i) == i) {
      if (cyc[i]) {
        x.push_back(siz[i]);
        sumx += siz[i];
      } else {
        y.push_back(siz[i] - 1);
      }
    }
  }
  std::sort(y.begin(), y.end(), std::greater<>());
  std::bitset<N + 1> f;
  f[0] = 1;
  std::vector<int> cnt(m + 1);
  for (int v : x) {
    cnt[v]++;
  }
  for (int i = 1; i <= m; i++) {
    if (cnt[i]) {
      int s = cnt[i];
      for (int k = 1; k < s; k *= 2) {
        // jiangly的二进制优化实在是太优雅了
        f |= f << (k * i);
        s -= k;
      }
      f |= f << (s * i);
    }
  }
  // for (int i = 0; i < x.size(); i++) {
  //   // std::cerr << x[i] << ' ';
  //   f |= f << x[i]; // 可行性背包用bitset优化，这里甚至可以二进制优化，jiangly真是神仙
  //   // 对图论，环与链的理解是多么深刻啊
  //   
  // }
  // std::cerr << '\n';
  int sum = sumx, j = 0;
  // for (int i = 1; i <= m; i++) {
  //   std::cerr << f[i] << " \n"[i == m];
  // }
  for (int i = 1; i <= n; i++) {
    if (i < sumx) {
      std::cout << i - !f[i] << ' '; // 某个环变成链了
    } else {
      while (sum < i) {
        sum += y[j++];
      }
      std::cout << i - j << ' ';
    }
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}