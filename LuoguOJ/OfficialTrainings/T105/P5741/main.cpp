#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

struct Stu {
  string n;
  int c, m, e, s;
} stus[1000];

bool isSimilar(const Stu &a, const Stu &b) {
  return abs(a.c - b.c) <= 5 && abs(a.m - b.m) <= 5 && abs(a.e - b.e) <= 5 && abs(a.s - b.s) <= 10;
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    Stu &s = stus[i];
    cin >> s.n >> s.c >> s.m >> s.e;
    s.s = s.c + s.m + s.e;
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (isSimilar(stus[i], stus[j])) {
        cout << stus[i].n << " " << stus[j].n << endl;
      }
    }
  }
  return 0;
}