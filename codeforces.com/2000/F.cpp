#include <bits/stdc++.h>
#define int long long
// using namespace std;

struct Node {
  int r, c;
  bool operator < (const Node &b) const {
    return std::min(r, c) > std::min(b.r, b.c);
  }
};

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<Node> a(n + 1);
  for (int i = 1; i <= n; i++) {
    int r, c;
    std::cin >> r >> c;
    a[i] = {r, c};
  }
  std::sort(a.begin() + 1, a.end(), [&](const Node &x, const Node &y) {
    return x.r + x.c < y.r + y.c;
  }); // w = r*c, v=r+c
  std::vector<int> f(k + 1, INT_MAX);
  std::vector<std::vector<int>> g(n + 1, std::vector<int>(k + 1));
  f[0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int v = k; v >= a[i].r + a[i].c; v--) {
      if (f[v] > f[v - a[i].r - a[i].c] + a[i].r * a[i].c) {
        f[v] = std::min(f[v], f[v - a[i].r - a[i].c] + a[i].r * a[i].c);
        g[i][v] = true;
      }
    }
  }

  auto check = [&](int sum) -> int {
    int ans = 0;
    std::priority_queue<Node> q;
    int tempv = sum;
    for (int i = n; i >= 1; i--) {
      if (g[i][tempv]) {
        ans += a[i].r * a[i].c;
        tempv -= a[i].r + a[i].c;
      } else {
        q.push({a[i].r, a[i].c});
      }
    }
    while (!q.empty() && sum < k) {
      auto [r, c] = q.top(); q.pop();
      if (r == 1 && c == 1) {
        sum += 2;
        ans++;
        continue;
      }
      if (r > c) std::swap(r, c);
      ans += r;
      sum++;
      q.push({r, c - 1});
    }
    if (sum < k) {
      return -1;
    }
    return ans;
  };

  int ans = INT_MAX;
  for (int i = k; i >= 0; i--) {
    if (f[i] != INT_MAX) {
      int res = check(i);
      if (res != -1) {
        ans = std::min(ans, res);
      }
    }
  }
  std::cout << (ans == INT_MAX ? -1 : ans) << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("F.in", "r", stdin);
  freopen("F.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}