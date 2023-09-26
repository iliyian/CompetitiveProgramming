#include <bits/stdc++.h>
using namespace std;

int len[11];
char a[1000][1000];
bitset<2> del[11];

void dfs(int n, int m) {

}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int n, m;
  cin >> n >> m;
  len[0] = 1;
  len[1] = 2;
  len[2] = 2;
  for (int i = 3; i <= n; i++)
    len[i] = 2 * len[i - 1] + 1;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
  }
  dfs(n, 0);
  for (int i = 0; i < len[n] + 1; i++) {
    for (int j = 0; j < 2 * len[n] + 1; j++)
      cout << char(a[i][j]);
    cout << '\n';
  }
  return 0;
}