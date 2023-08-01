#include <bits/stdc++.h>
using namespace std;

queue<int> q;
vector<int> L;
vector<vector<int>> e;
int in[28], n, m, dis[28];

bool check() {
  while (!q.empty()) q.pop();
  L.clear();

  memset(in, 0, sizeof(in));
  for (auto u : e)
    for (auto v : u)
      ++in[v];

  for (int i = 1; i <= n; i++) {
    if (!in[i]) q.push(i);
    dis[i] = -0x7fffffff;
  }
  q.push(0);
  dis[0] = 0;

  while (!q.empty()) {
    int u = q.front(); q.pop();
    L.push_back(u);
    for (auto v : e[u]) {
      if (--in[v] == 0)
        q.push(v);
    }
  }

  for (int i = 1; i <= n; i++) if (in[i]) return false;
  for (auto u : L) {
    for (auto v : e[u]) {
      dis[v] = max(dis[v], dis[u] + 1);
     }
  }

  return true;
}

int main() {
  freopen("data.in", "r", stdin);
  cin >> n >> m;
  e.resize(n + 2);

  for (int i = 1; i <= n; i++) {
    e[0].push_back(i);
    e[i].push_back(n + 1);
  }
  
  for (int i = 0; i < m; i++) {
    char a, op, b;
    cin >> a >> op >> b;
    a = a - 'A' + 1, b = b - 'A' + 1;
    e[a].push_back(b);
    if (!check()) {
      cout << "Inconsistency found after " << i + 1 << " relations.";
      return 0;
    }
    if (dis[n + 1] == n + 1) {
      cout << "Sorted sequence determined after " << i + 1 << " relations: ";
      for (int i = 1; i < L.size() - 1; i++) {
        cout << char(L[i] + 'A' - 1);
      }
      cout << '.';
      return 0;
    }
  }

  cout << "Sorted sequence cannot be determined.";
  return 0;
}