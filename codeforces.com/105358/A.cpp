#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 1e5 + 10;
const long long inf = ((long long)1 << 31) - 1;

long long l[maxn], t[maxn], w[maxn], n, k;

bool check(long long x) {
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += x / (t[i] * l[i] + w[i]) * l[i] + (x % ())
           min(x % (t[i] * l[i] + w[i]), t[i] * l[i]) / t[i];
  }
  // cout<< x << ' '<< ans << endl;
  return ans >= k;
}

void solve() {
  std::cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    std::cin >> t[i] >> l[i] >> w[i];
  }
  int l = 1, r = 3e18;
  while (l < r) {
    int mid = (l + r) / 2;
    if (check(mid)) r = mid;
    else l = mid + 1;
  }
  std::cout << l << '\n';
}

signed main() {
  freopen("A.in", "r", stdin);
  int T;
  std::cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
