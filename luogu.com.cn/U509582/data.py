from cyaron import *
import sys

io = IO("data.in")

n = int(2e5)
if len(sys.argv) > 1:
  n = int(sys.argv[1])

g = Graph.tree(n, 0.3, 0.3, weight_limit=n)

io.input_writeln(n)
io.input_writeln(g)