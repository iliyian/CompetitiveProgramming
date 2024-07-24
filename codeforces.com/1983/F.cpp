// date: 2024-07-24 13:12:27
// tag: 

#include <bits/stdc++.h>
#define int long long
#define N ((int)1e5 + 5)
// using namespace std;

std::vector<int> mx(N << 5);
std::vector<std::array<int, 2>> ch(N << 5);

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++ ) {
    std::cin >> a[i];
  }

  int tot = 1;
  auto insert = [&](int x, int id) {
    int u = 1;
    for (int i = 62; i >= 0; i--) {
      int p = x >> i & 1;
      if (!ch[u][p]) ch[u][p] = ++tot;
      u = ch[u][p];
      mx[u] = std::max(mx[u], id);
    }
  };

  auto query = [&](int x, int mid) -> int {
    int u = 1, pos = 0;
    for (int i = 62; i >= 0; i--) {
      int ix = x >> i & 1, im = mid >> i & 1;
      if (im) {
        pos = std::max(pos, mx[ch[u][ix]]);
      }
      u = ch[u][im ^ ix];
    }
    pos = std::max(pos, mx[u]);
    return pos;
  };

  auto check = [&](int mid) {
    int ans = 0, pos = 0;
    for (int i = 1; i <= n; i++) {
      pos = std::max(pos, query(a[i], mid));
      ans += pos;
      insert(a[i], i);
    }
    for (int i = 0; i <= tot; i++) {
      mx[i] = 0;
      ch[i] = {0, 0};
    }
    tot = 1;
    return ans;
  };

  int l = 0, r = 0x3f3f3f3f3f3f3f3f, ans = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(mid) >= k) r = mid - 1, ans = mid;
    else l = mid + 1;
  }
  std::cout << ans << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("F.in", "r", stdin);
  freopen("F.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}