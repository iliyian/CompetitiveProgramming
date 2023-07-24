// 一定是题面不准确，没提到在x=0不能移动

#include <bits/stdc++.h>
using namespace std;

int main() {
  double H, S1, V, L, K, n;
  cin >> H >> S1 >> V >> L >> K >> n;
  double t0 = sqrt((H - K) / 5.0), t1 = sqrt(H / 5.0);
  int d0 = min(int((L + S1) - V * t0), int(n)), d1 = max(int(S1 - V * t1), 0);
  cout << d0 - d1;
  return 0;
}