// date: 2024-09-04 18:51:28
// tag: 滑动窗口，集合值计数，

#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n, k, q;
  std::cin >> n >> k >> q;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    a[i] -= i;
  }
  std::map<int, int> cnt;
  std::vector<int> ans(n + 1);
  int mxn = 0;
  for (int i = 1; i <= k; i++) {
    cnt[a[i]]++;
    if (cnt[a[i]] > cnt[mxn]) {
      mxn = a[i];
    }
  }
  std::set<std::pair<int, int>, std::greater<>> s;
  for (auto &[k, v] : cnt) {
    s.insert({v, k});
  }
  for (int i = k + 1; i <= n; i++) {
    ans[i - k] = k - s.begin()->first;

    int ky = a[i - k];
    s.erase({cnt[ky], ky});
    cnt[ky]--;
    s.insert({cnt[ky], ky});

    ky = a[i];
    s.erase({cnt[ky], ky});
    cnt[ky]++;
    s.insert({cnt[ky], ky});

  }
  ans[n + 1 - k] = k - s.begin()->first;
  for (int i = 1; i <= q; i++) {
    int l, r;
    std::cin >> l >> r;
    std::cout << ans[l] << '\n';
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("G1.in", "r", stdin);
  freopen("G1.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}