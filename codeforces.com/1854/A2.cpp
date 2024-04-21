#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  int cnt2 = 0, cnt1 = 0, A = 0, B = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    cnt1 += a[i] > 0, cnt2 += a[i] < 0;
    if (a[i] > 0 && a[A] < a[i]) A = i;
    if (a[i] < 0 && a[B] < -a[i]) B = i;
  }
  if (cnt1 >= cnt2) {
    if (a[A] > -a[B]) {

    } else {
      
    }
  } else {

  }
  vector<array<int, 2>> ans;

}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("A2.in", "r", stdin);
  freopen("A2.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}