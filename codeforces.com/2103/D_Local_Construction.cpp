// date: 2025-04-23 23:53:28
// tag: 还是比较有意思的构造题，值域双指针。然而一开始想成拓扑排序了，其实这种比较复杂的关系不适合为图

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), c(n + 1);
  int pos = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    if (a[i] != -1) {
      c[a[i]]++;
    } else {
      pos = i;
    }
  }
  int l = 1, r = n;
  std::vector<int> ans(n + 1);
  for (int i = 1; i <= n; i++) {
    if (!c[i]) break;
    if (i % 2) {
      for (int j = 1; j < pos; j++) {
        if (a[j] == i) {
          ans[j] = r--;
        }
      }
      for (int j = n; j > pos; j--) {
        if (a[j] == i) {
          ans[j] = r--;
        }
      }
    } else {
      for (int j = 1; j < pos; j++) {
      // for (int j = pos - 1; j > 1; j--) {
        if (a[j] == i) {
          ans[j] = l++;
        }
      }
      for (int j = n; j > pos; j--) {
      // for (int j = pos + 1; j <= n; j++) {
        if (a[j] == i) {
          ans[j] = l++;
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    std::cout << (a[i] == -1 ? l : ans[i]) << ' ';
  }
  std::cout << '\n';
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