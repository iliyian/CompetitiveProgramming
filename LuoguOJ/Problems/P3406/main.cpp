#include <bits/stdc++.h>
#define int long long
using namespace std;

array<int, 1000001> p, a, b, A, B, C;

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> p[i];
    if (i) b[min(p[i], p[i - 1])]++, b[max(p[i], p[i - 1])]--;
  }
  for (int i = 1; i <= n; i++)
    a[i] = b[i] + a[i - 1];
  for (int i = 1; i <= n; i++)
    cin >> A[i] >> B[i] >> C[i];
  int ans = 0;
  for (int i = 1; i <= n; i++)
    ans += min(a[i] * A[i], C[i] + a[i] * B[i]);
  cout << ans;
  return 0;
}