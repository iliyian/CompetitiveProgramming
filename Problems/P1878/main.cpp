// copy

#include <bits/stdc++.h>
using namespace std;

char c[200001];
int a[200001], L[200001], R[200001];
bitset<200001> vis;

struct Node {
  int d, l, r;
  bool operator < (const Node &b) const {
    if (d == b.d) return l > b.l;
    return d > b.d;
  }
};
priority_queue<Node> q;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  string str;
  cin >> str;
  str = '#' + str;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int i = 1; i <= n; i++)
    L[i] = i - 1, R[i] = i + 1;
  L[1] = -1, R[n] = -1;
  for (int i = 2; i <= n; i++) {
    if (str[i] != str[i - 1])
      q.push({abs(a[i] - a[i - 1]), i - 1, i});
  }
  vector<pair<int, int>> ans;
  while (!q.empty()) {
    Node node = q.top(); q.pop();
    int d = node.d, l = node.l, r = node.r;
    if (vis[l] || vis[r]) continue;
    vis[l] = vis[r] = true;
    ans.push_back({node.l, node.r});
    if (L[l] != -1) R[L[l]] = R[r];
    if (R[r] != -1) L[R[r]] = L[l];
    if (L[l] != -1 && R[r] != -1 && str[L[l]] != str[R[r]]) {
      q.push({abs(a[L[l]] - a[R[r]]), L[l], R[r]});
    }
  }
  cout << ans.size() << '\n';
  for (auto &i : ans) {
    cout << i.first << ' ' << i.second << '\n';
  };
  return 0;
}