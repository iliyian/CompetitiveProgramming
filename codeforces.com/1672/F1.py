import random, sys

t, N = 1, int(2e5)

sys.stdout = open("F1.in", "w")

print(t)
for _ in range(t):
  print(N)
  for _ in range(N):
    print(random.randint(1, N), end=' ')
  print()