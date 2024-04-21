#include <bits/stdc++.h>
using namespace std;

struct Contest {
  int l, r, id;
} contests[100006];

bool operator < (const Contest &a, const Contest &b) {
  if (a.r == b.r) {
    return a.l < b.l;
  }
  return a.r < b.r;
}

int main() {
  freopen("data.in", "r", stdin);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> contests[i].l >> contests[i].r;
  }
  sort(contests, contests + n);
  int ans = 1;
  int curr = contests->r;
  for (int i = 0; i < n; i++) {
    if (contests[i].l >= curr) {
      ans++;
      curr = contests[i].r;
    }
  }
  cout << ans;
  return 0;
}