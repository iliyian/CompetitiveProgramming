#include <iostream>
#include <string>
using namespace std;

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string n;
    int y, s;
    cin >> n >> y >> s;
    cout << n << " " << y + 1 << " " << (int(s * 1.2) >= 600 ? 600 : int(s * 1.2)) << endl;
  }
  return 0;
}