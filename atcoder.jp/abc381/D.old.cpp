#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  int l = 1, r = n / 2, ans = 0;
  auto check = [&](int mid) -> bool {
    std::vector<int> cnt(n + 1);
    std::set<int> cnt2;
    int tot = 0;
    // std::cerr << tot << ' ' << cnt2.size() << '\n';
    auto add = [&](int x) {
      cnt[x]++;
      tot++;
      if (cnt[x] == 2) {
        cnt2.insert(x);
      } else {
        cnt2.erase(x);
      }
    };
    auto del = [&](int x) {
      cnt[x]--;
      tot--;
      if (cnt[x] == 2) {
        cnt2.insert(x);
      } else {
        cnt2.erase(x);
      }
    };
    for (int i = 1; i + 1 <= n; i += 2) {
      add(a[i]);
      add(a[i + 1]);
      if (tot > mid * 2) {
        del(a[i - mid * 2]);
        del(a[i - mid * 2 + 1]);
      }
      if (tot == mid * 2 && cnt2.size() == mid) {
        return true;
      }
    }
    std::fill(cnt.begin(), cnt.end(), 0);
    cnt.clear();
    cnt2.clear();
    tot = 0;
    for (int i = 2; i + 1 <= n; i += 2) {
      add(a[i]);
      add(a[i + 1]);
      if (tot > mid * 2) {
        del(a[i - mid * 2]);
        del(a[i - mid * 2 + 1]);
      }
      if (tot == mid * 2 && cnt2.size() == mid) {
        return true;
      }
    }
    return false;
  };
  // std::cerr << n << '\n';
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(mid)) l = mid + 1, ans = mid * 2;
    else r = mid - 1;
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