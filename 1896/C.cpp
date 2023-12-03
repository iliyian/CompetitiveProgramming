// wa#01: 搞错题目含义
// wa#02: 搞错数组
// wa#03: 不足够贪心

#include <bits/stdc++.h>
#define N 400005
using namespace std;

int a[N], b[N], aid[N], tmp[N];

void solve() {
  int n, x;
  cin >> n >> x;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int i = 1; i <= n; i++)
    cin >> b[i];
  iota(aid + 1, aid + 1 + n, 1);
  sort(b + 1, b + 1 + n);
  sort(aid + 1, aid + 1 + n, [](const int &x, const int &y) {
    return a[x] < a[y];
  });
  int cnt = 0;
  copy(b + 1, b + 1 + n, tmp + 1);
  copy(tmp + 1, tmp + 1 + x, b + 1 + n - x);
  copy(tmp + 1 + x, tmp + 1 + n, b + 1);
  for (int i = 1; i <= n; i++)
    cnt += a[aid[i]] > b[i];
  if (x != cnt) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  for (int i = 1; i <= n; i++)
    cout << b[i] << " \n"[i == n];
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("C.in", "r", stdin);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}