// math.h 把 y1 给定义了，就离谱

#include <bits/stdc++.h>
using namespace std;

int x[6], y[6], N, X1, Y1, x2, y2;
double R[6];
bitset<6> vis;

double dist(int x, int y, int xx, int yy) {
  return sqrt((x - xx) * (x - xx) + (y - yy) * (y - yy));
}

double getr(int cur) {
  double r = min(min(abs(X1 - x[cur]), abs(Y1 - y[cur])), min(abs(x2 - x[cur]), abs(y2 - y[cur])));
  for (int i = 0; i < N; i++) {
    if (i != cur && vis[i]) {
      double d2d = dist(x[i], y[i], x[cur], y[cur]);
      r = min(r, d2d - R[i]);
      r = max(r, 0.0);
    }
  }
  return r;
}

const double pi = acos(-1);
double ans = -1;

void dfs(int cur, double sum) {
  ans = max(ans, sum);
  for (int i = 0; i < N; i++) {
    if (!vis[i]) {
      R[i] = getr(i);
      vis[i] = true;
      dfs(i, sum + pi * R[i] * R[i]);
      vis[i] = false;
      R[i] = 0;
    }
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  cin >> N >> X1 >> Y1 >> x2 >> y2;
  for (int i = 0; i < N; i++) {
    cin >> x[i] >> y[i];
  }
  dfs(0, 0);
  cout << fixed << setprecision(0) << abs(X1 - x2) * abs(Y1 - y2) - ans;
  return 0;
}