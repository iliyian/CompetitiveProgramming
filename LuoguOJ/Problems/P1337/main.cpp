// wa#>10, 一直在调参，最后还吸氧...才过......
//         第一道退火模板题

#include <bits/stdc++.h>
#define N 10005
using namespace std;

int x[N], y[N], w[N], n;
double ansx, ansy, ansdis;

mt19937 mtrand(random_device{}());

double rnd() {
  return 1.0 * mtrand() / UINT_MAX;
}

double calc(double xx, double yy) {
  double dis = 0;
  for (int i = 1; i <= n; i++) {
    double dx = xx - x[i], dy = yy - y[i];
    dis += w[i] * sqrt(dx * dx + dy * dy);
  }
  if (dis < ansdis)
    ansdis = dis, ansx = xx, ansy = yy;
  return dis;
}

void SA() {
  double t = 30000;
  double nowx = ansx, nowy = ansy;
  while (t >= 1e-9) {
    double nxtx = nowx + t * (rnd() * 2 - 1),
      nxty = nowy + t * (rnd() * 2 - 1);
    double delta = calc(nxtx, nxty) - calc(nowx, nowy);
    if (delta < 0)
      nowx = nxtx, nowy = nxty;
    else if (exp(-delta / t) > rnd())
      nowx = nxtx, nowy = nxty;
    t *= 0.985;
  }
  // for (int i = 1; i <= 1500; i++) {
  //   double nxtx = ansx + t * (rnd() * 2 - 1),
  //     nxty = ansy + t * (rnd() * 2 - 1);
  //   calc(nxtx, nxty);
  // }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> y[i] >> w[i];
    ansx += x[i], ansy += y[i];
  }
  ansx /= n, ansy /= n;
  ansdis = calc(ansx, ansy);
  
  auto begin = clock();
  SA();
  auto end = clock();
  while ((double)clock() / CLOCKS_PER_SEC < 0.98 - double(end - begin) / CLOCKS_PER_SEC)
    SA();

  cout << fixed << setprecision(3) << ansx << ' ' << ansy;
  return 0;
}