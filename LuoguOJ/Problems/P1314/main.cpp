// 前缀和下标从0开始 ！！！

#include <bits/stdc++.h>
#define N 1000001
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;

int n, m, s;
int w[N], v[N], l[N], r[N];
int sumn[N], sumv[N], ans = inf, d;

int check(int W) {
  memset(sumn, 0, sizeof(sumn));
  memset(sumv, 0, sizeof(sumv));
  for (int i = 1; i <= n; i++) {
    if (w[i] >= W) sumn[i] = sumn[i - 1] + 1, sumv[i] = sumv[i - 1] + v[i];
    else sumn[i] = sumn[i - 1], sumv[i] = sumv[i - 1];
  }
  int y = 0;
  for (int i = 0; i < m; i++)
    y += (sumn[r[i]] - sumn[l[i] - 1]) * (sumv[r[i]] - sumv[l[i] - 1]);
  d = abs(y - s);
  return y > s;
}

signed main() {
  freopen("data.in", "r", stdin);
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> n >> m >> s;
  int L = inf, R = -1;
  for (int i = 1; i <= n; i++)
    cin >> w[i] >> v[i], L = min(L, w[i]), R = max(R, w[i]);
  for (int i = 0; i < m; i++)
    cin >> l[i] >> r[i];
  int ans = inf;
  L--, R++;
  while (L <= R) {
    int mid = L + ((R - L) >> 1);
    if (check(mid)) L = mid + 1;
    else R = mid - 1;
    ans = min(ans, d);
  }
  cout << ans;
  return 0;
}