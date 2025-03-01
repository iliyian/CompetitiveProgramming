#include <bits/stdc++.h>
using namespace std;

struct Water {
  int t, id;
} waters[100005];

bool operator < (const Water &a, const Water &b) {
  return a.t < b.t;
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> waters[i].t;
    waters[i].id = i;
  }
  sort(waters, waters + n);
  double ans = 0;
  for (int i = 0; i < n; i++) {
    ans += waters[i].t * (n - i - 1);
    cout << waters[i].id + 1 << ' ';
  }
  cout << '\n';
  cout << fixed << setprecision(2) << ans / n;
  return 0;
}