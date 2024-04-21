#include <bits/stdc++.h>
using namespace std;

int a[10000001];

int main() {
  int n, A, B, C;
  cin >> n >> A >> B >> C >> a[1];
  for (int i = 2; i <= n; i++)
    a[i] = ((long long) a[i - 1] * A + B) % 100000001;
  for (int i = 1; i <= n; i++)
    a[i] = a[i] % C + 1;
  double ans = 1.0 / max(a[1], a[n]);
  for (int i = 2; i <= n; i++)
    ans += (1.0 / max(a[i], a[i - 1]));
  cout << fixed << setprecision(3) << ans;
  return 0;
}