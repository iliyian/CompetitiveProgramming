import sys, random

sys.stdout = open("B.in", "w")

t, N, c = 1, int(1e5), int(1e5)

print(t)
for _ in range(t):
  print(N, c)
  for i in range(N):
    # print(i + 1, end=' ')
    print(random.randint(1, c), end=' ')
  print()q