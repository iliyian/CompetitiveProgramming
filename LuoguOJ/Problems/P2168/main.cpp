// date: 2023/11/15
// tag: k huffman template
// wa#01: not using long long

#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Node {
  int w, h;
  bool operator < (const Node &b) const {
    if (w == b.w) return h > b.h;
    return w > b.w;
  }
};

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int n, k;
  cin >> n >> k;
  priority_queue<Node> q;
  for (int i = 0; i < n; i++) {
    int w;
    cin >> w;
    q.push({w, 1});
  }
  // always divisible
  // each subs k into 1, total subs n to 1
  while ((q.size() - 1) % (k - 1)) q.push({0, 1});
  int ans = 0;
  while (q.size() > 1) {
    int w = 0, h = 0;
    for (int i = 0; i < k; i++) {
      Node node = q.top(); q.pop();
      w += node.w, h = max(h, node.h);
    }
    ans += w;
    q.push({w, h + 1});
  }
  // length eqs height sub 1
  cout << ans << '\n' << q.top().h - 1;
  return 0;
}