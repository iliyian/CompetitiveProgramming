#include <bits/stdc++.h>
#define N 100001
#define int long long
using namespace std;

struct Node {
  int a, b;
  bool operator < (const Node &b) const {
    return this->b > b.b;
  }
} nodes[N];

void solve() {
  int n, p;
  cin >> n >> p;

  for (int i = 0; i < n; i++)
    cin >> nodes[i].a;
  for (int i = 0; i < n; i++)
    cin >> nodes[i].b;
  priority_queue<Node> pq;
  for (int i = 0; i < n; i++)
    pq.push(nodes[i]);
  int ans = p, cnt = 1;
  while (!pq.empty()) {
    Node node = pq.top(); pq.pop();
    int b = min(node.b, p);
    int add = min(n - cnt, node.a);
    cnt += add, ans += add * b;
    if (cnt == n) {
      cout << ans << '\n';
      return;
    }
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("B.in", "r", stdin);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}