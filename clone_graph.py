# Definition for a undirected graph node
class UndirectedGraphNode:
    def __init__(self, x):
        self.label = x
        self.neighbors = []


class Solution:
    # @param node, a undirected graph node
    # @return a undirected graph node

    def create_new_nodes(self, node):
        if not node.label in self.visited:
            # print "visited: ", self.visited
            # print "creating for: ", node.label
            node.neighbors.append(UndirectedGraphNode(node.label))
            for n in node.neighbors[:-1]:
                self.visited.append(node.label)
                self.create_new_nodes(n)
                self.visited.pop()

    def connect_new_nodes(self, node):
        if not node.label in self.visited:
            from_node = node.neighbors[-1]
            for n in node.neighbors[:-1]:
                if len(n.neighbors) > 1:
                    to_node = n.neighbors[-1]
                    from_node.neighbors.append(to_node)
            for n in node.neighbors[:-1]:
                self.visited.append(node.label)
                self.connect_new_nodes(n)
                self.visited.pop()

    def clean_up_connections(self, node):
        if not node.label in self.visited:
            node.neighbors.pop()
            for n in node.neighbors:
                self.visited.append(node.label)
                self.clean_up_connections(n)
                self.visited.pop()

    def cloneGraph(self, node):
        if not node:
            return None
        self.visited = []
        self.create_new_nodes(node)
        self.visited = []
        self.connect_new_nodes(node)
        new_node = node.neighbors[-1]
        self.visited = []
        self.clean_up_connections(node)
        return new_node

n0 = UndirectedGraphNode(0)
n1 = UndirectedGraphNode(1)
n2 = UndirectedGraphNode(2)
n3 = UndirectedGraphNode(3)
n4 = UndirectedGraphNode(4)
n5 = UndirectedGraphNode(5)

n0.neighbors.append(n1)
n0.neighbors.append(n5)

n1.neighbors.append(n2)
n1.neighbors.append(n5)

n2.neighbors.append(n3)

n3.neighbors.append(n4)
n3.neighbors.append(n4)

n4.neighbors.append(n5)
n4.neighbors.append(n5)


sol = Solution()
nn0 = sol.cloneGraph(n0)



