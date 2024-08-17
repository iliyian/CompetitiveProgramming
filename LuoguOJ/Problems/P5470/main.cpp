// date: 2024-08-13 12:02:15
// tag: 6个堆维护的反悔贪心，通过4个替换方案增加交集

#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n, k, l;
  std::cin >> n >> k >> l;
  std::vector<int> a(n + 1), b(n + 1), typ(n + 1);
  std::priority_queue<std::pair<int, int>> q1, q2, q3, q4, q5, q6;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    q1.push({a[i], i});
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> b[i];
    q2.push({b[i], i});
  }
  int sum = 0, cnt = 0;
  for (int i = 1; i <= k; i++) {
    typ[q1.top().second] += 1;
    sum += q1.top().first;
    typ[q2.top().second] += 2;
    sum += q2.top().first;
    q1.pop();
    q2.pop();
  }
  for (int i = 1; i <= n; i++) {
    if (typ[i] == 1) {
      q3.push({- a[i], i});
    } else if (typ[i] == 2) {
      q4.push({- b[i], i});
    } else if (typ[i] == 3) {
      q6.push({- a[i] - b[i], i});
      cnt++;
    } else {
      q5.push({a[i] + b[i], i});
    }
  }
  for (int _ = cnt + 1; _ <= l; _++) {
    int op = 0, x = 0, y = 0, z = 0, mx = LLONG_MIN;
    // +ax-ay
    while (!q1.empty() && typ[q1.top().second] != 2) q1.pop();
    while (!q3.empty() && typ[q3.top().second] != 1) q3.pop();
    if (!q1.empty() && !q3.empty() && q1.top().first + q3.top().first > mx) {
      mx = q1.top().first + q3.top().first;
      x = q1.top().second, y = q3.top().second;
      op = 1;
    }

    // +bx-by
    while (!q2.empty() && typ[q2.top().second] != 1) q2.pop();
    while (!q4.empty() && typ[q4.top().second] != 2) q4.pop();
    if (!q2.empty() && !q4.empty() && q2.top().first + q4.top().first > mx) {
      mx = q2.top().first + q4.top().first;
      x = q2.top().second, y = q4.top().second;
      op = 2;
    }

    // +az+bz-ax-by
    while (!q5.empty() && typ[q5.top().second] != 0) q5.pop();
    while (!q3.empty() && typ[q3.top().second] != 1) q3.pop();
    while (!q4.empty() && typ[q4.top().second] != 2) q4.pop();
    if (!q5.empty() && !q3.empty() && !q4.empty() && q5.top().first + q3.top().first + q4.top().first > mx) {
      mx = q5.top().first + q3.top().first + q4.top().first;
      x = q3.top().second, y = q4.top().second, z = q5.top().second;
      op = 3;
    }

    // -az-bz+ax+by
    while (!q6.empty() && typ[q6.top().second] != 3) q6.pop();
    while (!q1.empty() && typ[q1.top().second] != 2) q1.pop();
    while (!q2.empty() && typ[q2.top().second] != 1) q2.pop();
    if (!q6.empty() && !q1.empty() && !q2.empty() && q6.top().first + q1.top().first + q2.top().first > mx) {
      mx = q6.top().first + q1.top().first + q2.top().first;
      z = q6.top().second, x = q1.top().second, y = q2.top().second;
      op = 4;
    }

    sum += mx;
    if (op == 1) {
      typ[x] = 3, typ[y] = 0;
      q6.push({- a[x] - b[x], x});
      q5.push({a[y] + b[y], y});
      q1.push({a[y], y});
      q2.push({b[y], y});
    } else if (op == 2) {
      typ[x] = 3, typ[y] = 0;
      q6.push({- a[x] - b[x], x});
      q5.push({a[y] + b[y], y});
      q1.push({a[y], y});
      q2.push({b[y], y});
    } else if (op == 3) {
      typ[z] = 3, typ[x] = typ[y] = 0;
      q6.push({-a[z] - b[z], z});

      q5.push({a[x] + b[x], x});
      q1.push({a[x], x});
      q2.push({b[x], x});

      q5.push({a[y] + b[y], y});
      q1.push({a[y], y});
      q2.push({b[y], y});
    } else if (op == 4) {
      typ[z] = 0, typ[x] = typ[y] = 3;
      q6.push({-a[x] - b[x], x});
      q6.push({-a[y] - b[y], y});

      q5.push({a[z] + b[z], z});
      q1.push({a[z], z});
      q2.push({b[z], z});
    }
  }
  std::cout << sum << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}