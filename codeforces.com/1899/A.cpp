#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  // freopen("A.in", "r", stdin);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << (n % 3 ? "First" : "Second") << '\n';
  }
  return 0;
}