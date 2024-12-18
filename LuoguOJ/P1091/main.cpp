#include <bits/stdc++.h>
using namespace std;

int a[100], f[100], g[100];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  memset(f, 0, sizeof(f));
  memset(g, 0, sizeof(g));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (a[i] > a[j] && f[j] + 1 > f[i]) {
        f[i] = f[j] + 1;
      }
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    for (int j = n - 1; j > i; j--) {
      if (a[i] > a[j] && g[j] + 1 > g[i]) {
        g[i] = g[j] + 1;
      }
    }
  }
  int ans = -1;
  for (int i = 0; i < n; i++)
    ans = max(ans, f[i] + g[i]);
  cout << n - ans - 1;
  return 0;
}