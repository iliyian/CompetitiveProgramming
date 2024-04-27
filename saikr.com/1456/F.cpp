#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("F.in", "r", stdin);
  freopen("F.out", "w", stdout);

  int n, an, bn;
  cin >> n >> an >> bn;
  vector<int> a(an), b(bn);

  vector<vector<int>> res = {
    {0, 0, 1, 1, 0},
    {0, 0, 0, 1, 0},
    {0, 0, 0, 0, 1},
    {0, 0, 0, 0, 1},
    {0, 0, 0, 0, 0},
  };

  for (int i = 0; i < an; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < bn; i++) {
    cin >> b[i];
  }

  int aans = 0, bans = 0;
  for (int i = 0; i < n; i++) {
    int ax = a[i % an], bx = b[i % bn];
    int f = 1;
    if (ax == bx) continue;

    if (ax > bx) f = -1, swap(ax, bx);
    if (res[ax][bx] && f == 1 || !res[ax][bx] && f == -1) {
      aans++;
    } else {
      bans++;
    }
  }
  cout << aans << ' ' << bans << '\n';


  return 0;
}