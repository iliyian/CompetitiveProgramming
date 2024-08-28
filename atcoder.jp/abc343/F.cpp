// date: 2024-08-18 09:49:49
// tag: 线段树区间次大值维护与计数与单点修改

#include <bits/stdc++.h>
#define int long long
#define lc p << 1
#define rc p << 1 | 1
#define mid (s + t) / 2
// using namespace std;

constexpr int N = 2e5;

struct Seg {
  int m1, m2, n1, n2;
};

Seg merge(const Seg &x, const Seg &y) {
  if (y.n1 == 0 && y.n2 == 0) return x;
  if (x.n1 == 0 && x.n2 == 0) return y;
  std::array<int, 4> arr({x.m1, x.m2, y.m1, y.m2});
  std::sort(arr.begin(), arr.end(), std::greater());
  int m1 = arr[0], m2 = arr[0];
  for (int i = 1; i < 4; i++) {
    if (m2 != arr[i]) {
      m2 = arr[i];
      break;
    }
  }
  return Seg{
    m1,
    m2,
    (m1 == x.m1 ? x.n1 : m1 == x.m2 ? x.n2 : 0) + (m1 == y.m1 ? y.n1 : m1 == y.m2 ? y.n2 : 0),
    (m2 == x.m2 ? x.n2 : m2 == x.m1 ? x.n1 : 0) + (m2 == y.m2 ? y.n2 : m2 == y.m1 ? y.n1 : 0),
  };
}

std::vector<Seg> seg(N << 2);
std::vector<int> a(N + 1);

Seg build(int s, int t, int p) {
  if (s == t) {
    return seg[p] = {a[s], a[s], 1, 1};
  }
  return seg[p] = merge(build(s, mid, lc), build(mid + 1, t, rc));
}

void modify(int x, int s, int t, int p, int c)  {
  if (x > t || x < s) return;
  if (x == s && x == t) {
    seg[p] = {c, c, 1, 1};
    return;
  }
  modify(x, s, mid, lc, c);
  modify(x, mid + 1, t, rc, c);
  seg[p] = merge(seg[lc], seg[rc]);
}

Seg query(int l, int r, int s, int t, int p) {
  if (l > t || r < s) return Seg{};
  if (l <= s && t <= r) {
    return seg[p];
  }
  return merge(query(l, r, s, mid, lc), query(l, r, mid + 1, t, rc));
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("F.in", "r", stdin);
  freopen("F.out", "w", stdout);

  int n, q;
  std::cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  build(1, n, 1);
  while (q--) {
    int op, x, y;
    std::cin >> op >> x >> y;
    if (op == 1) {
      modify(x, 1, n, 1, y);
    } else {
      auto s = query(x, y, 1, n, 1);
      if (s.m1 == s.m2) {
        std::cout << 0 << '\n';
      } else {
        std::cout << s.n2 << '\n';
      }
    }
  }

  return 0;
}