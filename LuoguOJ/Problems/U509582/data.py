from cyaron import *

io = IO("data.in")

n = int(16)

g = Graph.tree(n, 0.3, 0.3, weight_limit=n)

io.input_writeln(n)
io.input_writeln(g)