#include <cstdio>
#include <cstring>

int main() {
  int n, arr[34];
  scanf("%d", &n);
  memset(arr, 0, sizeof(arr));
  for (int i = 0; i < 7; i++) {
    int a;
    scanf("%d", &a);
    arr[a] = 1;
  }
  int prize[8];
  memset(prize, 0, sizeof(prize));
  while (n--) {
    int count = 0;
    for (int i = 0; i < 7; i++) {
      int a;
      scanf("%d", &a);
      if (arr[a]) count++;
    }
    prize[count]++;
  }
  for (int i = 7; i >= 1; i--) {
    printf("%d ", prize[i]);
  }
  return 0;
}