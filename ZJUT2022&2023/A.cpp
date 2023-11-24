#include <bits/stdc++.h>
#define N 105
using namespace std;

int a[N][N];

struct Node {
  int idx;
  double avg, cost, real;
  bool operator < (const Node &b) const {
    return real > b.real;
  }
} nodes[N];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("A.in", "r", stdin);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int p;
    cin >> nodes[i].cost >> p;
    int sum = 0;
    for (int j = 0; j < p; j++)
      cin >> a[i][j], sum += a[i][j];
    nodes[i].avg = double(sum) / p;
    nodes[i].idx = i;
    nodes[i].real = nodes[i].avg / nodes[i].cost;
  }
  sort(nodes, nodes + n);
  cout << double(m) / nodes[0].real;
  return 0;
}