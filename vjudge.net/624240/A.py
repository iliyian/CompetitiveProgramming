import sys, random

sys.stdout = open("A.in", "w")

print(300)
for i in range(300):
  print(300 - i, end=' ')
print()  

for i in range(150):
  print(i * 2 + 1)