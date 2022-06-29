#  Node class from textbook, 

class Node(object):
    def __init__(self, name):
        """Assumes name is a string"""
        self.name = name
    def getName(self):
        return self.name
    def __str__(self):
        return self.name
        
class Edge(object):
    def __init__(self, src, dest):
        """Assumes src and dest are nodes"""
        self.src = src
        self.dest = dest
    def getSource(self):
        return self.src
    def getDestination(self):
        return self.dest
    def __str__(self):
        return self.src.getName() + '->' + self.dest.getName()

class WeightedEdge(Edge):
    def __init__(self, src, dest, weight = 1.0):
        """Assumes src and dest are nodes, weight a float"""
        self.src = src
        self.dest = dest
        self.weight = weight
    def getWeight(self):
        return self.weight
    def __str__(self):
        return self.src.getName() + '->(' + str(self.weight) + ')' + self.dest.getName()

class Digraph(object):
    #nodes is a list of nodes in the graph
    #edges is a dict mapping each node to a list of its children
    def __init__(self):
        #self.nodes = []
        # Let dictionary keys be the list of nodes
        self.edges = {}
    def addNode(self, node):
        if node in self.edges:
            raise ValueError('Duplicate node')
        else:
            #self.nodes.append(node)
            self.edges[node] = []
    def addEdge(self, edge):
        src = edge.getSource()
        dest = edge.getDestination()
        if not(src in self.edges and dest in self.edges):
            raise ValueError('Node not in graph')
        else:
            self.edges[src].append(dest)
    def addWeightedEdge(self, weightedEdge):
        src = weightedEdge.getSource()
        dest = weightedEdge.getDestination()
        weight = weightedEdge.getWeight()
        if not(src in self.edges and dest in self.edges):
            raise ValueError('Node not in graph')
        else:
            self.edges[src].append((dest, weight))
    def childrenOf(self, node):
        return self.edges[node]
    def hasNode(self, node):
        return node in self.edges
    def getNode(self, name):
        for n in self.edges:
            if name == n.getName():
                return n
        raise NameError(name)
    def __str__(self):
        result = ''
        for src in self.edges:
            # SHOULD THIS BE GET INSTEAD OF BRACKETS BELOW?
            for e in self.edges[src]:
                dest, weight = e
                result = result + src.getName() + ' -> (' + str(weight) + ') ' + dest.getName() + '\n'
        return result[:-1]  # omits final newline
        
class Graph(Digraph):
    """Implementation of a graph as subclass of Digraph, from textbook"""
    def addWeightedEdge(self, weightedEdge):
        Digraph.addWeightedEdge(self, weightedEdge)
        rev = WeightedEdge(weightedEdge.getDestination(), weightedEdge.getSource(), weightedEdge.getWeight())
        Digraph.addWeightedEdge(self, rev)
    
