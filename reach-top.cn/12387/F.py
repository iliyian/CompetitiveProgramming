n = int(input())
for i in range(n):
  for j in range(n + n * 2 - 1):
    if j < n or j >= n * 2 - i - 1 and j < n * 2 + i:
      print('*', end='')
    else:
      print(' ', end='')
  print()
    