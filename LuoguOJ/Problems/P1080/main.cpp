#include <bits/stdc++.h>
#define Big vector<int>
#define MAXN 10000
#define LEN 4
using namespace std;

struct Node {
  int l, r;
  bool operator < (const Node &b) const {
    return l * r < b.l * b.r;
  }
} nodes[1001];

void operator *= (Big &a, const int &b) {
  for (int i = 0; i < a.size(); i++) {
    a[i] *= b;
  }
  for (int i = 0; i < a.size() - 1; i++) {
    a[i + 1] += a[i] / MAXN;
    a[i] %= MAXN;
  }
  while (!a.empty() && a.back() >= MAXN) {
    a.push_back(a.back() / MAXN);
    a[a.size() - 2] %= MAXN;
  }
}

bool operator < (const Big &a, const Big &b) {
  if (a.size() != b.size()) return a.size() < b.size();
  for (int i = a.size() - 1; i >= 0; i--)
    if (a[i] != b[i])
      return a[i] < b[i];
  return false;
}

Big operator / (const Big &a, const int &b) {
  Big res(a.size());
  int down = 0;
  for (int i = a.size() - 1; i >= 0; i--) {
    int cur = a[i] + down * MAXN;
    res[i] = cur / b;
    down = cur - res[i] * b;
  }
  while (res.size() >= 2 && !res.back()) res.pop_back();
  return res;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int n;
  cin >> n >> nodes[0].l >> nodes[0].r;
  for (int i = 1; i <= n; i++) {
    cin >> nodes[i].l >> nodes[i].r;
  }
  sort(nodes + 1, nodes + 1 + n);
  Big ans(1, 0), prev(1, nodes[0].l);
  for (int i = 1; i <= n; i++) {
    Big cur = prev / nodes[i].r;
    ans = ans < cur ? cur : ans;
    prev *= nodes[i].l;
  }
  cout << ans.back();
  for (int i = ans.size() - 2; i >= 0; i--) {
    cout << setw(LEN) << setfill('0') << ans[i];
  }
  return 0;
}