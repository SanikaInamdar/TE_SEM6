import heapq

class Node:
    def __init__(self, parent, position, g, h):
        self.parent=parent
        self.position=position
        self.g=g
        self.h=h
        self.f=g+h
    
    def __lt__(self,other):
        return self.f < other.f

def a_star(matrix, start_loc, end_loc):

    open_list=[]
    closed_set = set()

    start_node=Node(None, start_loc, 0, 0)
    heapq.heappush(open_list,(start_node.f, start_node))

    while open_list:
        current=heapq.heappop(open_list)[1]
        closed_set.add(current.position)

        if(current.position==end_loc):
            path=[]
            while current:
                path.append(current.position)
                current=current.parent
            path.reverse()
            return path

        directions=[(0,1), (0,-1), (1,0), (-1,0)]

        for direction in directions:
            new_position=((current.position[0]+direction[0]),(current.position[1]+direction[1]))

            if(
                new_position[0]<0 or new_position[0]>=len(matrix[0]) or
                new_position[1]<0 or new_position[1]>=len(matrix[0]) or
                matrix[new_position[0]][new_position[1]]==1 or
                new_position in closed_set
            ):
                continue

            new_node=Node(current, new_position, current.g+1, abs(end_loc[1]-new_position[1])+ abs(end_loc[0]-new_position[0]))

            if any(node.position == new_node.position for _, node in open_list):
                continue

            heapq.heappush(open_list,(new_node.f, new_node))

    return []

matrix= [
    [0, 0, 0, 0, 0, 0],
    [0, 1, 1, 1, 1, 0],
    [0, 1, 0, 0, 0, 0],
    [0, 0, 1, 0, 0, 1],
    [0, 1, 0, 0, 0, 0],
    [0, 0, 1, 1, 0, 0]
]
start_loc=(0,0)
end_loc=(5,5)
path = a_star(matrix, start_loc, end_loc)
if path:
    print("Path Found: ", path)
else:
    print("Path not found")
    