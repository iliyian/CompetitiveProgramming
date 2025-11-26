import sys

for _ in range(int(input())):
  f = False
  for i in range(0, 100):
    print("?", i)
    sys.stdout.flush()
    ans = int(input())
    if ans == 1:
      print("!", i)
      f = True
      break
  if not f:
    print("! 100")