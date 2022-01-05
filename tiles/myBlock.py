#  Let's try reprenting a simple graph with graph.py
# Four points, ABCD with edges as a square

from graph import *

first = Node('A')
second = Node('B')
third = Node('C')

print(first)
Edge(first, second)
path1 = Edge(first, second)
path2 = Edge(second, third)
print(path1, path2)

g = Graph()
g.addNode(first)
g.addNode(second)
g.addEdge(path1)
print(g)
print(type(g))
