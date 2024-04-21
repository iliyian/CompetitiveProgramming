// tmd wa了整整11次

#include <bits/stdc++.h>
#define inf 0x3f3f3f3f3f3f3f3f
#define int long long
using namespace std;

int a, N;

int getlen(int v) {
  int len = 0;
  if (v == 0) return 1;
  while (v) {
    len++;
    v /= 10;
  }
  return len;
}

int vis[10000001];
// bitset<1000001> vis;

int solve(int x, int cnt) {
  if (x == 1) {
    return cnt;
  }
  if (vis[x] <= cnt) return inf;
  vis[x] = cnt;

  int len = getlen(x);
  int p = pow(10, len - 1);
  int v = x % p * 10 + x / p;

  int ans = inf;
  if (x % a == 0)
    ans = min(ans, solve(x / a, cnt + 1));
  if (getlen(v) == len)
    ans = min(ans, solve(v, cnt + 1));
  return ans;
}

signed main() {
  freopen("D.in", "r", stdin);
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> a >> N;
  memset(vis, 0x3f, sizeof(vis));

  int ans = solve(N, 0);
  if (ans == inf) cout << -1;
  else cout << ans;
  return 0;
}