// date: 2024-08-13 10:02:08
// tag: 基于多个可删除堆的多选项渐进式反悔贪心

#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("I.in", "r", stdin);
  freopen("I.out", "w", stdout);

  int n, p, s;
  std::cin >> n >> p >> s;
  std::vector<int> a(n + 1), b(n + 1), typ(n + 1);
  std::priority_queue<std::pair<int, int>> q1, q2, q3;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    q1.push({a[i], i});
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> b[i];
  }
  int sum = 0;
  for (int i = 1; i <= p; i++) {
    auto [v, x] = q1.top();
    sum += v;
    typ[x] = 1;
    q2.push({b[x] - a[x], x});
    q1.pop();
  }
  for (int i = 1; i <= n; i++) {
    if (typ[i] == 0) {
      q3.push({b[i], i});
    }
  }
  for (int i = 1; i <= s; i++) {
    // 0->2
    while (!q3.empty() && typ[q3.top().second] != 0) q3.pop();
    int mx = LLONG_MIN, op = 0;
    if (!q3.empty() && q3.top().first > mx) {
      op = 1, mx = q3.top().first;
    }

    // 0->1,1->2
    while (!q1.empty() && typ[q1.top().second] != 0) q1.pop();
    while (!q2.empty() && typ[q2.top().second] != 1) q2.pop();
    if (!q1.empty() && !q2.empty() && q1.top().first + q2.top().first > mx) {
      op = 2;
      mx = q1.top().first + q2.top().first;
    }

    if (op == 1) {
      sum += q3.top().first;
      typ[q3.top().second] = 2;
      q3.pop();
    } else if (op == 2) {
      sum += q1.top().first + q2.top().first;
      typ[q2.top().second] = 2;
      q2.pop();

      q2.push({b[q1.top().second] - a[q1.top().second], q1.top().second});
      typ[q1.top().second] = 1;
      q1.pop();
    }
  }
  std::cout << sum << '\n';
  for (int i = 1; i <= n; i++) {
    if (typ[i] == 1) {
      std::cout << i << ' ';
    }
  }
  std::cout << '\n';
  for (int i = 1; i <= n; i++) {
    if (typ[i] == 2) {
      std::cout << i << ' ';
    }
  }
  std::cout << '\n';

  return 0;
}