#include <bits/stdc++.h>
#define N 100001
using namespace std;

int a[N], f[31];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  int ans = 0;
  memset(f, 0, sizeof(f));
  for (int i = 0; i < n; i++) {
    int t = 0;
    for (int j = 0; j < 31; j++)
      if (1 << j & a[i])
        t = max(t, f[j] + 1);
    for (int j = 0; j < 31; j++)
      if (1 << j & a[i])
        f[j] = max(f[j], t);
    ans = max(ans, t);
  }
  cout << ans;
  return 0;
}