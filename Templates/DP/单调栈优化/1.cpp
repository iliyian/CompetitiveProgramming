// date: 2024-08-18 11:27:53
// tag: 单调栈优化dp

#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  // std::vector<int> f(n + 1);
  // int realans = INT_MAX;
  // for (int i = 1; i <= n; i++) {
  //   int pre = a[i] - 1;
  //   for (int j = i - 1; j >= 1; j--) {
  //     f[i] += std::max<int>(0, a[j] - pre);
  //     pre = std::max<int>(0, std::min(pre - 1, a[j] - 1));
  //   }
  //   pre = a[i] - 1;
  //   for (int j = i + 1; j <= n; j++) {
  //     f[i] += std::max<int>(0, a[j] - pre);
  //     pre = std::max<int>(0, std::min(pre - 1, a[j] - 1));
  //   }
  //   realans = std::min(realans, f[i] + a[i]);
  // }

  std::stack<int> s;
  std::vector<int> fl(n + 1), fr(n + 1);
  auto calc = [&](int h, int len) {
    len = std::min(len, h);
    return len * (h + h - len + 1) / 2;
  };
  int sum = 0, inisum = 0;
  s.push(0);
  for (int i = 1; i <= n; i++) {
    inisum += a[i];
    while (s.size() > 1 && i - s.top() > a[i] - a[s.top()]) {
      int u = s.top(); s.pop();
      sum -= calc(a[u], u - s.top());
    }
    sum += calc(a[i], i - s.top());
    s.push(i);
    fl[i] = inisum - sum;
  }
  while (!s.empty()) s.pop();
  s.push(n + 1);
  sum = inisum = 0;
  for (int i = n; i >= 1; i--) {
    inisum += a[i];
    while (s.size() > 1 && s.top() - i > a[i] - a[s.top()]) {
      int u = s.top(); s.pop();
      sum -= calc(a[u], s.top() - u);
    }
    sum += calc(a[i], s.top() - i);
    s.push(i);
    fr[i] = inisum - sum;
  }
  int ans = LLONG_MAX;
  for (int i = 1; i <= n; i++) {
    ans = std::min(ans, fl[i] + fr[i] + a[i]);
  }
  // std::cout << ans << ' ' << realans << '\n';
  std::cout << ans << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}