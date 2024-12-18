// date: 2024-08-18 12:52:27
// tag: 单调队列优化dp，区间最值

#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    a[i] += a[i - 1];
  }
  std::vector<std::array<int, 2>> f(n + 1);
  std::deque<int> q;
  q.push_back(0);
  for (int i = 1; i <= n; i++) {
    f[i][0] = std::max(f[i - 1][0], f[i - 1][1]);
    while (!q.empty() && q.front() < i - k) {
      q.pop_front();
    }
    while (!q.empty() && f[q.back()][0] - a[q.back()] < f[i][0] - a[i]) {
      q.pop_back();
    }
    q.push_back(i);
    f[i][1] = f[q.front()][0] - a[q.front()] + a[i];
  }
  std::cout << std::max(f[n][0], f[n][1]) << '\n';

  return 0;
}