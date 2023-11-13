// date: 2023年11月10日
// 二分答案区间
// wa#01: 不开long long
// wa#02: 忽略无解情况

#include <bits/stdc++.h>
#define inf 0x3f3f3f3f3f3f3f3f
#define int long long
using namespace std;

int x[100001], L, k;

int check(int mid) {
  int sum = 0, solved = 0;
  for (int i = 0; i < L; i++) {
    sum += x[i];
    sum = max(0ll, sum);
    if (sum >= mid)
      sum = 0, solved++;
  }
  return solved;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  freopen("data.in", "r", stdin);
  cin >> L >> k;
  for (int i = 0; i < L; i++)
    cin >> x[i];

  int l = 1, r = inf, ans1 = -1, ans2 = -1;
  while (l <= r) {
    int mid = l + (r - l >> 1);
    int sol = check(mid);
    if (sol <= k) {
      r = mid - 1;
      if (sol == k) ans1 = mid;
    } else l = mid + 1;
  }

  l = 1, r = inf;
  while (l <= r) {
    int mid = l + (r - l >> 1);
    int sol = check(mid);
    if (sol >= k) {
      l = mid + 1;
      if (sol == k) ans2 = mid;
    } else r = mid - 1;
  }
  if (ans1 == -1 || ans2 == -1)
    cout << -1;
  else cout << ans1 << ' ' << ans2;
  return 0;
}