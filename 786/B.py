import sys
from random import randint as rand

sys.stdout = open("B.in", "w")

N, W = 100000, 1000000000
print(N, N, rand(1, N))
for _ in range(N):
  op = rand(1, 3)
  print(op, end=' ')
  if op == 1:
    print(rand(1, N), rand(1, N), rand(1, W))
  else:
    l = rand(1, N - 1)
    r = rand(l + 1, N)
    print(l, r, rand(1, N), rand(1, W))