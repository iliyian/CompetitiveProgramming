// date: 2025-03-26 18:58:47
// tag: 还是比较神奇的主席树套字典树，还是字典树套主席树？反正就是复制，增加，差分，把索引的差变成根的差，就很妙。顺便发现这写法真的很多相似之处，左右取决于idx罢了

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::vector<int> a(n + 1);
  int N = n << 6;
  std::vector<std::array<int, 3>> tr(N + 1);
  std::vector<int> cnt(N + 1), rt(N + 1);
  int tot = 1;
  auto insert = [&](auto self, int w, int &p, int x) {
    tr[++tot] = tr[p];
    p = tot;
    tr[p][2]++;
    if (w == -1) return;
    int idx = x >> w & 1;
    self(self, w - 1, tr[p][idx], x);
  };
  auto query = [&](int l, int r, int x) {
    int ans = 0;
    for (int i = 30; i >= 0; i--) {
      int idx = x >> i & 1;
      if (tr[tr[r][idx ^ 1]][2] > tr[tr[l][idx ^ 1]][2]) {
        ans ^= 1ll << i;
        if (l) l = tr[l][idx ^ 1];
        if (r) r = tr[r][idx ^ 1];
      } else {
        if (l) l = tr[l][idx];
        if (r) r = tr[r][idx];
      }
    }
    return ans;
  };
  rt[0] = 1;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    rt[i] = rt[i - 1];
    insert(insert, 30, rt[i], a[i]);
  }
  while (q--) {
    int l, r, x;
    std::cin >> l >> r >> x;
    std::cout << query(rt[l - 1], rt[r], x) << '\n';
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