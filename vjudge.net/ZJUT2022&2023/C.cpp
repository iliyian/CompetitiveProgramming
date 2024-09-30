#include <bits/stdc++.h>
#define N 100005
using namespace std;

int x[N];

struct Node {
  int a, b, c, d, h;
} nodes[N];

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    cin >> x[i];
  }
  for (int i = 1; i <= k; i++) {
    int a, b, c, d, h;
    cin >> a >> b >> c >> d >> h;
    nodes[i] = {a, b, c, d, h};
  }
  nodes[0] = {1, 1, }
  queue<Node> q;

  q.push({})
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("C.in", "r", stdin);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}