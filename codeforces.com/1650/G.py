import random, sys

sys.stdout = open("G.in", "w")

t = int(1)
n, m = int(2e3), int(2e3)

print(t)
for _ in range(t):
  print(n, m)
  print(1, n)
  for _ in range(m):
    while True:
      u, v = random.randint(1, n), random.randint(1, n)
      if u != v:
        print(u, v, end=' ')
        break
    print()