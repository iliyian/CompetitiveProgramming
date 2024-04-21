#include <bits/stdc++.h>
using namespace std;

int w[401], v[401], f[800001];

int main() {
  freopen("data.in", "r", stdin);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> w[i] >> v[i];
  memset(f, -0x3f, sizeof(f));
  f[400000] = 0;
  for (int i = 0; i < n; i++) {
    if (w[i] > 0)
      for (int j = 800000; j >= w[i]; j--)
        f[j] = max(f[j], f[j - w[i]] + v[i]);
    else
      for (int j = 0; j <= 800000 + w[i]; j++)
        f[j] = max(f[j], f[j - w[i]] + v[i]);
  }
  int ans = 0;
  for (int i = 400000; i <= 800000; i++)
    if (f[i] > 0)
      ans = max(ans, f[i] + i - 400000);
  cout << ans;
  return 0;
}