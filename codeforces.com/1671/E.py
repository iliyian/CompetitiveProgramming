import random, sys

sys.stdout = open("E.in", "w")

N = 18
print(N)

for _ in range((1 << N) - 1):
  print(random.choice(['A', 'B']), end='')