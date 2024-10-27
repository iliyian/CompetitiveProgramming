#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define lc p << 1
#define rc p << 1 | 1
#define mid (s + t) / 2

using namespace __gnu_pbds;

constexpr int N = 4e6;

std::vector<int> d(N << 2);
int n;

void pull(int p) {
  d[p] = d[lc] + d[rc];
}

void build(int s, int t, int p) {
  if (s == t) {
    d[p] = 1;
    return;
  }
  build(s, mid, lc);
  build(mid + 1, t, rc);
  pull(p);
}

int sum(int l, int r, int s, int t, int p) {
  if (l > t || r < s) return 0;
  if (l <= s && t <= r) return d[p];
  return sum(l, r, s, mid, lc) + sum(l, r, mid + 1, t, rc);
}

int query(int s, int t, int p, int c) {
  if (s == t) return s;
  if (d[lc] >= c) return query(s, mid, lc, c);
  return query(mid + 1, t, rc, c - d[lc]);
}

void reset(int x, int s, int t, int p) {
  if (x > t || x < s) return;
  if (s == t) {
    d[p] = 0;
    return;
  }
  reset(x, s, mid, lc);
  reset(x, mid + 1, t, rc);
  pull(p);
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  freopen("B.in", "r", stdin);
  std::cin >> n;
  std::vector<int> a(n / 2 + 1), b(n / 2 + 1);
  for (int i = 1; i <= n / 2; i++) {
    std::cin >> a[i];
  }
  for (int i = 1; i <= n / 2; i++) {
    std::cin >> b[i];
  }
  std::vector<int> ansa, ansb;

  build(1, n, 1);
  for (int i = 1; i <= n / 2; i++) {
    int x = query(1, n, 1, a[i]);
    ansa.push_back(x);
    reset(x, 1, n, 1);
    
    int y = query(1, n, 1, b[i]);
    ansb.push_back(y);
    reset(y, 1, n, 1);
  }

  // tree<int, null_type, std::less<int>, rb_tree_tag, tree_order_statistics_node_update> s;
  // for (int i = 1; i <= n; i++) {
  //   s.insert(i);
  // }
  // for (int i = 1; i <= n / 2; i++) {
  //   auto x = s.find_by_order(a[i] - 1);
  //   ansa.push_back(*x);
  //   s.erase(x);

  //   auto y = s.find_by_order(b[i] - 1);
  //   ansb.push_back(*y);
  //   s.erase(y);
  // }
  for (auto x : ansa) {
    std::cout << x << ' ';
  }
  std::cout << '\n';
  for (auto x : ansb) {
    std::cout << x << ' ';
  }
  std::cout << '\n';
  return 0;
}