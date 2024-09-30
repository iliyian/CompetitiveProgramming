#include <bits/stdc++.h>
using namespace std;

int x[10001], y[10001];
double f[10001];

double dist(int a, int b) {
  double d = sqrt((x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b]));
  return d;
}

int penalty(int a, int b) {
  int p = 0;
  if (b - a >= 31) return 0x3f3f3f3f;
  for (int i = b + 1; i < a; i++)
    p |= 1 << i - 1;
  return p;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("B.in", "r", stdin);
  int N;
  cin >> N;
  for (int i = 1; i <= N; i++)
    cin >> x[i] >> y[i];
  memset(f, 0x3f, sizeof(f));
  f[0] = 0;

  

  cout << fixed << setprecision(20) << f[N];
  return 0;
}