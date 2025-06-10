#include <bits/stdc++.h>
#define int long long

std::map<std::vector<int>, std::pair<int, int>> mp;

std::pair<int, int> bf(std::vector<int> &a) {
  auto b = a;
  std::sort(b.begin(), b.end());
  if (mp.count(b)) return mp[b];
  int x = 0;
  bool f = false;
  for (int i = 1; i < a.size(); i++) {
    x ^= a[i];
    if (a[i]) f = true;
  }
  if (!f) {
    return {0, 0};
  }
  if (!x) {
    int mx = 0, cnt = 0;
    for (int i = 1; i < a.size(); i++) {
      if (a[i] > 0) {
        int t = a[i];
        for (int j = 0; j < t; j++) {
          a[i] = j;
          auto [res, _] = bf(a);
          if (res > mx) {
            mx = res, cnt = 1;
          } else if (res == mx) {
            cnt++;
          }
        }
        a[i] = t;
      }
    }
    return mp[b] = {mx + 1, cnt};
  }
  int mn = LLONG_MAX, cnt = 0;
  for (int i = 1; i < a.size(); i++) {
    if ((a[i] ^ x) < a[i]) {
      a[i] ^= x;
      auto [res, _] = bf(a);
      if (res < mn) {
        mn = res, cnt = 1;
      } else if (res == mn) {
        cnt++;
      }
      a[i] ^= x;
    }
  }
  return mp[b] = {mn + 1, cnt};
}

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  int sum = 0, x = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    sum += a[i];
    x ^= a[i];
  }
  auto [xx, yy] = bf(a);
  std::cerr << xx << ' ' << yy << '\n';
  // return;
  if (x) {
    int cnt = 0, mx = 0;
    for (int i = 1; i <= n; i++) {
      cnt += (x ^ a[i]) <= a[i];
    }
    std::cout << sum - x + 1 << ' ' << cnt << '\n';
    return;
  }
  std::cout << "0: ";
  std::cout << sum << ' ';
  int cnt = 0, lo = 62;
  for (int i = 1; i <= n; i++) {
    lo = std::min(lo, (a[i] & -a[i]));
  }
  for (int i = 1; i <= n; i++) {
    cnt += !!(a[i] & lo);
  }
  std::cout << cnt << '\n';
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