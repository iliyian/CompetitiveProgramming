// date: 2024-08-02 15:05:00
// tag: 较复杂的反悔贪心

#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  int n, m;
  std::cin >> n >> m;
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                      std::greater<>>
      q1, q2, q3, q4, q5;
  std::vector<int> a(n + 1), b(n + 1), ans(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i] >> b[i];
  }
  for (int i = 1; i <= n; i++) {
    q1.push({a[i], i});
    q4.push({b[i], i});
  }
  int res = 0;
  for (int i = 1; i <= m; i++) {
    int op = 0, mn = LLONG_MAX, p = 0, q = 0;
    while (!q1.empty() && ans[q1.top().second] != 0)
      q1.pop(); // 0->1
    if (!q1.empty() && q1.top().first < mn) {
      mn = q1.top().first, p = q1.top().second;
      op = 1;
    }

    while (!q2.empty() && ans[q2.top().second] != 1)
      q2.pop(); // 1->2
    if (!q2.empty() && q2.top().first < mn) {
      mn = q2.top().first, p = q2.top().second;
      op = 2;
    }

    while (!q3.empty() && ans[q3.top().second] != 1)
      q3.pop(); // 1->0
    while (!q4.empty() && ans[q4.top().second] != 0)
      q4.pop(); // 0->2
    if (!q3.empty() && !q4.empty() && q3.top().first + q4.top().first < mn) {
      mn = q3.top().first + q4.top().first;
      p = q3.top().second, q = q4.top().second;
      op = 3;
    }

    while (!q5.empty() && ans[q5.top().second] != 2)
      q5.pop(); // 2->1
    while (!q4.empty() && ans[q4.top().second] != 0)
      q4.pop(); // 0->2
    if (!q5.empty() && !q4.empty() && q5.top().first + q4.top().first < mn) {
      mn = q5.top().first + q4.top().first;
      p = q5.top().second,
      q = q4.top()
              .second; // no need to pop to legalify it, it has been done upside
      op = 4;
    }

    res += mn;
    assert(mn != LLONG_MAX);
    assert(res >= 0 && mn >= 0);
    if (op == 1) {
      ans[p] = 1;
      q2.push({b[p] - a[p], p}); // 1->2
      q3.push({-a[p], p});       // 1->0
    } else if (op == 2) {
      ans[p] = 2;
      q5.push({a[p] - b[p], p}); // 2->1
    } else if (op == 3) {
      ans[p] = 0, ans[q] = 2;
      q1.push({a[p], p}); // 0->1
      q4.push({b[p], p}); // 0->2
      q5.push({a[q] - b[q], q});
    } else {
      ans[p] = 1, ans[q] = 2;
      q3.push({-a[p], p});
      q2.push({b[p] - a[p], p});
      q5.push({a[q] - b[q], q});
    }
  }
  std::cout << res << '\n';
  for (int i = 1; i <= n; i++) {
    std::cout << ans[i];
  }

  return 0;
}