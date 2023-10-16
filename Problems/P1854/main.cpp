#include <bits/stdc++.h>
using namespace std;

int a[101][101], f[101][101], pre[101][101];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int F, V;
  cin >> F >> V;
  for (int i = 1; i <= F; i++)
    for (int j = 1; j <= V; j++)
      cin >> a[i][j];
  memset(f, 0, sizeof(f));
  for (int i = 1; i <= F; i++)
    for (int j = i; j <= V - F + i + 1; j++) {
      int k = max_element(f[i - 1] + 1, f[i - 1] + j) - f[i - 1] - 1;
      f[i][j] = a[i][j] + f[i - 1][k];
      pre[i][j] = k;
    }
  int k = max_element(f[F] + 1, f[F] + V - F) - f[F] - 1;
  cout << f[F][k] << '\n';
  for (int i = F; i >= 1; i--) {
    cout << a[i][k] << ' ';
    k = pre[i][k];
  }
  return 0;
}