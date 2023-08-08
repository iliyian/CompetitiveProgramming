#include <bits/stdc++.h>
using namespace std;

struct Station {
  double d, p;
};
Station a[10];

double D1, C, D2, P;
int N;

double solve(int cur, double rest) {
  if (cur == N) {
    if (rest >= (D1 - a[cur].d) / D2) {
      return 0;
    } else 
      return ((D1 - a[cur].d) / D2 - rest) * a[cur].p;
  }
  int nxt = cur + 1;
  for (int i = cur + 1; i <= N; i++) {
    if (a[i].p < a[nxt].p) {
      nxt = i;
    }
  }
  cout << nxt << endl;
  double need = (a[nxt].d - a[cur].d) / D2;
  if (need >= rest && a[nxt].p > a[cur].p) {
    return solve(nxt, rest - need);
  } else {
    return need * a[cur].p + solve(nxt, C - need);
  }
}

int main() {
  freopen("data.in", "r", stdin);
  cin >> D1 >> C >> D2 >> P >> N;
  a[0] = {0, P};
  for (int i = 1; i <= N; i++) {
    cin >> a[i].d >> a[i].p;
  }
  if ((D1 - a[N].d) / D2 > C) {
    cout << "No Solution";
    return 0;
  }
  a[N + 1] = {D1, 0};

  cout << fixed << setprecision(2) << solve(0, 0);
  return 0;
}