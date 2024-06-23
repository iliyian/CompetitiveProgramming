import random, sys

sys.stdout = open("D.in", "w")

N = int(2e5)
a, b = [], []

for i in range(N):
  a.append(i + 1)
for i in range(N):
  b.append(i + 1)

random.shuffle(a)
random.shuffle(b)

print(N)
for i in a:
  print(i, end=' ')
print()
for i in b:
  print(i, end=' ')