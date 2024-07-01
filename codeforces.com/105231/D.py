import sys, random

sys.stdout = open("D.in", "w")

T = 1
N = int(1e6)

print(T)
for _ in range(T):
  print(N)
  for _ in range(N):
    print(random.randint(1, N), end=' ')
  print()