#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("D.in", "r", stdin);
  int n;
  cin >> n;
  double sums = 0, tot = 0;
  for (int i = 0; i < n; i++) {
    double a, b;
    cin >> a >> b;
    sums += a;
    tot += a * b;
  }
  cout << fixed << setprecision(10) << (tot / sums);
  return 0;
}