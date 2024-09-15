from cyaron import *

io = IO(None, "D.in")

g = Graph.tree(int(5e4), )
io.output_writeln(int(5e4), int(5e2))
io.output_write(g.to_str(output=Edge.unweighted_edge))