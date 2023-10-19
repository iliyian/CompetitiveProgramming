#include <bits/stdc++.h>
using namespace std;

int f[51][51], root[51][51], a[51];

int dfs(int i, int j) {
  if (f[i][j] == 0) {
    f[i][j] = f[i][i] + f[j][j], root[i][j] = i;
    for (int k = i + 1; k < j; k++) {
      int t = dfs(i, k - 1) * dfs(k + 1, j) + f[k][k];
      if (t > f[i][j]) {
        root[i][j] = k;
        f[i][j] = t;
      }
    }
  }
  return f[i][j];
}

void print(int l, int r) {
  if (l > r) return;
  cout << root[l][r] << ' ';
  if (l == r) return;
  print(l, root[l][r] - 1);
  print(root[l][r] + 1, r);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int n;
  cin >> n;
  memset(f, 0, sizeof(f));
  for (int i = 1; i <= n; i++)
    cin >> f[i][i], root[i][i] = i;
  cout << dfs(1, n) << '\n';
  print(1, n);
  return 0;
}