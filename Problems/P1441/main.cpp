#include <bits/stdc++.h>
using namespace std;

int a[20], n, m, f[2001], sum = 0;
bitset<20> vis;

int ans = -1;

void dp() {
  memset(f, 0, sizeof(f));
  f[0] = true;

  int res = 0;
  for (int i = 0; i < n; i++) {
    if (!vis[i]) continue;
    for (int j = sum; j >= a[i]; j--) {
      if (!f[j] && f[j - a[i]])
        f[j] = true, res++;
    }
  }
  ans = max(ans, res);
}

void dfs(int cur, int cnt) {
  if (cnt == n - m) {
    dp();
    return;
  }
  for (int i = cur; i < n; i++) {
    if (!vis[i]) {
      vis[i] = true;
      sum += a[i];
      dfs(i, cnt + 1);
      sum -= a[i];
      vis[i] = false;
    }
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  dfs(0, 0);
  cout << ans;
  return 0;
}