#This program is a display of my knowledge of Hamiltonian paths
# It simulates the key locations of different houses in a neighborhood and determines
# whether there is a Hamiltonian path

#Helps to create houses as nodes
from tkinter import NE
from unittest import result
import networkx as nx
import matplotlib.pyplot as plt
from networkx import neighbors

#Creating the graph of the neighborhood
Neighborhood = nx.Graph()

#Adding the house as nodes
Neighborhood.add_node("Jacksons")
Neighborhood.add_node("Obamas")
Neighborhood.add_node("Wayans")
Neighborhood.add_node("Kings")
Neighborhood.add_node("Knowles-Carters")
Neighborhood.add_node("Quanders")

#Connecting the nodes
Neighborhood.add_edge("Jacksons", "Obamas")
Neighborhood.add_edge("Jacksons","Wayans")
Neighborhood.add_edge("Jacksons","Knowles-Carters") 
Neighborhood.add_edge("Obamas","Knowles-Carters") 
Neighborhood.add_edge("Obamas","Quanders") 
Neighborhood.add_edge("Wayans","Kings") 
Neighborhood.add_edge("Kings", "Quanders")
Neighborhood.add_edge("Knowles-Carters","Quanders")

#Specifying the position of the nodes
Pos = {
    "Jacksons" : (2.1,4.7),
    "Obamas" : (5,4.3),
    "Wayans" : (3.6,3),
    "Kings" : (6.8, 3),
    "Knowles-Carters" : (2,2.5),
    "Quanders" : (5,2.5)
}

nx.draw(
    Neighborhood,
    pos = Pos,
    with_labels = True,
    node_color = "brown",
    node_size = 3000,
    font_color = "white", 
    font_family = "Arial", 
    font_weight = "bold", 
    width = 5
)

plt.margins(0.2)

#Displaying what has been graphed
plt.show()

#Trying to find a hamiltonian path

#checking if a house is adjacent to a previous one & if the house has been visited
def is_safe(next_house, path, graph):
    if next_house in path:
        return False
    if not graph.has_edge(path[-1], next_house):
        return False
    return True

#Recursive backtracking
def ham_util(graph, path):
    if len(path) == len(graph.nodes):
        return True #full Hamiltonian path found 
    
    for house in graph.nodes:
        if is_safe(house, path, graph):
            path.append(house)
        
            if ham_util(graph, path):
                return True
        
            path.pop() #backtrack
    
    return False

#Starting from every node
def find_hamiltonian_path(graph):
    for start in graph.nodes:
        path = [start]
        if ham_util(graph, path):
            return path
        
    return None

#Displaying the Hamiltonian results 
result = find_hamiltonian_path(Neighborhood)
if result:
    print("Hamiltonian Path Found: ")
    print(" -> " .join(result))
else:
    print("No Hamiltonian Path exists")