#include <bits/stdc++.h>
using namespace std;

struct Pos {
  int x, y;
  bool operator < (const Pos &b) const {
    return x < b.x;
  }
} poss[20005];

int main() {
  freopen("data.in", "r", stdin);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> poss[i].x >> poss[i].y;
  }
  sort(poss, poss + n);
  int prel = poss[0].x, prer = poss[0].y;
  int ans = prer - prel;
  for (int i = 1; i < n; i++) {
    int l = poss[i].x, r = poss[i].y;
    ans += max(0, r - max(l, prer));
    prel = max(l, prel), prer = max(r, prer);
  }
  cout << ans;
  return 0;
}