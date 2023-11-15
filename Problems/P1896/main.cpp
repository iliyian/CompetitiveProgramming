// birthday: 20231114
// tag: 状态压缩dp
// difficulty: 状态转移，状态映射

#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, k, stat[500], cnt = 0, popcount[500], f[500][500][500];

void dfs(int s, int cur, int sum) {
  if (cur >= n) {
    // critical, hit.
    stat[++cnt] = s;
    popcount[cnt] = sum;
    return;
  }
  dfs(s, cur + 1, sum);
  dfs(s + (1 << cur), cur + 2, sum + 1);
}

bool check(int x, int y) {
  if (stat[x] & stat[y]) return false;
  if ((stat[x] << 1) & stat[y]) return false;
  if (stat[x] & (stat[y] << 1)) return false;
  return true;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> n >> k;
  dfs(0, 0, 0);
  for (int i = 1; i <= cnt; i++)
    f[1][i][popcount[i]] = 1;
  for (int r = 2; r <= n; r++) {
    for (int i = 1; i <= cnt; i++) {
      for (int j = 1; j <= cnt; j++) {
        if (!check(i, j)) continue;
        for (int c = popcount[i]; c <= k; c++)
          f[r][i][c] += f[r - 1][j][c - popcount[i]];
      } 
    }
  }
  long long ans = 0;
  for (int i = 1; i <= cnt; i++)
    ans += f[n][i][k];
  cout << ans;
  return 0;
}