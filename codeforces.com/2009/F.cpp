// date: 2024-09-04 18:53:01
// tag: 数学，模拟

#include <bits/stdc++.h>
#define int long long
// using namespace std;

int n, q;

int get(int x) {
  int c = (x - 1) / n;
  int idx = x - c * n;
  idx = (idx + c - 1) % n + 1;
  return idx;
}

int query(std::vector<int> &a, int l, int r) {
  if (l <= r) {
    return a[r] - a[l - 1];
  }
  return a[n] - a[l - 1] + a[r];
};

void solve() {
  std::cin >> n >> q;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    a[i] += a[i - 1];
  }
  while (q--) {
    int l, r;
    std::cin >> l >> r;
    int lc = (l - 1) / n, rc = (r - 1) / n;
    int lx = get(l), rx = get(r);
    if (lc == rc) {
      std::cout << query(a, lx, rx) << '\n';
      continue;
    }
    int ans = (rc - lc - 1) * a[n];
    ans += query(a, lx, (n + lc - 1) % n + 1);
    ans += query(a, rc % n + 1, rx);
    std::cout << ans << '\n';
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("F.in", "r", stdin);
  freopen("F.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}