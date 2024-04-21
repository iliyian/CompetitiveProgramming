#include <cstdio>
#include <algorithm>

// 按照相同情况特殊处理的，还是宁肯多写一个id保证AC吧

struct Stu {
  char name[20];
  int y, m, d, id;
};

bool cmp(const Stu &a, const Stu &b) {
  if (a.y == b.y) {
    if (a.m == b.m) {
      if (a.d == b.d) return a.id > b.id;
      return a.d < b. d;
    }
    return a.m < b.m;
  }
  return a.y < b.y;
}

int main() {
  int n;
  scanf("%d", &n);

  Stu stus[100];

  for (int i = 0; i < n; i++) {
    Stu &s = stus[i];
    scanf("%s %d %d %d", s.name, &s.y, &s.m, &s.d);
    s.id = i;
  }

  std::sort(stus, stus+n, cmp);

  for (int i = 0; i < n; i++) {
    printf("%s\n", stus[i].name);
  }

  return 0;
}