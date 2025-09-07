#include <bits/stdc++.h>
#define int long long

std::mt19937_64 rd(std::random_device{}());

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), b(n + 1), x(n + 1);
  std::vector<int> ax(n + 1), bx(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    x[i] = rd();
  }
  std::vector<int> pos(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> b[i];
    pos[b[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    ax[i] = ax[i - 1] ^ x[a[i]];
    bx[i] = bx[i - 1] ^ x[b[i]];
  }
  auto eq = [&](int l, int r) {
    int p = pos[a[r]];
    if (p < r - l + 1) return false;
    return (ax[r] ^ (l == 0 ? 0 : ax[l - 1])) == (bx[p] ^ bx[p - (r - l + 1)]);
  };
  int pre = 1, ans = 1;
  for (int i = 1; i <= n; i++) {
    if (!eq(pre, i)) {
      ans++;
      pre = i;
    }
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