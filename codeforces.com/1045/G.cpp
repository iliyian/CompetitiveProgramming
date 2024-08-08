// date: 2024-08-06 11:36:28
// tag: cdq分治

#include <bits/stdc++.h>
#define int long long
// using namespace std;

struct Node {
  int x, r, iq;
};

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("G.in", "r", stdin);
  freopen("G.out", "w", stdout);

  int n, k;
  std::cin >> n >> k;
  std::vector<Node> a(n + 1);
  std::vector<int> v = {LLONG_MIN};
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i].x >> a[i].r >> a[i].iq;
    v.push_back(a[i].x);
    v.push_back(a[i].x - a[i].r);
    v.push_back(a[i].x + a[i].r);
  }

  // int real = 0;
  // for (int i = 1; i <= n; i++) {
  //   for (int j = i + 1; j <= n; j++) {
  //     if (std::abs(a[i].iq - a[j].iq) <= k &&
  //         std::abs(a[i].x - a[j].x) <= std::min(a[i].r, a[j].r)) {
  //       real++;
  //     }
  //   }
  // }
  // std::cout << real << '\n';

  std::sort(v.begin(), v.end());
  v.erase(std::unique(v.begin(), v.end()), v.end());

  auto id = [&](int x) {
    return std::lower_bound(v.begin(), v.end(), x) - v.begin();
  };

  auto cmpiq = [&](const Node &x, const Node &y) { return x.iq < y.iq; };

  std::vector<int> d(v.size() + 5);
  auto add = [&](int x, int c) {
    for (int i = x; i < v.size(); i += i & -i) {
      d[i] += c;
    }
  };

  auto query = [&](int x) {
    int ans = 0;
    for (int i = x; i > 0; i -= i & -i) {
      ans += d[i];
    }
    return ans;
  };

  int ans = 0;
  auto cdq = [&](auto self, int l, int r) {
    if (l == r)
      return;
    int mid = (l + r) / 2;
    self(self, l, mid);
    self(self, mid + 1, r);
    std::sort(a.begin() + l, a.begin() + mid + 1, cmpiq);
    std::sort(a.begin() + mid + 1, a.begin() + r + 1, cmpiq);
    int L = l, R = l, j = mid + 1;
    while (j <= r) {
      while (R <= mid && a[R].iq <= a[j].iq + k)
        add(id(a[R++].x), 1);
      while (L <= mid && a[L].iq < a[j].iq - k)
        add(id(a[L++].x), -1);
      ans += query(id(a[j].x + a[j].r)) - query(id(a[j].x - a[j].r) - 1);
      j++;
    }
    for (int i = L; i < R; i++) {
      add(id(a[i].x), -1);
    }
  };

  std::sort(a.begin() + 1, a.end(),
            [&](const Node &x, const Node &y) { return x.r > y.r; });
  cdq(cdq, 1, n);
  std::cout << ans << '\n';

  return 0;
}