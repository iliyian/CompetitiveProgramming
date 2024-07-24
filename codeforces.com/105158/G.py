from random import *
import sys

sys.stdout = open("G.in", "w")

N = 5
print(N * N)
for i in range(N * N):
  print(N, i + 1)
