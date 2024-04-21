// 模拟退火
// wa#01: ??? 

#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define N 32
// #define int long long
using namespace std;

int a[N], n, ans;

mt19937 R(random_device{}());

int calc() {
  int sum = 0;
  for (int i = 1; i <= n; i++)
    sum += a[i] * (i <= n / 2 ? 1 : -1);
  return abs(sum);
}

// void swap(int &x, int &y) {
//   x ^= y;
//   y ^= x;
//   x ^= y;
// }

void SA() {
  double beginT = 5000, endT = 1e-5, down = 0.911;
  for (double t = beginT; t > endT; t *= down) {
    // int len = (n - 1) / 2 + 1;
    int x = R() % n + 1, y = R() % n + 1;
    swap(a[x], a[y]);
    int sum = calc();
    int delta = sum - ans;
    if (sum < ans) {
      ans = sum;
    } else if (exp(-delta / t) > (double)R() / UINT_MAX)
      ans = sum;
    else swap(a[x], a[y]);
  }
}

void solve() {
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  ans = calc();
  for (int i = 0; i < 1000; i++)
    SA();
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int T; cin >> T;
  while (T--) solve();
  return 0;
}