#include <bits/stdc++.h>
using namespace std;

bitset<500> vis[500];
int arr[500][500];

struct Node {
  int x, y, t;
};
queue<Node> q;

struct Person {
  int id, t;
  bool operator < (const Person &b) const {return id < b.id;}
};
vector<Person> v;

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

int main() {
  freopen("data.in", "r", stdin);
  int n, m, a, b, x, y;
  cin >> n >> m >> a >> b;
  for (int i = 0; i < 500; i++) memset(arr[i], 0, sizeof(arr[i]));
  for (int i = 0; i < a; i++) {
    cin >> x >> y;
    x--, y--;
    q.push({x, y, 0});
  }
  for (int i = 0; i < b; i++) {
    cin >> x >> y;
    x--, y--;
    arr[x][y] = i + 1;
  }
  while (!q.empty()) {
    Node node = q.front(); q.pop();
    int x = node.x, y = node.y, t = node.t;
    if (arr[x][y])
      v.push_back({arr[x][y], t}), arr[x][y] = 0;
    if (vis[x][y]) continue;
    vis[x][y] = true;
    for (int i = 0; i < 4; i++) {
      int xx = x + dx[i], yy = y + dy[i];
      if (xx < 0 || xx >= n || yy < 0 || yy >= m || vis[xx][yy]) continue;
      q.push({xx, yy, t + 1});
    }
  }
  sort(v.begin(), v.end());
  for (auto p : v) {
    cout << p.t << '\n';
  }
  return 0;
}