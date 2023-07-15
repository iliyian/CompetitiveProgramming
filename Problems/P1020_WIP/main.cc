#include <bits/stdc++.h>

struct MissileGroup {
  int front = 0, back = 0, count = 0;
}groups[100000];

bool push(MissileGroup &g, int h) {
  if (!g.front) {
    g.front = h;
    g.count++;
  } else if (!g.back || h <= g.back) {
    g.back = h;
    g.count++;
  } else if (h > g.back) {
    return false; 
  }
  return true;
}

int m[100000], n = 0;
bool vis[100000];

int attack(int prev, int idx) {
  int acc = 0;
  for (int i = idx; i < n; i++) {
    if (m[i] <= prev) {
      vis[i] = true;
      acc = std::max(acc, attack(m[i], i+1) + 1);
      vis[i] = false;
    }
  }

}

int main() {
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);

  int h, idx = 0;
  memset(m, 0, sizeof(m));
  memset(vis, 0, sizeof(vis));

  for (int i = 0; i < n; i++) {
    if (!vis[i])
  }

  // for (int i = 0; i <= idx; i++) {
  //   printf("g[%d] : front=%d, back=%d, count=%d\n", i, groups[i].front, groups[i].back, groups[i].count);
  // }

  return 0;
}
