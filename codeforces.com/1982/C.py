import random, sys

sys.stdout = open("C.in", "w")
print(10)
N, l, r = 10, 10, 10
for t in range(10):
  print(N, l, r)
  for i in range(N):
    print(random.randint(1, 5), end=' ')
  print()