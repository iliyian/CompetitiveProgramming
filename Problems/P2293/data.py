import sys

sys.stdout = open("main.in", "w")

print(2)
print(5, end='')
for i in range(5000):
  print(0, end='')