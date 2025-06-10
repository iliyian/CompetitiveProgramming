// date: 2025-03-26 20:17:01
// tag: 主席树二分+随机权值异或哈希，有意思

#include <bits/stdc++.h>
// #define int long long
#define lc tr[p].ls
#define rc tr[p].rs
#define mid (s + t) / 2

struct Node {
  int ls, rs;
  unsigned val;
};

std::mt19937 rd(std::random_device{}());

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  int N = (int)2e5 << 5;
  int tot = 1;
  std::vector<Node> tr(N + 1);
  std::vector<int> rt(n + 1);
  auto modify = [&](auto self, int s, int t, int &p, int x, unsigned c) {
    if (s > x || t < x) return;
    tr[++tot] = tr[p];
    p = tot;
    tr[p].val ^= c;
    if (s == t) return;
    self(self, s, mid, lc, x, c);
    self(self, mid + 1, t, rc, x, c);
  };
  auto query = [&](auto self, int s, int t, int lp, int rp) -> int {
    if (s == t) return s;
    if (tr[tr[rp].ls].val != tr[tr[lp].ls].val) {
      return self(self, s, mid, tr[lp].ls, tr[rp].ls);
    } else if (tr[tr[rp].rs].val != tr[tr[lp].rs].val) {
      return self(self, mid + 1, t, tr[lp].rs, tr[rp].rs);
    } else return 0;
  };
  std::map<int, unsigned> to;
  for (int i = 1; i <= n; i++) {
    to[a[i]] = rd();
  }
  for (int i = 1; i <= n; i++) {
    rt[i] = rt[i - 1];
    modify(modify, 1, (int)1e9, rt[i], a[i], to[a[i]]);
  }
  int q;
  std::cin >> q;
  int lst = 0;
  while (q--) {
    int l, r;
    std::cin >> l >> r;
    l ^= lst, r ^= lst;
    int ans = query(query, 1, (int)1e9, rt[l - 1], rt[r]);
    std::cout << ans << '\n';
    lst = ans;
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