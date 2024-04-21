// 顺便，插入排序是 stable_sort

#include <bits/stdc++.h>
using namespace std;

int a[8001], r[8001];

struct Node {
  int v, idx;
  bool operator < (const Node &b) const {
    return v < b.v;
  }
} nodes[8001];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int n, Q;
  cin >> n >> Q;
  for (int i = 1; i <= n; i++) {
    cin >> nodes[i].v;
    nodes[i].idx = i;
    a[i] = nodes[i].v;
  }
  stable_sort(nodes + 1, nodes + 1 + n);
  for (int i = 1; i <= n; i++)
    r[nodes[i].idx] = i;

  for (int i = 0; i < Q; i++) {
    int op, x, v;
    cin >> op >> x;
    if (op == 1) {
      cin >> v;
      if (a[x] == v) continue;
      for (int j = 1; j <= n; j++) {
        if (j == x) continue;

        // 严格条件
        if
      (
          (a[j] < a[x] || a[j] == a[x] && j < x) &&
          (a[j] > v || a[j] == v && j > x)
      ) 
        r[j]++, r[x]--;
        else if
      (
          (a[j] > a[x] || a[j] == a[x] && j > x) &&
          (a[j] < v || a[j] == v && j < x)
      ) 
        r[j]--, r[x]++;
      }
      a[x] = v;
    } else {
      cout << r[x] << '\n';
    }
  }
  return 0;
}