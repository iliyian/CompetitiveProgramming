#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Oil {
  double a, p;
  bool operator < (const Oil &b) const {
    return p > b.p;
  }
};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  double D1, C, D2, P;
  int N;
  cin >> D1 >> C >> D2 >> P >> N;
  vector<double> d(N + 2), p(N + 2);
  for (int i = 1; i <= N; i++) {
    cin >> d[i] >> p[i];
  }
  deque<Oil> q;
  double ans = C * P;
  q.push_back({C, P});
  double sum = C;
  for (int i = 1; i <= N + 1; i++) {
    double dis = d[i] - d[i - 1];
    double need = dis / D2;
    while (!q.empty()) {
      auto [a, pr] = q.front(); q.pop_front();
      if (a >= need) {
        a -= need;
        sum -= need;
        need = 0;
      } else {
        need -= a;
        sum -= a;
      }
      if (!need) {
        q.push_front({a, pr});
        break;
      }
    }
    if (need) {
      cout << "No Solution\n";
      return 0;
    }
    if (i == N + 1) {
      while (!q.empty()) {
        auto [a, p] = q.front(); q.pop_front();
        ans -= a * p;
      }
      cout << fixed << setprecision(2) << ans << '\n';
    }
    double tot = C - sum;
    while (!q.empty()) {
      if (q.back().p >= p[i] && tot + q.back().a <= C) {
        tot += q.back().a;
        q.pop_back();
      } else {
        break;
      }
    }
    q.push_front({tot, p[i]});
  }

  return 0;
}