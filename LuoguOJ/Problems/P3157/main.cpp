// date: 2024-08-08 12:29:35
// tag: cdq分治，三维偏序

#include <bits/stdc++.h>
#define int long long
// using namespace std;

constexpr int N = 1e5;

struct Node {
  int id, x, t;
};

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n, m;
  std::cin >> n >> m;
  std::vector<Node> a(n + 1);
  std::vector<int> pos(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i].x;
    a[i].id = i;
    a[i].t = m + 1;
    pos[a[i].x] = i;
  }
  for (int i = 1; i <= m; i++) {
    int x;
    std::cin >> x;
    a[pos[x]].t = i;
  }

  auto cmpxr = [&](const Node &x, const Node &y) { return x.x > y.x; };
  auto cmpxl = [&](const Node &x, const Node &y) { return x.x > y.x; };

  std::vector<int> d(N + 5);
  auto add = [&](int x, int c) {
    for (int i = x; i <= N; i += i & -i)
      d[i] += c;
  };
  auto query = [&](int x) {
    int ans = 0;
    for (int i = x; i > 0; i -= i & -i) {
      ans += d[i];
    }
    return ans;
  };

  std::vector<int> del(m + 2);
  auto cdq = [&](auto self, int l, int r) -> void {
    if (l == r)
      return;
    int mid = (l + r) / 2;
    self(self, l, mid);
    self(self, mid + 1, r);
    std::sort(a.begin() + l, a.begin() + mid + 1, cmpxr);
    std::sort(a.begin() + mid + 1, a.begin() + r + 1, cmpxr);
    int i = l, j = mid + 1;
    while (j <= r) {
      while (i <= mid && a[i].x > a[j].x) {
        add(a[i++].t, 1);
      }
      del[a[j].t] += query(m + 2) - query(a[j].t);
      j++;
    }
    for (int k = l; k < i; k++) {
      add(a[k].t, -1);
    }
    std::reverse(a.begin() + l, a.begin() + mid + 1);
    std::reverse(a.begin() + mid + 1, a.begin() + r + 1);
    i = l, j = mid + 1;
    while (i <= mid) {
      while (j <= r && a[i].x > a[j].x) {
        add(a[j++].t, 1);
      }
      del[a[i].t] += query(m + 2) - query(a[i].t);
      i++;
    }
    for (int k = mid + 1; k < j; k++) {
      add(a[k].t, -1);
    }
  };

  int ini = 0;
  for (int i = 1; i <= n; i++) {
    ini += query(n + 1) - query(a[i].x);
    add(a[i].x, 1);
  }
  for (int i = 1; i <= n; i++) {
    add(a[i].x, -1);
  }

  cdq(cdq, 1, n);

  for (int i = 1; i <= m; i++) {
    del[i] += del[i - 1];
  }
  for (int i = 0; i < m; i++) {
    std::cout << ini - del[i] << '\n';
  }
  std::cout << '\n';

  return 0;
}