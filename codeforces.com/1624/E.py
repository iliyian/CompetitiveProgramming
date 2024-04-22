import random, sys

sys.stdout = open("E.in", "w")

t = 100
print(t)

for _ in range(t):
  n, m = random.randint(1, 100), random.randint(1, 100)
  print(n, m)
  for _ in range(n + 1):
    for _ in range(m):
      print(random.randint(0, 9), end='')
    print()
