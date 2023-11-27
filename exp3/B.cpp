#include <bits/stdc++.h>
#define N 1005
using namespace std;

int a[N];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("B.in", "r", stdin);
  int n, k, t = 0;
  cin >> n >> k;
  int cur = n;
  for (int i = 0; i <= k; i++) {
    cin >> a[i];
    if (a[i] > n) {
      cout << "No Solution!";
      return 0;
    }
    if (cur < a[i]) t++, cur = n;
    cur -= a[i];
  }
  cout << t;
  return 0;
}