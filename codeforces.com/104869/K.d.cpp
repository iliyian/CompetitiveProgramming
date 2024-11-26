#include <bits/stdc++.h>
#include <random>
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

std::mt19937 rd(std::random_device{}());

void solve() {
  int n = 2e5, q = 2e5;
  std::cout << n << ' ' << q << '\n';
  for (int i = 1; i <= n; i++) {
    std::cout << std::uniform_int_distribution<>{(int)-1e9, (int)1e9}(rd) << ' ';
  }
  std::cout << '\n';
  for (int i = 1; i <= q; i++) {
    std::cout << rd() % (int)2e5 + 1 << ' ' << std::uniform_int_distribution<>{(int)-1e9, (int)1e9}(rd) << '\n';
  }
  std::cout << '\n';
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