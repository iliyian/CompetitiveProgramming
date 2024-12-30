from cyaron import *

n, m = 12, 17
io = IO("graph.in", "graph.out")

g = Graph.graph(n, m, directed=False, self_loop=False, repeated_edges=False) # 生成一个n点，m边的无向图，禁止重边和自环
io.input_writeln(n, m)
io.input_writeln(g.to_str(output=Edge.unweighted_edge))