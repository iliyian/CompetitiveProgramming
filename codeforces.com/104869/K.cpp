#include <bits/stdc++.h>
#define int long long
#define lc p << 1
#define rc p << 1 | 1
#define mid (s + t) / 2

std::vector<int> vec = {INT_MIN};

int id(int x) {
  return std::lower_bound(vec.begin(), vec.end(), x) - vec.begin();
}

constexpr int N = 5e5;

int sum[N << 2], d[N << 2];

void add(int x, int s, int t, int p, int c, int sig) { 
  if (x < s || x > t) return;
  if (s == t) {
    sum[p] += c * sig;
    d[p] += sig;
    return;
  }
  add(x, s, mid, lc, c, sig);
  add(x, mid + 1, t, rc, c, sig);
  sum[p] = sum[lc] + sum[rc];
  d[p] = d[lc] + d[rc];
}

int neg = 0;

int query(int s, int t, int p, int val) {
  if (s == t) return std::min(d[p], val / vec[s]);
  if (sum[lc] >= val) return query(s, mid, lc, val);
  return query(mid + 1, t, rc, val - sum[lc]) + d[lc];
}

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    if (a[i] > 0) vec.push_back(a[i]);
  }
  std::vector<std::pair<int, int>> ask(q);
  for (auto &[x, v] : ask) {
    std::cin >> x >> v;
    if (v > 0) vec.push_back(v);
  }
  std::sort(vec.begin(), vec.end());
  vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
  int len = vec.size() - 1;

  if (len == 0) {
    while (q--) {
      std::cout << 1 << '\n';
    }
    return;
  }

  memset(d, 0, sizeof(d));
  memset(sum, 0, sizeof(sum));

  int cnt = 0;
  auto insert = [&](int x, int c) {
    if (x < 0) neg += x * c;
    else if (x > 0) add(id(x), 1, len, 1, x, c), cnt += c;
  };

  for (int i = 1; i <= n; i++) {
    insert(a[i], 1);
  }

  for (auto [x, v] : ask) {
    insert(a[x], -1);
    insert(v, 1);

    a[x] = v;

    std::cout << query(1, len, 1, -neg) + 1 << '\n';
  }
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}