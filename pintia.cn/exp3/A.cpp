#include <bits/stdc++.h>
#define int long long
#define N 100001
using namespace std;

int a[N];

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("A.in", "r", stdin);

  // int t = 0;
  // while (cin >> a[t]) t++;
  // sort(a, a + t);
  // int len = unique(a, a + t) - a;
  // if (len < 3) {
  //   cout << a[len - 1];
  //   return 0;
  // }
  // int k = a[len - 3];
  // sort(a, a + t);
  // if (count(a, a + t, k) > 1) {
  //   cout << a[t - 1];
  // } else {
  //   cout << k;
  // }

  int x, t = 1, cnt = 0;
  cin >> x;
  int ans3 = -0x3f3f3f3f3f3f3f3f, ans2 = -0x3f3f3f3f3f3f3f3f, ans1 = x;
  while (cin >> x) {
    t++;
    if (x == ans3) {
      cnt++;
      continue;
    }
    if (x == ans1 || x == ans2) continue;
    if (x > ans1) {
      ans3 = ans2;
      ans2 = ans1;
      ans1 = x;
      cnt = 0;
    } else if (x > ans2) {
      ans3 = ans2;
      ans2 = x;
      cnt = 0;
    } else if (x > ans3) {
      ans3 = x;
      cnt = 0;
    }
  }
  if (t < 3) cout << ans1;
  else cout << ans3;
  return 0;
}