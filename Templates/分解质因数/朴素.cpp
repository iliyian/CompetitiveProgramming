#include <bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define N ((int)3e5)
using namespace std;

struct Node {
  int u, d, id;
  bool operator < (const Node &b) const {
    return d > b.d;
  }
};

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<vector<int>> belong(N + 1);

  priority_queue<Node> q;
  bitset<N + 1> vis;
  vector<int> dis(N + 1, inf);

  int s, t;
  cin >> s >> t;

  if (s == t) {
    cout << 1 << '\n';
    cout << s << '\n';
    return 0;
  }

  if (a[s] == 1 || a[t] == 1) {
    cout << -1 << '\n';
    return 0;
  }

  if (a[s] == a[t]) {
    cout << 2 << '\n';
    cout << s << ' ' << t << '\n';
    return 0;
  }

  for (int i = 1; i <= n; i++) {
    int tmp = a[i];
    for (int j = 2; j * j <= tmp; j++) {
      if (tmp % j == 0) {
        belong[j].push_back(i);
        if (i == s) {
          q.push({j, dis[j] = 1, s});
        }
        while (tmp % j == 0) tmp /= j;
      }
    }
    if (tmp != 1) {
      belong[tmp].push_back(i);
      if (i == s) {
        q.push({tmp, dis[tmp] = 1, s});
      }
    }
  }
  vector<int> prv(n + 1);

  while (!q.empty()) {
    auto [u, d, id] = q.top(); q.pop();
    if (a[t] % u == 0) {
      cout << d + 1 << '\n';
      vector<int> ans;
      cout << s << ' ';
      while (id != s) {
        ans.push_back(id);
        id = prv[id];
      }
      while (!ans.empty()) {
        cout << ans.back() << ' ';
        ans.pop_back();
      }
      cout << t << '\n';
      return 0;
    }
    if (vis[u]) continue;
    vis[u] = true;
    for (int v : belong[u]) {
      int tmp = a[v];
      for (int j = 2; j * j <= tmp; j++) {
        if (tmp % j == 0) {
          if (dis[j] > dis[u] + 1) {
            dis[j] = dis[u] + 1;
            prv[v] = id;
            q.push({j, dis[j], v});
          }
          while (tmp % j == 0) tmp /= j;
        }
      }
      if (tmp != 1) {
        if (dis[tmp] > dis[u] + 1) {
          dis[tmp] = dis[u] + 1;
          prv[v] = id;
          q.push({tmp, dis[tmp], v});
        }
      }
    }
  }
  cout << -1 << '\n';

  return 0;
}