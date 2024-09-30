#include <bits/stdc++.h>
using namespace std;

char a[21];

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  cout << a[n - 1] << '\n';
  // bool aw = false, bw = false;
  // for (int x = 1; x * x <= n; x++) {
  //   int acnt = 0, bcnt = 0, ay = 0, by = 0;
  //   for (int i = 0; i < n; i++) {
  //     bool f = false;
  //     acnt += a[i] == 'A';
  //     bcnt += a[i] == 'B';
  //     if (acnt == x) {
  //       ay++, acnt = bcnt = 0;
  //       f = true;
  //     }
  //     if (bcnt == x) {
  //       by++, bcnt = acnt = 0;
  //       f = true;
  //     }
  //     if (i == n - 1) {
  //       if (!f) continue;
  //       if (ay > by && a[i] == 'A')
  //         aw = true;
  //       if (ay < by && a[i] == 'B')
  //         bw = true;
  //     }
  //   }
  // }
  // if (aw ^ bw) {
  //   if (aw) cout << 'A';
  //   else cout << 'B';
  // } else cout << '?';
  // cout << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("A.in", "r", stdin);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}