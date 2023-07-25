#include <bits/stdc++.h>
using namespace std;

int votes[2000010];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> votes[i];
  }
  sort(votes, votes + m);
  for (int i = 0; i < m; i++) {
    cout << votes[i] << ' ';
  }
  return 0;
}