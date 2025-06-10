// date: 2025-05-12 18:45:35
// tag: 有点像单调队列的变种，这有点像mex的本质,minimum excluded嘛，所以求前缀mex和，就把后缀min给加起来就好啦，然后只要用类似优先队列的东西动态维护每一个min的贡献就可以了

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n * 2 + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    a[i + n] = a[i];
  }
  std::deque<int> q = {0};
  int sum = 0, ans = 0;
  for (int i = 1; i <= n * 2; i++) {
    while (q.size() >= 2 && a[q.back()] >= a[i]) {
      int x = q.back();
      q.pop_back();
      int p = q.back();
      sum -= a[x] * (x - p);
    }
    sum += a[i] * (i - q.back());
    q.push_back(i);
    if (i >= n) {
      ans = std::max(ans, sum + n);
    }
  }
  std::cout << ans << '\n';
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