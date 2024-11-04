#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 2);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::vector<int> s(n + 2), ss(n + 2);
  s[n] = a[n];
  for (int i = n - 1; i >= 1; i--) {
    s[i] = s[i + 1] + (n - i + 1) * a[i];
  }
  for (int i = 1; i <= n; i++) {
    ss[i] = ss[i - 1] + s[i];
  }
  for (int i = 1; i <= n; i++) {
    a[i] += a[i - 1];
  }
  std::vector<int> shu(n + 2);
  for (int i = 1; i <= n; i++) {
    shu[i] = shu[i - 1] + a[i];
  }
  auto query = [&](int src, int len) {
    int totlen = n - src + 1;
    int ans = s[src] - s[src + len];
    int cnt = totlen - len;
    int sidesum = cnt * (a[src + len - 1] - a[src - 1]);
    return ans - sidesum;
  };
  int q;
  std::cin >> q;
  while (q--) {
    int l, r;
    std::cin >> l >> r;
    int li = std::ceil((n * 2 + 1 - sqrt(4 * n * n + 4 * n + 1 - 8 * l)) / 2.0);
    int ri = std::ceil((n * 2 + 1 - sqrt(4 * n * n + 4 * n + 1 - 8 * r)) / 2.0);
    // std::cout << l << ' ' << r << ' ' << li << ' ' << ri << '\n';
    if (ri == li) {
      int lpos = (n + n - li + 2) * (li - 1) / 2;
      int lidx = l - lpos, ridx = r - lpos;
      int ans = shu[li - 1 + ridx] - shu[li - 1 + lidx - 1];
      int top = (r - l + 1) * a[ri - 1];
      std::cout << ans - top << '\n';
      continue;
    }
    int ans = ss[ri - 1] - ss[li - 1];

    int lilen = (n + n - li + 2) * (li - 1) / 2;
    int len = l - lilen - 1;
    ans -= query(li, len);

    int rilen = (n + n - ri + 2) * (ri - 1) / 2;
    ans += query(ri, r - rilen);

    std::cout << ans << '\n';
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int _ = 1;

  while (_--) {
    solve();
  }

  return 0;
}