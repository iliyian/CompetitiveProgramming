// Said no more counting dollars. We'll be counting stars.
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define IOS                                                                    \
  ios::sync_with_stdio(0);                                                     \
  cin.tie(0);                                                                  \
  cout.tie(0)
#define For(i, j, k) for (int i = j; i <= k; i++)
#define Rof(i, j, k) for (int i = j; i >= k; i--)
#define int long long
#define N 400010
#define low (x & (-x))
int n, a[N], c[3][N], m, base;
char ch;
void add(int T, int x, int y) {
  while (x <= m) {
    c[T][x] += y;
    x += low;
  }
}
int que(int T, int x) {
  int res = 0;
  while (x) {
    res += c[T][x];
    x -= low;
  }
  return res;
}
int mo(int x) { return (x % 3 + 3) % 3; }
void work() {
  cin >> n;
  m = n << 1 | 1;
  base = n + 1;
  For(i, 0, 2) For(j, 0, m) c[i][j] = 0;
  For(i, 1, n) {
    cin >> ch;
    a[i] = a[i - 1] + (ch == '+' ? 1 : -1);
  }
  int ans = 0;
  Rof(i, n, 0) {
    ans += que(mo(a[i]), a[i] + base);
    add(mo(a[i]), a[i] + base, 1);
  }
  cout << ans << endl;
}
signed main() {
  IOS;
  int T;
  cin >> T;
  while (T--)
    work();
  return 0;
}