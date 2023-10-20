#include <bits/stdc++.h>
#define int long long
using namespace std;

int a[300001], b[300001];

void solve() {
  int n;
  cin >> n;
  int mina = 0x3f3f3f3f, minb = 0x3f3f3f3f, suma = 0, sumb = 0;
  for (int i = 0; i < n; i++)
    cin >> a[i], mina = min(mina, a[i]), suma += a[i];
  for (int i = 0; i < n; i++)
    cin >> b[i], minb = min(minb, b[i]), sumb += b[i];
  cout << min(suma + minb * n, sumb + mina * n) << '\n';
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}