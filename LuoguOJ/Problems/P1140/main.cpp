#include <bits/stdc++.h>
using namespace std;

int a[101], b[101], f[101][101];

int d[5][5] = {
  {0, -3, -4, -2, -1},
  {-3, 5, -1, -2, -1},
  {-4, -1, 5, -3, -2},
  {-2, -2, -3, 5, -2},
  {-1, -1, -2, -2, 5}
};

int change(int x) {
  switch (char(x)) {
    case 'A': return 1;
    case 'C': return 2;
    case 'G': return 3;
    case 'T': return 4;
  }
  return 0;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  freopen("data.in", "r", stdin);
  int alen, blen;
  string stra, strb;
  cin >> alen >> stra >> blen >> strb;
  stra = '#' + stra, strb = '#' + strb;
  
  for (int i = 1; i <= alen; i++)
    a[i] = change(stra[i]);
  for (int i = 1; i <= blen; i++)
    b[i] = change(strb[i]);

  memset(f, -0x3f, sizeof(f));
  f[0][0] = 0;
  for (int i = 1; i <= alen; i++)
    f[i][0] = f[i - 1][0] + d[a[i]][0];
  for (int i = 1; i <= blen; i++)
    f[0][i] = f[0][i - 1] + d[0][b[i]];

  for (int i = 1; i <= alen; i++) {
    for (int j = 1; j <= blen; j++) {
      f[i][j] = max(f[i][j], max(f[i - 1][j - 1] + d[a[i]][b[j]], 
        max(f[i - 1][j] + d[a[i]][0], f[i][j - 1] + d[0][b[j]])));
    }
  }
  cout << f[alen][blen];
  return 0;
}