#include <bits/stdc++.h>
using namespace std;

int f[100001], a[100001];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int n;
  cin >> n;
  memset(f, 0, sizeof(f));
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    for (int j = 1; j * j <= a[i]; j++) {
      if (a[i] % j == 0) {
        f[j]++;
        f[a[i] / j]++;
        if (a[i] / j == j)
          f[j]--;
      }
    }
  }
  int ans = 1;
  for (int i = 2; i <= 1e5; i++)
    ans = max(ans, f[i]);
  cout << ans;
  return 0;
}