#include <cstdio>

int main() {
  int N;
  scanf( "%d", &N );
  for ( int i = 1 ; ; i++ ) {
    int right = (1+i) * i / 2;
    if ( N <= right ) {
      int sum = i+1, son;
      if ( ( i & 1 ) ) {
        son = right - N + 1;
      } else {
        son = i - (right - N);
      }
      printf("%d/%d\n", son, sum - son);
      break;
    }
  }
  return 0;
}