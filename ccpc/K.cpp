#include <bits/stdc++.h>
#define int long long

int check(std::vector<int> &a, int n) {
  std::vector<int> pa(n + 1), siz(n + 1, 1);
  auto find = [&](auto self, int x) -> int {return x == pa[x] ? x : pa[x] = self(self, pa[x]);};
  auto merge = [&](int x, int y) -> bool {
    x = find(find, x), y = find(find, y);
    if (x == y) {
      return false;
    }
    if (siz[x] > siz[y]) std::swap(x, y);
    pa[x] = y;
    siz[y] += siz[x];
    return true;
  };
  std::iota(pa.begin(), pa.end(), 0);
  for (int i = 1; i <= n; i++) {
    merge(i, a[i]);
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += find(find, a[i]) == i;
  }
  return ans;
}

void solve() {
  int n;
  std::cin >> n;
  std::cout << n * (n + 1) / 2 << '\n';
  for (int i = n; i >= 1; i--) {
    std::cout << i << ' ';
  }
  std::cout << '\n';
}

// void solve() {
//   int n;
//   std::cin >> n;
//   std::vector<int> a(n + 1);
//   std::iota(a.begin() + 1, a.end(), 1);
//   auto ans = a;
//   int mx = 0;
//   do {
//     auto b = a;
//     int cur = 0;
//     for (int i = 1; i <= n; i++) {
//       int x = b[1];
//       std::shift_left(b.begin() + 1, b.end(), 1);
//       b[n] = x;
//       cur += check(b, n);
//     }
//     if (cur > mx) {
//       mx = cur, ans = a;
//     }
//   } while (std::next_permutation(a.begin() + 1, a.end()));
//   std::cout << mx << '\n';
//   for (auto i : ans) {
//     std::cout << i << ' ';
//   }
//   std::cout << '\n';
// }

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}