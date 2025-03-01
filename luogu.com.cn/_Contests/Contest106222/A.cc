#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int v, w;
};

struct Node {
  int dis, u;
  bool operator > (const Node &b) const {return dis > b.dis;}
};
 
int in[100005], dis[100005], inf = 1 << 30, vis[100005];
vector<vector<Edge>> adj;
priority_queue<Node, vector<Node>, greater<Node>> que;
map<int, map<int, bool>> g;

int gcd(int a, int b) {
  return b ? gcd(b, a % b) : a;
}

// int lcm(int a, int b) {
//   return a * b / gcd(a, b);
// }

bool check(int a, int b) {
  if (b % a) return false;
  return gcd(a, b) == a; 
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  freopen("A.in", "r", stdin);
  int T;
  cin >> T;
  while (T--) {
    adj.clear();
    int n, q;
    cin >> n >> q;

    adj.resize(n + 1);

    for (int i = 1; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
        if (!check(i, j)) continue;
        int w = abs(i - j);
        adj[i].push_back({j, w});
        adj[j].push_back({i, w});
      }
    }

    for (int i = 0; i < q; i++) {
      memset(vis, 0, sizeof(vis));
      for (int i = 0; i <= n; i++) dis[i] = inf;
      int x, y;
      cin >> x >> y;
      while (!que.empty()) que.pop();
      que.push({0, x});
      dis[x] = 0;
      while (!que.empty()) {
        int u = que.top().u; que.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (auto ed : adj[u]) {
          int v = ed.v, w = ed.w;
          if (dis[v] > dis[u] + w) {
            dis[v] = dis[u] + w;
            que.push({dis[v], v});
          }
        }
      }
      cout << dis[y] << '\n';
    }
  }
  return 0;
}