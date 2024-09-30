#include <bits/stdc++.h>
#define int long long
#define N 100005
using namespace std;

int a[N], dep[N], in[N], top[N], nxt[N];
int n, m;

void dfs(int u) {
  if (dep[u]) return;
  if (nxt[u] > n) {
    dep[u] = 1;
    top[u] = u;
    return;
  }
  dfs(nxt[u]);
  dep[u] = dep[nxt[u]] + 1;
  top[u] = top[nxt[u]];
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    nxt[i] = i + a[i];
    if (nxt[i] <= n) {
      in[nxt[i]] = true;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (!in[i]) {
      dfs(i);
    }
  }
  for (int i = 0; i < m; i++) {
    int op, x, y;
    cin >> op;
    if (!op) {
      cin >> x >> y;
      dep[x] = 0;
      nxt[x] = x + y;
      dfs(x);
    } else {
      cin >> x;
      cout << top[x] << ' ' << dep[x] << '\n';
    }
  }

  return 0;
}