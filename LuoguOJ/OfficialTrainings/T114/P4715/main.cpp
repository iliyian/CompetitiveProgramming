// 我保证你读不懂，我已经读不懂了，但是没有看题解
// 而二叉树由于太简单找到的资料都惜字如金，tmd根本写不来

#include <bits/stdc++.h>
using namespace std;

int a[150], pa[150];

int main() {
  freopen("data.in", "r", stdin);
  int n;
  cin >> n;
  int N = 1 << n;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
    pa[i] = i;
  }
  int T = N;
  while (N >= 2) {
    int w = T / N;
    for (int i = 0; i < T; i += w << 1) {
      if (a[pa[i]] > a[pa[i + w]])
        pa[i] = pa[i + w] = N > 2 ? pa[i] : pa[i + w];
      else pa[i] = pa[i + w] = N > 2 ? pa[i + w] : pa[i];
    }
    N >>= 1;
  }
  cout << pa[0] + 1;
  return 0;
}