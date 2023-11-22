// date: 2023/11/21
// tag: 稍微复杂的种类并查集模板，三个种类罢了，关键在于美妙的传递性
// 一遍AC

#include <bits/stdc++.h>
#define N 500001
using namespace std;

int pa[N * 3];

int find(int x) { return x == pa[x] ? x : pa[x] = find(pa[x]); }
void merge(int x, int y) { pa[find(x)] = find(y); }

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int n, k;
  cin >> n >> k;
  iota(pa + 1, pa + 1 + n * 3, 1);
  int ans = 0;
  for (int q = 0; q < k; q++) {
    int op, x, y;
    cin >> op >> x >> y;
    if (x > n || y > n) {
      ans++;
      continue;
    }
    if (op == 1) {
      if (find(x + n) == find(y) || find(x) == find(y + n)) ans++;
      else
        for (int i = 0; i < 3; i++)
          merge(x + i * n, y + i * n);
    } else {
      if (find(x) == find(y) || find(x) == find(y + n)) ans++;
      else
        for (int i = 0; i < 3; i++)
          merge(x + (i + 1) % 3 * n, y + i * n);
    }
  }
  cout << ans;
  return 0;
}