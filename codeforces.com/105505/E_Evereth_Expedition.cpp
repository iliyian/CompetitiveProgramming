#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 2);
  std::set<int> s, vis;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    if (!a[i]) s.insert(i);
    vis.insert(a[i]);
  }
  // for (int i = 1; i <= n && !s.empty(); i++) {
  //   if (a[i]) {
  //     if (i == a[i]) {
  //       for (auto j : s) {
  //         if (j > i) break;
  //         // if (vis.count(j)) {
  //         //   std::cout << "*\n";
  //         //   return;
  //         // }
  //         vis.insert(j);
  //         a[j] = j;
  //       }
  //     } else if (a[i] == n - i + 1) {
  //       for (auto j : s | std::views::reverse) {
  //         if (j < i) break;
  //         // if (vis.count(n - j + 1)) {
  //         //   std::cout << "*\n";
  //         //   return;
  //         // }
  //         vis.insert(n - j + 1);
  //         a[j] = n - j + 1;
  //       }
  //     }
  //   }
  // }
  // for (int i = 1; i <= n; i++) {
  //   std::cerr << a[i] << " \n"[i == n];
  // }
  int l = 1, r = n, cur = 1;
  std::vector<int> lv(n + 1), rv(n + 1);
  int prv = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i]) {
      prv = i;
    }
    lv[i] = prv;
  }
  prv = n + 1;
  for (int i = n; i >= 1; i--) {
    if (a[i]) {
      prv = i;
    }
    rv[i] = prv;
  }
  while (l <= r) {
    // for (int i = 1; i <= n; i++) {
    //   std::cerr << a[i] << " \n"[i == n];
    // }
    if (a[l] == cur) cur++, l++;
    else if (a[r] == cur) cur++, r--;
    else {
      if (a[l] && a[r]) {
        std::cout << "*\n";
        return;
      }
      if (!a[l] && !a[r]) {
        // if (r - lv[r] < rv[l] - l || r - lv[r] == rv[l] - l && a[lv[r]] < a[rv[l]]) {
        if (a[lv[r]] < a[rv[l]] || a[lv[r]] == a[rv[l]] && r - lv[r] < rv[l] - l) {
          a[r--] = cur++;
        } else {
          a[l++] = cur++;
        }
      }
      else if (!a[l]) a[l++] = cur++;
      else a[r--] = cur++;
    }
  }
  for (int i = 1; i <= n; i++) {
    std::cout << a[i] << " \n"[i == n];
  }
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