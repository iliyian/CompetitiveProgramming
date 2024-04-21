// vis 绝对前置，一些时候性能提升巨大，比如现在

#include <bits/stdc++.h>
using namespace std;

struct Step {
  int P, Q;
};

struct Node {
  int x, y;
};

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

int gcd(int x, int y) {
  return y == 0 ? x : gcd(y, x % y);
}

void solve() {
  int N;
  cin >> N;
  vector<Step> v;
  for (int i = 0; i < N; i++) {
    int P, Q;
    cin >> P >> Q;
    v.push_back({P, Q});
  }
  int gcdx = v.front().P, gcdy = v.front().Q;
  for (int i = 1; i < N; i++) {
    gcdx = gcd(gcdx, v[i].P), gcdy = gcd(gcdy, v[i].Q);
  }
  if (abs(gcdx) > 1 || abs(gcdy) > 1) {
    cout << "NIE\n";
    return;
  }
  queue<Node> q;
  q.push({100, 100});
  bitset<200> vis[200];
  vis[100][100] = true;
  while (!q.empty()) {
    Node node = q.front(); q.pop();
    int x = node.x, y = node.y;
    if (vis[99][100] && vis[101][100] && vis[100][99] && vis[100][101]) {
      cout << "TAK\n";
      return;
    }
    for (int i = 0; i < N; i++) {
      int xx = x + v[i].P, yy = y + v[i].Q;
      if (xx < 0 || xx >= 200 || yy < 0 || yy >= 200) continue;
      if (vis[xx][yy]) continue;
      vis[xx][yy] = true;
      q.push({xx, yy});
    }
  }
  cout << "NIE\n";
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int K;
  cin >> K;
  while (K--) solve();
  return 0;
}