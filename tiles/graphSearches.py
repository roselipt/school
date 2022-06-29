#

from graph import *

#  graph implements classes for Node, Edge and Graph as a derived class of Digraph
# An instance of Graph has a list of nodes and a dict of weighted edges 
# where key node maps to a list of its edges.
# Graph implements every edge as two edges, one in each direction.

# class weightedGraph(Graph):
#     '''Weighted Graph implemented as subclass of Graph.
#     Needs a new addEdge that includes weight. 
#     Edges remains a dictionary but here each node is a key 
#     mapping to a list of tuples (child node, distance).
#     '''
#     def addEgde(self, weightedEdge):
#         '''Because this method overrides Graph, it must add each edge in both directions.'''
#         src = weightedEdge.getSource()
#         dest = self.getDestination()


problem = [ ('S', 'A', 3), ('S', 'D', 4), ('A', 'D', 5), ('A', 'B', 4), ('D', 'E', 2), \
            ('B', 'C',4), ('E','F',4), ('F', 'G', 3) ]

prob_graph = Graph()

# Add nodes
for node in ['S', 'A', 'B', 'C', 'D', 'E', 'F', 'G']:
    prob_graph.addNode(Node(node))
print(len(prob_graph.edges))

for e in problem:
    src, dest, w = e
    # THIS METHOD IS MAKING A NEW NODE FOR EVERY OCCURRENCE OF A LETTER
    print('Adding', e, 'to the graph.')

    src = prob_graph.getNode(src)
    dest = prob_graph.getNode(dest)
    if not prob_graph.hasNode(src):
        prob_graph.addNode(src)
    if not prob_graph.hasNode(dest):
        prob_graph.addNode(dest)
    edge = WeightedEdge(src, dest, w)
    # print('Adding edge of weight',w)
    # print(edge)
    prob_graph.addWeightedEdge(edge)
    
print('Problem input:', problem)
print(prob_graph, '\n')


# for node in prob_graph.nodes:
#     print(str(node))
# print(len(prob_graph.nodes))
#print(prob_graph.edges[prob_graph.nodes[0]])

print('And if my grandmother had wheels she"d be a wagon.')