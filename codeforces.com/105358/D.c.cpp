#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 10;
// const long long inf = ((long long) 1 << 63) - 1;

// pair <long long, long long> a[maxn];

long long n, ans, p, a, b, q, c, d, m, t, k, k1;

void solve() {
  scanf("%lld %lld %lld", &p, &a, &b);
  scanf("%lld %lld %lld", &q, &c, &d);
  scanf("%lld %lld", &m, &t);
  while (t >= a + b + c + d && p <= m) {
    k = m / p;
    k1 = (p - m % p + k * (q - p) - 1) / (k * (q - p));
    if ((t - b - d) / (a + c) >= k1 * k) {
      t -= k1 * (k * (a + c) + b + d);
      m += k1 * k * (q - p);
    } else if ((t - b - d) / (a + c) >= k) {
      k1 = (t - b - d) / (a + c) * k;
      t -= k1 * (k * (a + c) + b + d);
      m += k1 * k * (q - p);
    } else {
      k1 = (t - b - d) / (a + c);
      t -= k1 * (a + c) + b + d;
      m += k1 * (q - p);
    }
  }
  printf("%lld\n", m);
}

int main() {
  freopen("D.in", "r", stdin);
  int T;
  scanf("%d", &T);
  // cout <<inf;
  while (T--) {
    solve();
  }
}
