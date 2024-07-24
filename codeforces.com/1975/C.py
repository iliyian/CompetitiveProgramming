import random, sys

sys.stdout = open("C.in", "w")

t, N = 10, 10
print(t)
for _ in range(N):
  print(N)
  for i in range(N):
    print(random.randint(1, 100), end=' ')
  print()