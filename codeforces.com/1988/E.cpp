// date: 2024-07-19 14:41:37
// tag: 暴力

#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  std::vector<std::vector<int>> mn(n + 1, std::vector<int>(21));
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    mn[i][0] = a[i];
  }
  for (int j = 1; j <= 20; j++) {
    for (int i = 1; i + (1 << (j - 1)) <= n; i++) {
      mn[i][j] = std::min(mn[i][j - 1], mn[i + (1 << (j - 1))][j - 1]);
    }
  }
  auto querymn = [&](int l, int r) {
    int len = std::__lg(r - l + 1);
    return std::min(mn[l][len], mn[r - (1 << len) + 1][len]);
  };

  std::vector<int> l(n + 1), r(n + 1);
  std::stack<int> s;
  for (int i = 1; i <= n; i++) {
    while (!s.empty() && a[s.top()] >= a[i]) {
      s.pop();
    }
    if (!s.empty()) {
      l[i] = s.top();
    } else {
      l[i] = 0;
    }
    s.push(i);
  }
  while (!s.empty()) s.pop();
  for (int i = n; i >= 1; i--) {
    while (!s.empty() && a[s.top()] >= a[i]) {
      s.pop();
    }
    if (!s.empty()) {
      r[i] = s.top();
    } else {
      r[i] = n + 1;
    }
    s.push(i);
  }

  std::vector<int> ans(n + 2);

  auto add = [&](int l, int r, int x) {
    if (l > r) return;
    ans[l] += x, ans[r + 1] -= x;
  };

  for (int j = 1; j <= n; j++) {
    // i < l[j], i > r[j]
    add(1, l[j] - 1, a[j] * (j - l[j]) * (r[j] - j));
    add(r[j] + 1, n, a[j] * (j - l[j]) * (r[j] - j));

    // l[j] < i < j, j < i < r[j], len - 1
    add(l[j] + 1, j - 1, a[j] * (j - l[j] - 1) * (r[j] - j));
    add(j + 1, r[j] - 1, a[j] * (j - l[j]) * (r[j] - j - 1));
  }

  for (int i = 1; i <= n; i++) {
    ans[i] += ans[i - 1];
  }

  for (int j = 1; j <= n; j++) {
    if (l[j] == 0) continue;
    int L = 1, R = l[j] - 1, k = l[j];
    // from l[j] to k, now the original value, not 0
    while (L <= R) {
      int mid = (L + R) / 2;
      if (querymn(mid, l[j] - 1) > a[j]) k = mid, R = mid - 1;
      else L = mid + 1;
    }
    ans[l[j]] += a[j] * (j - k) * (r[j] - j);
  }

  for (int j = 1; j <= n; j++) {
    if (r[j] == n + 1) continue;
    int L = r[j] + 1, R = n, k = r[j];
    while (L <= R) {
      int mid = (L + R) / 2;
      if (querymn(r[j] + 1, mid) > a[j]) k = mid, L = mid + 1;
      else R = mid - 1;
    }
    ans[r[j]] += a[j] * (j - l[j]) * (k - j);
  }

  for (int i = 1; i <= n; i++) {
    std::cout << ans[i] << " \n"[i == n];
  }
}

signed main() {
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