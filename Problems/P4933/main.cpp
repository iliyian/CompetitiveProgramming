#include <bits/stdc++.h>
#define mod 998244353
using namespace std;

int a[1001];
map<int, map<int, int>> f;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int n, ans = 0;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int r = 1; r < n; r++) {
    for (int l = r - 1; l >= 0; l--) {
      int d = a[r] - a[l];
      f[r][d] += f[l][d] + 1;
      f[r][d] %= mod;
      ans += f[l][d] + 1;
      ans %= mod;
    }
  }
  cout << ans + n;
  return 0;
}