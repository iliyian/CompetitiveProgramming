#include <bits/stdc++.h>
using namespace std;

struct Pos {
  int x, y, z;
} dots[50005];

bool operator < (const Pos &a, const Pos &b) {
  return a.z < b.z;
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> dots[i].x >> dots[i].y >> dots[i].z;
  }
  sort(dots, dots + n);
  double d = 0;
  for (int i = 1; i < n; i++) {
    Pos &u = dots[i], &v = dots[i - 1];
    d += sqrt((u.x - v.x) * (u.x - v.x) + (u.y - v.y) * (u.y - v.y) + (u.z - v.z) * (u.z - v.z));
  }
  cout << fixed << setprecision(3) << d;
  return 0;
}