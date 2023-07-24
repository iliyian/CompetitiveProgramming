#include <bits/stdc++.h>
using namespace std;

int main() {
  double a, b, c;
  cin >> a >> b >> c;
  if (a == 0) {
    cout << "No!!!";
    return 0;
  }
  double n = 999 / (a + b + c);
  bool found = false;
  for (int i = 123; i <= 987; i++) {
    int count[10]; memset(count, 0, sizeof(count));
    int j = i * b / a, k = i * c / a;
    count[i / 100] = count[i / 10 % 10] = count[i % 10] = 1;
    count[j / 100] = count[j / 10 % 10] = count[j % 10] = 1;
    count[k / 100] = count[k / 10 % 10] = count[k % 10] = 1;
    int f = 0; for (int i = 1; i < 10; i++) f += count[i];
    if (f != 9) continue;
    found = true;
    cout << i << " " << j << " " << k << '\n';
  }
  if (!found) cout << "No!!!";
  return 0;
}