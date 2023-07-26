#include <bits/stdc++.h>
using namespace std;

struct Gold {
  int w, v;
  double t;
}golds[101];

bool cmp(const Gold &a, const Gold &b) {
  return a.t > b.t;
}

int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> golds[i].w >> golds[i].v;
    golds[i].t = golds[i].v / 1.0 / golds[i].w;
  }
  double ans = 0;
  int cur = 0;  
  sort(golds, golds + n, cmp);
  for (int i = 0; i < n; i++) {
    if (cur + golds[i].w <= k) {
      cur += golds[i].w;
      ans += golds[i].v;
    } else {
      ans += (k - cur) * golds[i].t;
      break;
    }
  }
  cout << fixed << setprecision(2) << ans;
  return 0;
}