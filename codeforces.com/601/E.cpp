// date: 2024-07-22 14:06:46
// tag: 线段树分治，维护01背包

#include <bits/stdc++.h>
#define int long long
#define lc p << 1
#define rc p << 1 | 1
#define N ((int)5e3 + 5)
#define M ((int)4e4 + 5)
// using namespace std;

constexpr int base = 1e7 + 19, mod = 1e9 + 7;

std::vector<std::pair<int, int>> timeline[M << 2];

void update(int l, int r, int s, int t, int p, std::pair<int, int> v) {
  if (l <= s && t <= r) {
    timeline[p].push_back(v);
    return;
  }
  int mid = (s + t) / 2;
  if (l <= mid) update(l, r, s, mid, lc, v);
  if (r > mid) update(l, r, mid + 1, t, rc, v);
}

std::vector<int> ans(M);
std::bitset<M> isquery;
int n, k, q;

void solve(int s, int t, int p, std::vector<int> f) {
  for (auto [v, w] : timeline[p]) {
    for (int i = k; i >= w; i--) {
      f[i] = std::max(f[i], f[i - w] + v);
    }
  }
  if (s == t) {
    if (isquery[s]) {
      int b = 1;
      for (int i = 1; i <= k; i++) {
        ans[s] += f[i] * b % mod;
        ans[s] %= mod;
        b = b * base % mod;
      }
    }
  } else {
    int mid = (s + t) / 2;
    solve(s, mid, lc, f);
    solve(mid + 1, t, rc, f);
  }
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  std::cin >> n >> k;

  std::vector<std::tuple<int, int, std::pair<int, int>>> ops;
  std::vector<int> lst(M);
  std::vector<std::pair<int, int>> d(M);
  std::map<int, int> id;

  for (int i = 1; i <= n; i++) {
    int v, w;
    std::cin >> v >> w;
    d[i] = {v, w};
    lst[i] = i;
    id[i] = i;
  }

  std::cin >> q;
  int t = n;

  for (int i = 1; i <= q; i++) {
    int op;
    std::cin >> op;
    if (op == 1) {
      int v, w;
      std::cin >> v >> w;
      d[i + n] = {v, w};
      lst[i + n] = i + n;
      id[++t] = i + n;
    } else if (op == 2) {
      int x;
      std::cin >> x;
      x = id[x];
      ops.push_back({lst[x], i + n - 1, d[x]});
      lst[x] = 0;
    } else {
      isquery[i + n] = true;
    }
  }
  
  for (int i = 1; i <= n + q; i++) {
    if (lst[i]) {
      ops.push_back({lst[i], n + q, d[i]});
    }
  }

  for (auto [l, r, v] : ops) {
    // std::cout << l << ' ' << r << ' ' << v.first << ' ' << v.second << '\n';
    update(l, r, 1, n + q, 1, v);
  }
  std::vector<int> f(k + 1);
  solve(1, n + q, 1, f);

  for (int i = 1; i <= q; i++) {
    if (isquery[i + n]) {
      std::cout << ans[i + n] << '\n';
    }
  }

  return 0;
}