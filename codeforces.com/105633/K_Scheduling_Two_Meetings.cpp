#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n + 1);
  std::vector<int> pos((1 << m), -1); // 某个值对应的最小位置
  for (int i = 1; i <= n; i++) {
    std::string str;
    std::cin >> str;
    int x = 0;
    for (int j = 0; j < m; j++) {
      x ^= (int)(str[j] == 'Y') << j;
    }
    a[i] = x;
    if (pos[x] == -1) {
      pos[x] = i;
    }
  }
  if (pos[(1 << m) - 1] != -1) {
    auto p = pos[(1 << m) - 1];
    int val = -1, q = -1;
    for (int i = 1; i <= n; i++) {
      if (i == p) continue;
      if (__builtin_popcountll(a[i]) > val) {
        q = i;
        val = __builtin_popcountll(a[i]);
      }
    }
    if (p > q) std::swap(p, q);
    std::cout << p << ' ' << q << '\n';
    return;
  }
  std::vector<int> fpos(1 << m, -1), fval(1 << m, -1);
  for (int S = (1 << m) - 1; S >= 0; S--) { // 顺序似乎不影响？
  // for (int S = 0; S < (1 << m); S++) {
    if (pos[S] == -1) continue; // 当前不存在
    int t = S ^ ((1 << m) - 1); // 补集
    std::cerr << "S: " << S << '\n';
    for (int i = 0; i < m; i++) {
      // t |= (1 << i); // 补集的某个超集，两者相或满足交集为全集
      if (t >> i & 1) continue;
      int tt = t ^ (1 << i);
      if (fval[t] > fval[tt] && pos[]) {

      }
    }
  }
  int x = -1, y = -1, ansval = -1;
  for (int S = (1 << m) - 1; S >= 0; S--) {
    if (fval[S] != -1) {
      int p = pos[S], q = fpos[S];
      if (p > q) std::swap(p, q);
      if (fval[S] > ansval || fval[S] == ansval && std::tie(p, q) < std::tie(x, y)) {
        ansval = fval[S],
        x = p, y = q;
      }
    }
  }
  if (x == -1) {
    std::cout << "No\n";
    return;
  }
  std::cout << x << ' ' << y << '\n';
  std::cerr << ansval << '\n';
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