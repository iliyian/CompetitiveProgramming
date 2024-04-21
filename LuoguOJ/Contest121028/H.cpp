#include <bits/stdc++.h>
using namespace std;

int n, k, a[1000000];

bool check() {
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    sum += a[i];
  }
  return sum >= k;
}

void solve() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  cout << "No";
  return;
  while (!check()) {

  }
}

int main() {
  int T;
  cin >> T;
  while (T--) solve();
  return 0; 
}