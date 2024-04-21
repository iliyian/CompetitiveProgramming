// 连通块是个好概念

#include <bits/stdc++.h>
using namespace std;

struct Road {
  int x, y, t;
};

array<int, 100010> fa{};
vector<Road> roads;

bool operator < (const Road &a, const Road &b) {return a.t < b.t;};

int find(int x) {return fa[x] == x ? x : fa[x] = find(fa[x]);}

int main() {
  int N, M;
  cin >> N >> M;
  int cnt = N;
  roads.reserve(M);
  for (int i = 0; i < M; i++) {
    int a, b, t;
    cin >> a >> b >> t;
    fa[a] = a, fa[b] = b;
    roads.push_back(Road{a, b, t});
  }
  sort(roads.begin(), roads.end());
  for (auto r : roads) {
    int fx = find(r.x), fy = find(r.y);
    if (fx != fy) fa[fx] = fy, cnt--;
    if (cnt == 1) {
      cout << r.t;
      return 0;
    }
  }
  cout << -1;
  return 0;
}