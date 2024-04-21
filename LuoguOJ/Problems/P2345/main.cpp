#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Node {
  int x, v;
} nodes[20001];

bool cmp1(const Node &a, const Node &b) {
  return a.v < b.v;
}

bool cmp2(const Node &a, const Node &b) {
  return a.x < b.x;
}

int ans = 0;

void cdq(int l, int r) {
  if (l == r) return;
  int mid = l + (r - l >> 1);
  cdq(l, mid);
  cdq(mid + 1, r);
  sort(nodes + l, nodes + mid + 1, cmp2);
  sort(nodes + mid + 1, nodes + r + 1, cmp2);
  int j = l, more = 0, les = 0;
  for (int i = l; i <= mid; i++)
    more += nodes[i].x;
  for (int i = mid + 1; i <= r; i++) {
    while (j <= mid && nodes[j].x < nodes[i].x)
      more -= nodes[j].x, les += nodes[j].x, j++;
    int lesc = j - l, morec = mid - j + 1;
    ans += nodes[i].v * (more - les + (lesc - morec) * nodes[i].x);
  }
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> nodes[i].v >> nodes[i].x;
  }
  sort(nodes + 1, nodes + n + 1, cmp1);
  cdq(1, n);
  cout << ans;
  return 0;
}