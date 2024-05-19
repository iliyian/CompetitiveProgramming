import sys
from random import *

sys.stdout = open("I.in", "w")

N, M = int(1e3), int(1e5)

print(N, M)
for _ in range(N):
  print(randint(1, int(1e4)), randint(1, int(1e2)))
for i in range(M):
  print(randint(1, int(1e9)))