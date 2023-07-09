#include <cstdio>
#include <algorithm>

struct Stu {
  char name[21];
  int finalGrd, classGrd;
  bool isMonitor, fromWest, hasPaper;
  int prize;
}stus[101];

int cmp(const Stu &a, const Stu &b) {
  return a.prize >= b.prize;
}

int main() {
  int n, sum = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    Stu &s = stus[i];
    char isMo, fromW;
    int paperC;
    scanf("%s %d %d %c %c %d", &s.name, &s.finalGrd, &s.classGrd, &isMo, &fromW, &paperC);
    s.isMonitor = isMo =='Y';
    s.fromWest = fromW == 'Y';
    s.hasPaper = paperC >= 1;

    s.prize = 8000 * (s.finalGrd > 80 && s.hasPaper)
      + 4000 * (s.finalGrd > 85 && s.classGrd > 80)
      + 2000 * (s.finalGrd > 90)
      + 1000 * (s.finalGrd > 85 && s.fromWest)
      + 850 * (s.finalGrd > 80 && s.isMonitor);

    sum += s.prize;
  }

  std::sort(stus, stus+n, cmp);
  
  printf("%s\n%d\n%d", stus[0].name, stus[0].prize, sum);
  return 0;
}