#include <bits/stdc++.h>
using namespace std;

int cows[20010];

int main() {
  int n, h;
  cin >> n >> h;
  for (int i = 0; i < n; i++) cin >> cows[i];
  sort(cows, cows + n);
  int cur = 0, cnt = 0;
  for (int i = n - 1; i >= 0; i--) {
    cur += cows[i], cnt++;
    if (cur >= h) break;
  }
  cout << cnt;
  return 0;
}