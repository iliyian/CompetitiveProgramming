#include <bits/stdc++.h>
using namespace std;

int xs[1000001], ys[1000001];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < k; i++) {
    cin >> xs[i] >> ys[i];
  }
  sort(xs, xs + k);
  sort(ys, ys + k);
  auto szx = unique(xs, xs + k) - xs, szy = unique(ys, ys + k) - ys;
  cout << n * n - (n - szx) * (n - szy);
  return 0;
}