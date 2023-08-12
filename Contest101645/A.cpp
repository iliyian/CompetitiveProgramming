#include <bits/stdc++.h>
using namespace std;

int x[1000001], a[1000001], ans = -1;
long long n, t, f;
bitset<1000001> vis;

void dfs(long long pos, long long after, int cnt) {
  if (after + abs(f - pos) > t) return;
  ans = max(ans, cnt);
  for (int i = 0; i < n; i++) {
    int at = after + abs(pos - x[i]);
    if (!vis[i] && at >= a[i]) {
      vis[i] = true;
      dfs(x[i], at, cnt + 1);
      vis[i] = false;
    }
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  cin >> n >> t >> f;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> a[i];
  }
  for (int i = 0; i < n; i++) {
    vis[i] = true;
    dfs(0, x[i], 0);
    vis[i] = false;
  }
  cout << ans;
  return 0;
}