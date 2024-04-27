#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Edge {
  int v, w, id;
};

struct Ed {
  int u, v, w;
};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("A.in", "r", stdin);
  freopen("A.out", "W", stdout);

  int n, m;
  cin >> n >> m;
  vector<int> sum(n + 1, 0);
  vector<vector<Edge>> g(n + 1);
  vector<Ed> edges(m + 1);
  vector<int> dir(m + 1, 0), in(n + 1, 0);
  for (int i = 1; i <= m; i++) {
    int x, y, w;
    cin >> x >> y >> w;
    sum[x] += w, sum[y] += w;
    g[x].push_back({y, w, i});
    g[y].push_back({x, w, i});
    edges[i] = {x, y, w};
    in[x]++, in[y]++;
  }

  vector<int> chosen;
  for (int u = 1; u <= n; u++) {
    if (sum[u] % 2) {
      chosen.push_back(u);
    }
  }

  fill(sum.begin(), sum.end(), 0);
  sort(chosen.begin(), chosen.end(), [&](const int &x, const int &y) {
    return in[x] > in[y];
  });
  cout << chosen.size() << '\n';
  for (auto u : chosen) {
    vector<int> one, two;
    int s = 0;
    for (auto [v, w, id] : g[u]) {
      if (dir[id]) {
        s += (dir[id] == 1 && edges[id].u == u
            || dir[id] == 2 && edges[id].v == u ? -1 : 1)
            * w;
      } else {
        if (w == 1) one.push_back(id);
        else two.push_back(id);
      }
    }
    for (auto i : two) {
      if (s < 0) {
        dir[i] = (edges[i].v == u ? 1 : 2);
        s += 2;
      } else {
        dir[i] = (edges[i].u == u ? 1 : 2);
        s -= 2;
      }
    }
    for (auto i : one) {
      if (s < 0) {
        dir[i] = (edges[i].v == u ? 1 : 2);
        s += 1;
      } else {
        dir[i] = (edges[i].u == u ? 1 : 2);
        s -= 1;
      }
    }
    sum[u] = s;
  }

  for (auto u : chosen) {
    if (abs(sum[u]) != 1) {
      cout << u << ' ' << sum[u] << '\n';
    }
  }

  for (int i = 1; i <= m; i++) {
    cout << (dir[i] ? dir[i] : 1);
  }
  cout << '\n';

  return 0;
}