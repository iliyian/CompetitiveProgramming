#include <bits/stdc++.h>
using namespace std;

int w[10000], v[10000], k[10000], f[1001];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int sh, sm, dh, dm, n;
  char t1, t2;
  cin >> sh >> t1 >> sm >> dh >> t2 >> dm >> n;
  // scanf("%d:%d %d:%d %d", &sh, &sm, &dh, &dm, &n);
  if (sm > dm) sm -= 60, sh++;
  int T = (dh - sh) * 60 + dm - sm;
  for (int i = 0; i < n; i++) {
    cin >> w[i] >> v[i] >> k[i];
  }
  f[0] = 0;
  for (int i = 0; i < n; i++) {
    if (k[i] == 0)
      for (int j = w[i]; j <= T; j++)
        f[j] = max(f[j], f[j - w[i]] + v[i]);
    else {
      int idx = 0, ww[12], vv[12], c = 1;
      while (k[i] > c) {
        k[i] -= c;
        ww[idx] = w[i] * c;
        vv[idx++] = v[i] * c;
        c *= 2;
      }
      ww[idx] = w[i] * k[i];
      vv[idx++] = v[i] * k[i];
      for (int t = 0; t < idx; t++)
        for (int j = T; j >= ww[t]; j--)
          f[j] = max(f[j], f[j - ww[t]] + vv[t]);
    }
  }
  cout << f[T];
  return 0;
}