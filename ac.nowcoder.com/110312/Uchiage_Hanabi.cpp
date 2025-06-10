#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m, d;
  std::cin >> n >> m >> d;
  std::vector<int> a(m + 1), b(m + 1), t(m + 1), p(m + 1), tt = {0};
  for (int i = 1; i <= m; i++) {
    std::cin >> a[i] >> b[i] >> t[i];
    p[i] = i;
    tt.push_back(t[i]);
  }
  std::sort(tt.begin() + 1, tt.end());
  tt.erase(std::unique(tt.begin() + 1, tt.end()), tt.end());
  std::sort(p.begin() + 1, p.end(), [&](const int &x, const int &y) {
    return t[x] < t[y];
  });
  std::vector<int> f(n + 1);
  for (int i = 1; i < tt.size(); i++) {
    std::vector<int> nf(n + 2, LLONG_MIN / 3);
    std::vector<int> pre(n + 2), suf(n + 2);
    for (int j = 1; j <= m; j++) {
      if (t[p[j]] == tt[i]) {
        pre[a[p[j]]] += b[p[j]];
        suf[a[p[j]]] += b[p[j]];
      }
    }
    for (int j = 1; j <= n; j++) {
      pre[j] += pre[j - 1];
    }
    for (int j = n; j >= 1; j--) {
      suf[j] += suf[j + 1];
    }
    int sum = 0;
    for (int j = 1; j <= n; j++) {
      sum += suf[j];
    }
    std::deque<int> q;
    for (int j = 1; j <= n; j++) {
      sum -= suf[j];
      while (!q.empty() &&
          (q.front() < j - d * (tt[i] - tt[i - 1])
            || q.front() > j + d * (tt[i] - tt[i - 1]))) {
        q.pop_front();
      }
      while (!q.empty() && f[q.back()] < f[j]) {
        q.pop_back();
      }
      q.push_back(j);
      nf[j] = std::max(nf[j], f[q.front()] + sum);
      sum += pre[j];
    }
    sum = 0;
    for (int j = 1; j <= n; j++) {
      sum += pre[j];
    }
    while (!q.empty()) q.clear();
    for (int j = n; j >= 1; j--) {
      sum -= pre[j];
      while (!q.empty() &&
          (q.front() < j - d * (tt[i] - tt[i - 1])
            || q.front() > j + d * (tt[i] - tt[i - 1]))) {
        q.pop_front();
      }
      while (!q.empty() && f[q.back()] < f[j]) {
        q.pop_back();
      }
      q.push_back(j);
      nf[j] = std::max(nf[j], f[q.front()] + sum);
      sum += suf[j];
    }
    f = nf;
  }
  int ans = LLONG_MIN / 3;
  for (int i = 1; i <= n; i++) {
    ans = std::max(ans, f[i]);
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