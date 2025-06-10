#include <bits/stdc++.h>
#define int long long

constexpr int N = 1e7;
std::vector<int> pri;
bool vis[N + 1];

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::sort(a.begin() + 1, a.end());
  for (int i = 1; i <= n; i++) {
    a[i] += a[i - 1];
  }
  int l = 0, r = n - 1, ans = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (a[n] - a[mid] >= pri[n - mid - 1]) r = mid - 1, ans = mid;
    else l = mid + 1;
  }
  std::cout << ans << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  memset(vis, 0, sizeof(vis));
  for (int i = 2; i <= N; i++) {
    if (!vis[i]) {
      pri.push_back(i);
    }
    for (int p : pri) {
      if (i * p > N) break;
      vis[i * p] = true;
      if (i % p == 0) break;
    }
  }
  for (int i = 1; i < pri.size(); i++) {
    pri[i] += pri[i - 1];
  }

  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}