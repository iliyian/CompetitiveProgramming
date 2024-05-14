// date: 2024-05-13 21:19:34
// tag: 数学，构造

#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("H.in", "r", stdin);
  freopen("H.out", "w", stdout);

  int n;
  cin >> n;
  vector<int> a(n + 1), ans(n + 1);
  int cnt0 = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    cnt0 += !(a[i] % 3);
  }
  if (cnt0 <= n / 2) {
    int cnt = n / 2 - cnt0;
    for (int i = 1; i <= n; i++) {
      if (a[i] % 3 == 0 || cnt) {
        ans[i] = 1;
        if (a[i] % 3) {
          cnt--;
        }
      } else {
        ans[i] = 0;
      }
    }
    cout << 0 << '\n';
  } else {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i] % 3 == 0 && cnt < n / 2) {
        ans[i] = 1;
        cnt++;
      } else {
        ans[i] = 0;
      }
    }
    cout << 2 << '\n';
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[i];
  }


  return 0;
}