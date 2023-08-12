#include <bits/stdc++.h>
using namespace std;

int a[1000];
map<int, int> dp;

int main() {
  int N, C;
  long long sum = 0;
  cin >> N >> C;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
    sum += a[i];
  }
  for (int i = 0; i < N; i++) {
    for (int j = C; j >= a[i]; j--)
      dp[j] = max(dp[j], dp[j - a[i]] + a[i]);
  }
  for (int i = C; i >= 0; i--)
    if (dp[i])
      cout << 
}