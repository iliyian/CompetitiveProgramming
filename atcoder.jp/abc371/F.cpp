// date: 2024-10-06 16:18:27
// tag: 线段树，二分

#include <bits/stdc++.h>
#define int long long
#define lc p << 1
#define rc p << 1 | 1
#define mid (s + t) / 2

constexpr int N = 2e5;
int n, m;
std::vector<int> tag(N << 2, INT_MIN), a(N << 2);

struct Seg {
  int sum = 0, mx = INT_MIN, len = 0;
  Seg operator + (const Seg &b) const {
    return {sum + b.sum, std::max(mx, b.mx), len + b.len};
  }
} seg[N << 2];

void pull(int p) {
  seg[p] = seg[lc] + seg[rc];
}

void build(int s, int t, int p) {
  if (s == t) {
    seg[p] = {a[s], a[s], 1};
    return;
  }
  build(s, mid, lc);
  build(mid + 1, t, rc);
  pull(p);
}

void P(int p, int c) {
  seg[p] = {c * seg[p].len, c, seg[p].len};
  tag[p] = c;
}

void push(int p) {
  if (tag[p] != INT_MIN) {
    P(lc, tag[p]);
    P(rc, tag[p]);
    tag[p] = INT_MIN;
  }
}

Seg query(int l, int r, int s, int t, int p) {
  if (l > t || r < s) return {};
  if (l <= s && t <= r) return seg[p];
  push(p);
  return query(l, r, s, mid, lc) + query(l, r, mid + 1, t, rc);
}

void modify(int l, int r, int s, int t, int p, int c) {
  if (l > t || r < s) return;
  if (l <= s && t <= r) {
    P(p, c);
    return;
  }
  push(p);
  modify(l, r, s, mid, lc, c);
  modify(l, r, mid + 1, t, rc, c);
  pull(p);
}

signed main() {
  freopen("F.in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    a[i] -= i;
  }
  build(1, n, 1);
  std::cin >> m;
  int ans = 0;
  for (int i = 1; i <= m; i++) {
    int idx, x;
    std::cin >> idx >> x;
    x -= idx;
    int s = 1, t = n, cur = query(idx, idx, 1, n, 1).sum;
    if (cur == x) continue;
    while (s < t) {
      if (query(1, mid, 1, n, 1).mx >= x) t = mid;
      else s = mid + 1;
    }
    if (cur < x) {
      if (s != n || query(1, n, 1, n, 1).mx >= x) s--;
      ans += x * (s - idx + 1) - query(idx, s, 1, n, 1).sum;
      modify(idx, s, 1, n, 1, x);
    } else {
      ans += query(s, idx, 1, n, 1).sum - x * (idx - s + 1);
      modify(s, idx, 1, n, 1, x);
    }
    // std::cout << s << '\n';
  }
  std::cout << ans << '\n';
  return 0;
}