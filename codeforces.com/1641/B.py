import random, sys

sys.stdout = open("B.in", "w")

t, N = 1, 500

print(t)
for _ in range(t):
  print(N)
  num = [i % 25 for i in range(1, N + 1)]
  random.shuffle(num)
  for i in num:
    print(i, end=' ')
  print()