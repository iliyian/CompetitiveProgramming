#include <bits/stdc++.h>
#define int long long

void output(long double x){
  static char s[25];
  sprintf(s,"%.4Le",x);
  for(int i:{0,1,2,3,4,5,6,7}) printf("%c",s[i]);
  printf("%c",s[strlen(s)-1]);
}

void solve() {
  int n, m, X, Y;
  // std::cin >> n >> m >> X >> Y;
  scanf("%lld%lld%lld%lld", &n, &m, &X, &Y);
  std::vector<int> a(m + 1);
  for (int i = 1; i <= m; i++) {
    // std::cin >> a[i];
    scanf("%lld", &a[i]);
  }
  std::vector<int> h(n + 1), w(n + 1), p(n + 1);
  for (int i = 1; i <= n; i++) {
    // std::cin >> h[i] >> w[i];
    scanf("%lld%lld", &h[i], &w[i]);
    p[i] = i;
  }
  long double ans = std::numeric_limits<long double>::max() / 3;
  auto calc = [&](double x) {
    long double ans = 0, xx = x;
    for (int i = 1; i <= m; i++) {
      ans += x * a[i];
      x = x * xx;
    }
    return ans;
  };
  auto integrate = [&](long double x) {
    int step = 600;
    long double dx = x / step, ans = 0;
    for (int i = 0; i < step; i++) {
      long double lx = i * dx, rx = (i + 1) * dx;
      long double dy = calc(rx) - calc(lx);
      ans += std::hypot(dx, dy);
    }
    return ans;
  };
  auto getk = [&](long double x, long double y) {
    return y / x;
  };
  do {
    long double x = 0, cur = 0, y = 0;
    for (int i = 2; i <= n; i++) {
      long double l = x, r = 1e9, ans = 0;
      while (r - l > 1e-7) {
        long double mid = (l + r) / 2;
        if (std::hypot(x - mid, y - calc(mid)) >= std::max(h[p[i - 1]], h[p[i]])
      && (calc(mid) - Y) * (x - X) >= (y + h[p[i - 1]] - Y) * (mid - X)
    //  && getk(mid - X, calc(mid) - Y) >= getk(x - X, y + h[p[i - 1]] - Y)
    ) r = mid, ans = mid;
        else l = mid;
      }
      x = ans;
      y = calc(x);
      cur += integrate(x) * w[p[i]];
    }
    ans = std::min(ans, cur);
  } while (std::next_permutation(p.begin() + 1, p.end()));
  output(ans);
  printf("\n");
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  scanf("%lld", &t);
  // std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}