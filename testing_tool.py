import os
from random import *

n = 5
tc = 5

while True:
  input = open('input.txt', 'w')
  input.write(str(tc) + '\n')
  for _ in range(tc):
    input.write(str(n) + '\n')
    a = [choice(range(n)) + 1 for _ in range(n)]
    input.write(' '.join([str(x) for x in a]) + '\n')
    shuffle(a)
    input.write(' '.join([str(x) for x in a]) + '\n')

  os.system(r"./sol > out.a")
  os.system(r"./test > out.b")
  exitcode = os.system(r"diff out.a out.b")
  if exitcode != 0: break