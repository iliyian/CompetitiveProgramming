#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "w", stdout);
  mt19937 ra(random_device{}());
  int N = 1000000;
  for (int i = 0; i < N; i++)
    cout << ra() % 10;
  cout << '\n';
  for (int i = 0; i < N; i++)
    cout << ra() % 10;
  return 0;
}