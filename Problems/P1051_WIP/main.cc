#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

struct Stu {
  char name[21];
  int finalGrd, classGrd;
  bool isMonitor, fromWest, hasPaper;
  int prize;
  int id;
};

int cmp(const Stu &a, const Stu &b) {
  if (a.prize == b.prize) return a.id < b.id;
  return a.prize > b.prize;
}

int main() {
  int n, sum = 0;
  vector<Stu> stus;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    Stu s;
    char isMo, fromW;
    int paperC;
    scanf("%s %d %d %c %c %d", s.name, &s.finalGrd, &s.classGrd, &isMo, &fromW, &paperC);
    s.isMonitor = isMo =='Y';
    s.fromWest = fromW == 'Y';
    s.hasPaper = paperC >= 1;
    s.id = i;

    s.prize = 8000 * (s.finalGrd > 80 && paperC)
      + 4000 * (s.finalGrd > 85 && s.classGrd > 80)
      + 2000 * (s.finalGrd > 90)
      + 1000 * (s.finalGrd > 85 && fromW == 'Y')
      + 850 * (s.finalGrd > 80 && isMo == 'Y');

    sum += s.prize;

    stus.push_back(s);
  }

  sort(stus.begin(), stus.end(), cmp);
  
  printf("%s\n%d\n%d", stus[0].name, stus[0].prize, sum);
  return 0;
}

/*

4
YaoLin 87 82 Y N 0
ChenRuiyi 88 78 N Y 1
LiXin 92 88 N N 0
ZhangQin 83 87 Y N 1

*/
