#include <bits/stdc++.h>
using namespace std;

int a[101];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int N;
  cin >> N;
  for (int i = 0; i < N; i++)
    cin >> a[i];
  int K;
  cin >> K;
  for (int i = 0; i < K; i++) {
    bool ok = false, wrong = false, bet = false;
    for (int j = 0; j < N; j++) {
      int x;
      cin >> x;
      if (x) {
        bet = true;
        if (x != a[j]) wrong = true;
        else ok = true;
      }
    }
    if (!wrong && ok) cout << "Da Jiang!!!" << '\n';
    else if (wrong || !bet) cout << "Ai Ya" << '\n';
  }
  return 0;
}