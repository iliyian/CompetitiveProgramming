#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  int ans = 1;
  cin >> n;
  for (int i = 2; i <= n; i++)
    ans = ans * i;
  cout << ans;
}