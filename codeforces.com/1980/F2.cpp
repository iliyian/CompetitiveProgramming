// date: 2024-08-01 14:57:52
// tag: 

#include <algorithm>
#include <bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
// using namespace std;

struct Node {
  int x, y, id;
};

void solve() {
  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector<Node> a(k + 1);
  for (int i = 1; i <= k; i++) {
    std::cin >> a[i].x >> a[i].y;
    a[i].id = i;
  }
  auto cmp = [&](const Node &x, const Node &y) {
    if (x.x != y.x) {
      return x.x > y.x;
    }
    return x.y < y.y;
  };
  std::sort(a.begin() + 1, a.end(), cmp);
  std::vector<int> ans(k + 3), px(k + 3), py(k + 3), s(k + 3);
  a.push_back({0, 0, 0});
  px[1] = n, py[1] = m + 1;
  int sum = 0;
  for (int i = 1; i <= k + 1; i++) {
    s[i] = s[i - 1];
    py[i + 1] = py[i], px[i + 1] = px[i];
    if (a[i].y < py[i]) {
      ans[a[i].id] = 1;
      s[i] += (py[i] - 1) * (px[i] - a[i].x);
      py[i + 1] = a[i].y, px[i + 1] = a[i].x;
    }
  }
  std::cout << s[k + 1] << '\n';
  for (int i = 1; i <= k + 1; i++) {
    if (!ans[a[i].id]) continue;
    int x = px[i], y = py[i], sum = s[i - 1];
    for (int j = i + 1; j <= k + 1; j++) {
      if (a[j].y < y) {
        sum += (y - 1) * (x - a[j].x);
        y = a[j].y, x = a[j].x;
      }
      if (ans[a[j].id]) {
        ans[a[i].id] = sum - s[j];
        break;
      }
    }
  }
  for (int i = 1; i <= k; i++) {
    std::cout << ans[i] << " \n"[i == k];
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("F.in", "r", stdin);
  freopen("F2.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}