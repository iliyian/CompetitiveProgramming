import random, sys

sys.stdout = open("E.in", "w")

N = 1000
print(N)

for i in range(N + 2):
  if i < N:
    for _ in range(N):
      print(-1 if random.random() < 0.0006 else (1 if round(random.random()) else 0), end=' ')
  else:
    for _ in range(N):
      print(1 if round(random.random()) else 0, end=' ')
  print()