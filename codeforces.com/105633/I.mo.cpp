#include <algorithm>
#include <bits/stdc++.h>
#define int long long

constexpr int N = 1e5;
constexpr int maxn = 400;

struct Node {
  int l, r, id;

  bool operator < (const Node &x) const {
    if (l / maxn != x.l / maxn) return l < x.l;
    return (l / maxn) & 1 ? r < x.r : r > x.r;
  }
};

std::vector<std::vector<int>> fac(N + 1);

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> c(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> c[i];
  }
  int q;
  std::cin >> q;
  std::vector<Node> a(q);
  for (int i = 0; i < q; i++) {
    std::cin >> a[i].l >> a[i].r;
    a[i].id = i;
  }
  std::vector<int> cnt(N + 1);
  std::set<int> s;
  int l = 1, r = 0;
  int tot = 0;
  auto add = [&](int x) {
    // std::cerr << "add: " << x << '\n';
    for (int i : fac[x]) {
      tot++;
      cnt[i]++;
      if (cnt[i] == 2) {
        s.insert(i);
      }
    }
  };
  auto del = [&](int x) {
    // std::cerr << "del: " << x << '\n';
    for (int i : fac[x]) {
      tot++;
      cnt[i]--;
      if (cnt[i] == 1) {
        s.erase(i);
      }
    }
  };
  std::sort(a.begin(), a.end());
  std::vector<int> ans(q);
  for (int i = 0; i < q; i++) {
    while (l > a[i].l) add(c[--l]);
    while (r < a[i].r) add(c[++r]);
    while (l < a[i].l) del(c[l++]);
    while (r > a[i].r) del(c[r--]);
    ans[a[i].id] = *s.rbegin();
  }
  for (int i = 0; i < q; i++) {
    std::cout << ans[i] << '\n';
  }
  std::cerr << tot << '\n';
  // std::cout << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  for (int i = 1; i <= N; i++) {
    for (int j = i; j <= N; j += i) {
      fac[j].push_back(i);
    }
  }
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}