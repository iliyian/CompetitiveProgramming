// date: 2025-05-06 18:45:58
// tag: 还是比较吃观察的一个dp，将操作规约化，贪心化。然后是平凡的单调队列优化？主要是要观察到子结构的独立性这才能用dp，这就可以通过枚举分界点来实现。观察到必然可以用最小值来弄？

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), f(n + 2, LLONG_MAX / 3);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  f[n + 1] = 0;
  for (int i = n; i >= 1; i--) {
    std::deque<int> q;
    q.push_back(i);
    for (int j = i + 1; j <= n + 1; j++) {
      f[i] = std::min(f[i], f[j] + (j - i) * a[q.front()] + j - q.front() - 1 + j - i - 1);
      if (j <= n) {
        while (!q.empty() && a[q.back()] > a[j]) q.pop_back();
        q.push_back(j);
      }
    }
  }
  std::cout << f[1] << '\n';
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