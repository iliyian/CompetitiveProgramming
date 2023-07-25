#include <cstdio>
#include <array>
#define matrix array<array<bool, 10>, 10>
using namespace std;

int n;

void turn(matrix &sqr) {
  matrix temp{};
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      temp[j][n - i - 1] = sqr[i][j];
  sqr = temp;
}

int checkTurn(matrix sqr, matrix &t) {
  for (int i = 1; i <= 3; i++) {
    turn(sqr);
    if (sqr == t) return i;
  }
  return 0;
}

void flip(matrix &sqr) {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n / 2; j++)
      swap(sqr[i][j], sqr[i][n - 1 - j]);
}

int main() {
  // freopen("data.in", "r", stdin);
  
  scanf("%d\r\n", &n);
  matrix sqr1{};
  matrix sqr2{};

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      char ch = getchar();
      sqr1[i][j] = ch == '@' ? 1 : 0;
    }
    getchar();
    getchar();
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      char ch = getchar();
      sqr2[i][j] = ch == '@' ? 1 : 0;
    }
    getchar();
    getchar();
  }

  int checkT = checkTurn(sqr1, sqr2);
  if (checkT) {
    printf("%d", checkT);
    return 0;
  }

  flip(sqr1);
  if (sqr1 == sqr2) {
    printf("4");
    return 0;
  }
  if (checkTurn(sqr1, sqr2)) {
    printf("5");
    return 0;
  }
  flip(sqr1);

  if (sqr1 == sqr2) {
    printf("6");
    return 0;
  }
  
  // for (int i = 0; i < n; i++) {
  //   for (int j = 0; j < n; j++)
  //     printf("%c", sqr1[i][j] ? '@' : '-');
  //   printf("\n");
  // }

  printf("7");
  return 0;
}