#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("A.in", "r", stdin);

  int t;
  cin >> t;
  while (t--) {
    long long n, sum = 0;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
      int a;
      cin >> a;
      sum += a;
    }
    cout << -sum << '\n';
  } 
  return 0;
}