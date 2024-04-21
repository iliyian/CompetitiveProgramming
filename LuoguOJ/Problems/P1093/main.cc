#include <cstdio>
#include <algorithm>

struct Stu {
  int id, sum, chn;
};

bool cmp(const Stu &a, const Stu &b) {
  if (a.sum == b.sum) {
    if (a.chn == b.chn) return a.id < b.id;
    return a.chn > b.chn;
  }
  return a.sum > b.sum;
}

int main() {
  int n;
  Stu stus[301];
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    stus[i] = {i+1, a+b+c, a};
  }

  std::sort(stus, stus+n, cmp);

  for (int i = 0; i < 5; i++) {
    printf("%d %d\n", stus[i].id, stus[i].sum);
  }
  
  return 0;
}