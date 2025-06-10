#include <bits/stdc++.h>
#define int long long

int ask1(int l, int r) {
  std::cout << "? 1 ";
  std::cout << r - l + 1 << ' ';
  for (int i = l; i <= r; i++) {
    std::cout << i << ' ';
  }
  std::cout << std::endl;
  int ans;
  std::cin >> ans;
  return ans;
}

void ask2(int x) {
  std::cout << "? 2 " << x << std::endl;
}

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 2; i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  int rt = 1, l = 2, r = n;
  while (l <= r) {
    int mid = (l + r) / 2;
    int ans1 = ask1(2, mid);
    ask2(1);
    int ans2 = ask1(2, mid);
    if (std::abs(ans1 - ans2) != 2 * (mid - 2 + 1)) {
      r = mid - 1, rt = mid;
    } else {
      l = mid + 1;
    }
  }
  std::vector<int> ans(n + 1);
  int rtv = ask1(rt, rt), v1 = 0;
  ans[rt] = rtv;
  if (rt != 1) {
    v1 = ask1(1, 1) - rtv;
    ans[1] = v1;
  }
  for (int i = 1; i <= n; i++) {
    if (i != rt && i != 1) {
      int val = ask1(i, i);
      ans[i] = val - v1 - rtv;
    }
  }
  std::cout << "! ";
  for (int i = 1; i <= n; i++) {
    std::cout << ans[i] << ' ';
  }
  std::cout << std::endl;
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}