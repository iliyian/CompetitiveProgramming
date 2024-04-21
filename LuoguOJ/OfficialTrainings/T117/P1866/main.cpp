#include <bits/stdc++.h>
using namespace std;

int a[50];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(a, a + n);
  long long ans = 1;
  for (int i = 0; i < n; i++)
    ans = ans * (a[i] - i) % int(1e9 + 7);
  cout << ans;
  return 0;
}
