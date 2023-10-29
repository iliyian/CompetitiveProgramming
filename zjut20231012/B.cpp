#include <bits/stdc++.h>
using namespace std;

int C(int m, int n) {
  int ans = 1;
  for (int i = m; i >= m - n + 1; i--)
    ans *= i;
  for (int i = 2; i <= n; i++)
    ans /= i;
  return ans;
}

void print(double ans) {
  cout << fixed << setprecision(12) << ans;
  exit(0);
}

int main() {
  freopen("B.in", "r", stdin);
  string a, b;
  cin >> a >> b;
  int pos = 0;
  for (int i = 0; i < a.size(); i++) {
    if (a[i] == '+') pos++;
    else pos--;
  }
  int k = 0;
  for (int i = 0; i < b.size(); i++) {
    if (b[i] == '+') pos--;
    else if (b[i] == '-') pos++;
    else k++;
  }
  int d = abs(pos);
  if (!d && !k) {
    print(1.0);
    return 0;
  }
  if ((d + k) & 1 || d > k) {
    print(0.0);
    return 0;
  }

  // ?????? k = 6, d = 4
  // 3
  int n = (k - d) >> 1;
  double ans = C(k, n);
  for (int i = 1; i <= k; i++)
    ans /= 2;
  cout << fixed << setprecision(12) << ans;
  return 0;
}