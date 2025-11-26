#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n + 1);
  std::vector<int> cnt(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    cnt[a[i]]++;
  }
  int c = 0;
  for (int i = 1; i <= n; i++) {
    if (cnt[i] % k) {
      std::cout << 0 << '\n';
      return;
    }
  }
  std::set<int> s;
  std::vector<int> now(n + 1);
  auto add = [&](int x) {
    now[x]++;
    if (now[x] > cnt[x] / k) {
      s.insert(x);
    }
  };
  auto del = [&](int x) {
    now[x]--;
    if (now[x] <= cnt[x] / k) {
      s.erase(x);
    }
  };
  int ans = 0;
  for (int i = 1, j = 1; i <= n; i++) {
    add(a[i]);
    while (!s.empty() && j <= i) {
      del(a[j++]);
    }
    ans += i - j + 1;
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