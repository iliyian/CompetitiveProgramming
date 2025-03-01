// 把所有int改成LL即可，内存消耗应该不大

#include <bits/stdc++.h>
#define LL long long
using namespace std;

struct Hole {
  LL x, y, z, i;
};

array<LL, 1010> fa{}, cei{}, flo{};
array<Hole, 1010> holes{};

LL find(LL x) {return fa[x] == x ? x : fa[x] = find(fa[x]);}

LL dist(LL x1, LL x2, LL y1, LL y2, LL z1, LL z2) {
  return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) + (z1-z2)*(z1-z2);
}

void solve() {
  holes.fill(Hole{});
  fa.fill(0), cei.fill(0), flo.fill(0);
  LL n, h, r, ccnt = 0, fcnt = 0;
  cin >> n >> h >> r;
  for (LL i = 0; i < n; i++) {
    LL x, y, z;
    cin >> x >> y >> z;
    fa[i] = i;
    holes[i] = Hole{x, y, z, i};
    if (z + r >= h) cei[ccnt++] = i;
    if (z - r <= 0) flo[fcnt++] = i;
    for (LL j = 0; j < i; j++) {
      Hole &h1 = holes[i], &h2 = holes[j];
      if ((h1.x - h2.x) * (h1.x - h2.x) + (h1.y - h2.y) * (h1.y - h2.y) > (LL)(4 * r * r)) continue;
      if (dist(h1.x, h2.x, h1.y, h2.y, h1.z, h2.z) <= (LL)(4 * r * r)) {
        LL fi = find(i), fj = find(j);
        if (fi != fj) fa[fi] = fj; // 不然会死循环然后seg fault
      }
    }
  }
  for (LL i = 0; i < ccnt; i++) {
    for (LL j = 0 ; j < fcnt; j++) {
      if (find(cei[i]) == find(flo[j])) {
        cout << "Yes" << endl;
        return;
      }
    }
  }
  cout << "No" << endl;
}

int main() {
  freopen("data.in", "r", stdin);
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}