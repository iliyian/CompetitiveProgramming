#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int l, r, L, R;
  std::cin >> l >> r >> L >> R;
  std::vector<int> a(102);
  a[l]++, a[r + 1]--;
  a[L]++, a[R + 1]--;
  int ll = 0, rr = 0, len = 0;
  for (int i = 1; i <= 100; i++) {
    a[i] += a[i - 1];
    if (a[i] == 2) {
      len++;
      if (!ll) ll = i;
      rr = i;
    }
  }
  if (!len) {
    std::cout << 1 << '\n';
    return;
  }
  std::cout << len - 1 + (a[ll - 1] > 0) + (a[rr + 1] > 0) << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}