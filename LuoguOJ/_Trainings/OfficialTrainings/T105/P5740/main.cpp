// 这题我好像做过

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct Stu {
  string name;
  int c, m, e;
} stus[1000];

bool operator < (const Stu &a, const Stu &b) {
  return a.c + a.m + a.e < b.c + b.m + b.e;
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    Stu &s = stus[i];
    cin >> s.name >> s.c >> s.m >> s.e;
  }
  Stu *s = max_element(stus, stus + n);
  cout << s->name << " " << s->c << " " << s->m << " " << s->e;
  return 0;
}