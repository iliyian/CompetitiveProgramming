#include <bits/stdc++.h>
#define int long long
#define mid (s + t) / 2
#define lc seg[p].l
#define rc seg[p].r

constexpr int N = 2e5;
constexpr int inf = 0x3f3f3f3f3f3f3f3f;

struct Node {
  int a, b;
};

struct Seg {
  int l, r, cnt = 0, sum = 0;
} seg[N << 6];

int rt[N + 1];

int tot = 0;

int update(int x, int s, int t, int pre) {
  int p = ++tot;
  seg[p] = seg[pre];
  seg[p].cnt++, seg[p].sum += x;
  if (s == t) return p;
  if (x <= mid) lc = update(x, s, mid, lc);
  else rc = update(x, mid + 1, t, rc);
  return p;
}

int query(int s, int t, int p1, int p2, int k) {
  if (!k) return 0;
  int sum = seg[seg[p2].l].sum - seg[seg[p1].l].sum;
  int cnt = seg[seg[p2].l].cnt - seg[seg[p1].l].cnt;
  if (s == t) {
    // assert(cnt);
    return s * k;
  }
  if (cnt > k) return query(s, mid, seg[p1].l, seg[p2].l, k);
  return sum + query(mid + 1, t, seg[p1].r, seg[p2].r, k - cnt);
}

void solve() {
  int n;
  std::cin >> n;
  std::vector<Node> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i].a >> a[i].b;
  }
  std::sort(a.begin() + 1, a.end(), [&](const Node &x, const Node &y) {
    return x.b < y.b;
  });

  for (int i = 1; i <= n; i++) {
    rt[i] = update(a[i].a, 1, (int)1e9, rt[i - 1]);
  }
  auto get = [&](int k, int x) {
    return query(1, (int)1e9, rt[0], rt[x], k);
  };
  std::vector<int> ans(n + 1);
  auto work = [&](this auto &&self, int s, int t, int l, int r) -> void {
    if (s > t) return;
    int mn = inf, idx = 0;
    for (int i = std::max(mid, l); i <= r; i++) {
      int x = get(mid, i) + a[i].b;
      if (x < mn) {
        mn = x, idx = i;
      }
    }
    ans[mid] = mn;
    self(s, mid - 1, l, idx);
    self(mid + 1, t, idx, r);
  };
  work(1, n, 1, n);
  for (int i = 1; i <= n; i++) {
    std::cout << ans[i] << '\n';
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
