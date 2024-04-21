// wa#01: 搞错题目含义
// wa#02: 搞错数组
// wa#03: 不足够贪心

#include <bits/stdc++.h>
#define N 400005
using namespace std;

int a[N], b[N], idx[N], ans[N];

void solve() {
  int n, x;
  cin >> n >> x;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  iota(idx, idx + n, 0);
  sort(idx, idx + n, [&](const int &x, const int &y) {
    return a[x] < a[y];
  });
  sort(b, b + n);
  for (int i = 0; i < x; i++)
    ans[idx[n - x + i]] = b[i];
    // ans后面x个是b前x小
    // 同时对应a前x大
  for (int i = x; i < n; i++)
    ans[idx[i - x]] = b[i];
  for (int i = 0; i < n; i++)
    x -= a[i] > ans[i];
  if (!x) {
    cout << "YES\n";
    for (int i = 0; i < n; i++)
      cout << ans[i] << " \n"[i == n - 1];
  } else cout << "NO\n";
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("C.in", "r", stdin);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}