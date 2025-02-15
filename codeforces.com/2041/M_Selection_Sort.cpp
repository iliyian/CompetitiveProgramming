// date: 2025-01-29 02:03:41
// tag: 贪心，模拟，同样是枚举低第一维，然后得到最优的第二维
// 通过维护当前的左右两侧所必要的需要排序的区间得到最优解
// 左侧界限在于这个界限和当前枚举的界限之间可能存在完全处于正确位置的，
// 右侧取决于左侧可以从1开始完全恢复到多少，如果左侧无能，右侧可能存在1，右侧交叠至左侧
// 否则区间不重叠，当前枚举的成为右边界，左边界是一直所维护的最后的不在正确位置上的
// 关于排序操作的一类抽象的问题

#include <bits/stdc++.h>
#define int long long

struct Node {
  int x, id, rnk;
};

void solve() {
  int n;
  std::cin >> n;
  std::vector<Node> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i].x;
    a[i].id = i;
  }
  std::sort(a.begin() + 1, a.end(), [&](const Node &x, const Node &y) {
    return std::tie(x.x, x.id) < std::tie(y.x, y.id);
  });
  for (int i = 1; i <= n; i++) {
    a[i].rnk = i;
  }
  std::sort(a.begin() + 1, a.end(), [&](const Node &x, const Node &y) {
    return x.id < y.id;
  });

  int ans = n * n;

  int l = 0, r = 0;
  std::priority_queue<int, std::vector<int>, std::greater<>> q;
  for (int i = 1; i <= n; i++) {
    if (q.empty() && a[i].rnk == r + 1) { // resolved
      r++;
    } else {
      l = i;
      q.push(a[i].rnk);
    }
    while (!q.empty() && q.top() == r + 1) {
      r++;
      q.pop();
    }
    ans = std::min(ans, l * l + (n - r) * (n - r));
  }
  l = n + 1, r = n + 1;
  // std::cerr << ans << '\n';
  std::priority_queue<int> q2;
  for (int i = n; i >= 1; i--) {
    if (q2.empty() && a[i].rnk == l - 1) { // resolved
      l--;
    } else {
      r = i; // necessary
      q2.push(a[i].rnk);
    }
    while (!q2.empty() && q2.top() == l - 1) {
      l--;
      q2.pop();
    }
    // std::cerr << i << ' ' << l << ' ' << r << '\n';
    ans = std::min(ans, (n - r + 1) * (n - r + 1) + (l - 1) * (l - 1));
  }
  std::cout << ans << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}