#include <bits/stdc++.h>
#define int long long
#define mid (s + t) / 2
#define lc p << 1
#define rc p << 1 | 1

constexpr int mod = 1e9 + 7;
constexpr int N = 1e6;

int n, a, b;

std::array<std::vector<int>, 2> d;
std::vector<std::array<int, 2>> f(N + 1);

void add(int x, int s, int t, int p, int c, int w) {
  if (x > t || x < s) return;
  if (s == t) {
    d[w][p] += c;
    d[w][p] %= mod;
    return;
  }
  add(x, s, mid, lc, c, w);
  add(x, mid + 1, t, rc, c, w);
  d[w][p] = d[w][lc] + d[w][rc];
  d[w][p] %= mod;
}

int query(int l, int r, int s, int t, int p, int w) {
  if (l > t || r < s) return 0;
  if (l <= s && t <= r) return d[w][p];
  return (query(l, r, s, mid, lc, w) + query(l, r, mid + 1, t, rc, w)) % mod;
}

void add(int x, int w, int c) {
  add(x + 1, 1, N + 1, 1, c, w);
}

int query(int l, int r, int w) {
  l = std::max(0ll, l);
  if (l > r) return 0;
  return query(l + 1, r + 1, 1, N + 1, 1, w);
}

int qpow(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}

void solve() {
  std::cin >> n >> a >> b;
  f[0][0] = f[0][1] = 1;
  d[0].assign((N + 10) << 2, 0);
  d[1].assign((N + 10) << 2, 0);
  add(0, 0, 1);
  add(0, 1, 1);
  for (int i = 1; i <= n; i++) {
    f[i][0] += query(i - a + 1, i - 1, 1);
    f[i][1] += query(i - b + 1, i - 1, 0);
    f[i][0] %= mod;
    f[i][1] %= mod;
    add(i, 0, f[i][0]);
    add(i, 1, f[i][1]);
  }
  int ans = qpow(2, n);
  ans = (ans - f[n][0] + mod) % mod;
  ans = (ans - f[n][1] + mod) % mod;
  std::cout << ans << '\n';
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