#include <bits/stdc++.h>
#include <ranges>
#define int long long
using namespace std;

struct Node {
  int l, r, w;
  bool operator < (const Node &b) const {
    return l < b.l;
  }
};

void solve() {
  int n;
  cin >> n;
  vector<int> a(n * 2 + 2);
  a[0] = 0x3f3f3f3f;
  vector<Node> nodes;
  int prv = 1;
  for (int i = 1; i <= n * 2; i++) {
    cin >> a[i];
    if (a[i] > a[prv]) {
      nodes.push_back({prv, i - 1, i - prv});
      prv = i;
    }
  }
  nodes.push_back({prv, n * 2, n * 2 - prv + 1});
  // sort(nodes.begin(), nodes.end());
  vector<bool> vis(nodes.size());
  for (int i = 0; i < nodes.size(); i++) {
    int sum = nodes[i].w;
    vector<int> ans = {i};
    for (int j = i + 1; j < nodes.size(); j++) {
      if (sum + nodes[j].w > n) {
        break;
      } else {
        sum += nodes[j].w;
        ans.push_back(j);
        if (sum == n) {
          for (auto u : ans) {
            for (int j = nodes[u].l; j <= nodes[u].r; j++) {
              cout << a[j] << ' ';
            }
            vis[u] = true;
          }
          cout << '\n';
          for (int i = 0; i < nodes.size(); i++) {
            if (!vis[i]) {
              for (int j = nodes[i].l; j <= nodes[i].r; j++) {
                cout << a[j] << ' ';
              }
            }
          }
          return;
        }
      }
    }
  }
  cout << -1 << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}