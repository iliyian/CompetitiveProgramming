#include <bits/stdc++.h>
using namespace std;

double a[100001], b[100001];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  sort(a, a + n);
  sort(b, b + n);
  double suma = 0, sumb = 0, ans = -0x3f3f3f3f;
  queue<double> aq, bq;
  for (int i = n - 1, j = n - 1; i >= 0; i--) {
    suma += a[i];
    aq.push(a[i]);
    while (suma > sumb && b[j] >= 1 && j >= 0) {
      ans = max(ans, min(suma, sumb) - double(aq.size() + bq.size()));
      sumb += b[j];
      bq.push(b[j]);
      ans = max(ans, min(suma, sumb) - double(aq.size() + bq.size()));
      j--;
    }
    ans = max(ans, min(suma, sumb) - double(aq.size() + bq.size()));
  }
  ans = max(ans, 0.0);
  cout << fixed << setprecision(4) << ans;
  return 0;
}