#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;
string s[N];
int mn[N], mx[N], par[N];
int dx[] = {1, -1, 0};
int dy[] = {0, 0, 1};
int fnd(int u) {
  if (par[u] == u)
    return u;
  return par[u] = fnd(par[u]);
}
void unite(int u, int v) {
  int pu = fnd(u), pv = fnd(v);
  if (pu == pv)
    return;
  par[pv] = pu, mx[pu] = max(mx[pu], mx[pv]), mn[pu] = min(mn[pu], mn[pv]);
}

void broadcast(vector<vector<int>> &dist, int x, int y, int n, int val) {
  if (x >= n)
    return;
  if (x < 0)
    return;
  if (dist[x][y] == -1)
    return;
  if (dist[x][y] >= val)
    return;
  dist[x][y] = val;
  broadcast(dist, x - 1, y, n, val);
  broadcast(dist, x + 1, y, n, val);
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int _;
  cin >> _;
  while (_--) {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i)
      cin >> s[i];
    vector<vector<int>> vis(n, vector<int>(m, 0)), vis2(n, vector<int>(m, 0)),
        bad(n, vector<int>(m, 0)), dist(n, vector<int>(m, 0));
    vis[0][0] = 1;
    for (int i = 0; i < n * m; ++i)
      par[i] = i, mx[i] = mn[i] = i % m;
    queue<pair<int, int>> Q;
    Q.push(make_pair(0, 0));
    while (Q.size()) {
      auto [u, v] = Q.front();
      Q.pop();
      for (int i = 0; i < 3; ++i) {
        int nu = u + dx[i], nv = v + dy[i];
        if (nu < 0 || nu >= n || nv < 0 || nv >= m || s[nu][nv] == '1' ||
            vis[nu][nv])
          continue;
        vis[nu][nv] = 1, Q.push(make_pair(nu, nv));
      }
    }
    vis2[0][m - 1] = 1;
    Q.push(make_pair(0, m - 1));
    while (Q.size()) {
      auto [u, v] = Q.front();
      Q.pop();
      for (int i = 0; i < 3; ++i) {
        int nu = u + dx[i], nv = v - dy[i];
        if (nu < 0 || nu >= n || nv < 0 || nv >= m || s[nu][nv] == '1' ||
            vis2[nu][nv])
          continue;
        vis2[nu][nv] = 1, Q.push(make_pair(nu, nv));
      }
    }
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j) {
        if (vis[i][j] && !vis2[i][j]) {
          for (int k = 0; k < 3; ++k) {
            int nu = i + dx[k], nv = j + dy[k];
            if (nu < 0 || nu >= n || nv < 0 || nv >= m || vis2[nu][nv] ||
                !vis[nu][nv])
              continue;
            unite(i * m + j, nu * m + nv);
          }
        }
      }
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j) {
        if (vis[i][j] && !vis2[i][j])
          bad[i][j] = 1;
        else
          bad[i][j] = 0, dist[i][j] = -1;
      }
    int ans = 0;
    for (int j = m - 1; j > 0; --j) {
      for (int i = 0; i < n; ++i) {
        if (bad[i][j - 1] && bad[i][j])
          dist[i][j - 1] = dist[i][j] + 1;
      }
      vector<pair<int, int>> lst;
      for (int i = 0; i < n; ++i) {
        if (bad[i][j - 1]) {
          lst.push_back({dist[i][j - 1], i});
        }
      }
      sort(lst.begin(), lst.end());
      reverse(lst.begin(), lst.end());
      for (auto [u, v] : lst)
        broadcast(dist, v - 1, j - 1, n, u),
            broadcast(dist, v + 1, j - 1, n, u);
    }
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        ans = max(ans, dist[i][j] + 1);
    if (k <= ans)
      cout << "Yes\n";
    else
      cout << "No\n";
  }
}