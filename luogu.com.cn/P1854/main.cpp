#include <bits/stdc++.h>
using namespace std;

int a[101][101], f[101][101], pre[101][101];

void print(int k, int i) {
  if (i > 1) print(pre[i][k], i - 1);
  cout << k << ' ';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int F, V;
  cin >> F >> V;
  for (int i = 1; i <= F; i++)
    for (int j = 1; j <= V; j++)
      cin >> a[i][j];

  // something MUST todo
  for (int i = 1; i <= V - F + 1; i++)
    f[1][i] = a[1][i];
  for (int i = 2; i <= F; i++)
    for (int j = i; j <= V - F + i; j++) {
      for (int k = 1; k < j; k++) {
        if (f[i - 1][k] + a[i][j] > f[i][j]) {
          f[i][j] = f[i - 1][k] + a[i][j];
          pre[i][j] = k;
        }
      }
    }
  int k = -1, maxn = -1;
  for (int i = F; i <= V; i++)
    if (f[F][i] > maxn) {
      k = i, maxn = f[F][i];
    }
  cout << maxn << '\n';
  print(k, F);
  return 0;
}