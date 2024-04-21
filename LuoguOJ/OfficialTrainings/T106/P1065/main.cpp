#include <bits/stdc++.h>
using namespace std;

int machines[22][20000];
int orders[410];

struct Gongjian {
  int id[22], time[22], gxdoneat[22];
} gongjians[22];

int main() {
  freopen("data.in", "r", stdin);
  int m, n;
  cin >> m >> n;
  for (int i = 0; i < 21; i++) memset(machines[i], 0, sizeof(machines[i]));
  for (int i = 0 ; i < m * n; i++) {
    cin >> orders[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> gongjians[i].id[j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> gongjians[i].time[j];
    }
  }
  int ans = -1;
  for (int i = 0; i < m * n; i++) {
    int gj = orders[i], gx = 0;
    while (!gongjians[gj].id[gx]) gx++;
    int mch = gongjians[gj].id[gx]; gongjians[gj].id[gx] = 0;
    int prevtime = 0;
    if (gx) prevtime = gongjians[gj].gxdoneat[gx-1];
    for (int j = prevtime + 1;; j++) {
      if (!machines[mch][j]) {
        bool f = true;
        for (int k = 0; k < gongjians[gj].time[gx]; k++) if (machines[mch][j+k]) {f = false; break;}
        if (!f) continue;
        for (int k = 0; k < gongjians[gj].time[gx]; k++) machines[mch][j + k] = 1;
        int doneat = j + gongjians[gj].time[gx] - 1;
        ans = max(ans, doneat);
        gongjians[gj].gxdoneat[gx] = doneat;
        break;
      }
    }
  }
  cout << ans;
  return 0;
}