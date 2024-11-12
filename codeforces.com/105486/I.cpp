#include <bits/stdc++.h>
#define int long long
#define lc p << 1
#define rc p << 1 | 1
#define mid (s + t) / 2
using namespace std;

constexpr int N = 2e5;

std::vector<int> a(N + 2), d((N << 2) + 500);
int n, q;

void build(int s, int t, int p) {
  if (s == t) {
    d[p] = (a[s] > a[s + 1] ? s : 0);
    // std::cout << s << ' ' << d[p] << '\n';
    return;
  }
  build(s, mid, lc);
  build(mid + 1, t, rc);
  d[p] = std::gcd(d[lc], d[rc]);
}

void modify(int x, int s, int t, int p, int c) {
  if (x > t || x < s) return;
  if (s == t) {
    d[p] = c;
    return;
  }
  modify(x, s, mid, lc, c);
  modify(x, mid + 1, t, rc, c);
  d[p] = std::gcd(d[lc], d[rc]);
}

int query(int l, int r, int s, int t, int p) {
  if (l > t || r < s) return 0;
  if (l <= s && t <= r) {
    // std::cout << l << ' ' << d[p] << '\n';
    return d[p];
  }
  // int ans = 0;
  // if (l <= mid) ans = std::gcd(ans, query(l, r, s, mid, lc));
  // if (r > mid) ans = std::gcd(ans, query(l, r, mid + 1, t, rc));
  // return ans;
  return std::gcd(query(l, r, s, mid, lc), query(l, r, mid + 1, t, rc));
}

int trans(int g) {
  if (g == 0) return n;
  int ans = 0;
  for (int i = 1; i * i <= g; i++) {
    if (g % i == 0) {
      ans++;
      if (i * i != g) {
        ans++;
      }
    }
  }
  return ans;
}

void solve() {
  std::cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  a[n + 1] = INT_MAX;
  build(1, n, 1);
  std::cout << trans(d[1]) << '\n';
  while (q--) {
    int x, v;
    std::cin >> x >> v;
    a[x] = v;
    // if (x != n) {
      // std::cout << "! " << x << '\n';
      if (a[x] > a[x + 1]) modify(x, 1, n, 1, x);
      else modify(x, 1, n, 1, 0);
    // }
    if (x != 1) {
      // std::cout << "! " << x << '\n';
      if (a[x - 1] > a[x]) modify(x - 1, 1, n, 1, x - 1);
      else modify(x - 1, 1, n, 1, 0);
    }
    // for (int i = 1; i <= n; i++) {
    //   std::cout << query(i, i, 1, n, 1) << " \n"[i == n];
    // }
    std::cout << trans(d[1]) << '\n';
  }
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}