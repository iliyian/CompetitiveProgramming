import random, sys

sys.stdout = open("G2.in", "w")

t, N = 1, int(2e5)

print(t)
for _ in range(t):
  print(N, 1, N)
  for _ in range(N):
    print(random.choice("abcdefghijklm"), end='')
  print()