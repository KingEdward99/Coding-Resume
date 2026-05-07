"""
    This program simulates the key locaitons of different houses in a neighboorhood
    It then finds the best route to remove snow from each edge and node
"""
#importing queue data structure
from collections import deque

#importing to help plot the different houses
import matplotlib.pyplot as plt 

#helps to create houses as nodes
import networkx as nx

#Creating the graph of the neighborhood
Neighborhood = nx.Graph()

#Adding the houses as nodes
Neighborhood.add_node("Stevie")
Neighborhood.add_node("Beyonce")
Neighborhood.add_node("Marvin")
Neighborhood.add_node("HER")
Neighborhood.add_node("SZA")

#Connecting the nodes
Neighborhood.add_edge("Beyonce", "HER")
Neighborhood.add_edge("Beyonce","Marvin")
Neighborhood.add_edge("HER","SZA") 
Neighborhood.add_edge("Beyonce","SZA") 
Neighborhood.add_edge("SZA","Stevie") 
Neighborhood.add_edge("Marvin","Stevie") 

#Specifying the position of the nodes
Pos = {
    "Beyonce" : (1,4),
    "HER" : (2.5,4),
    "SZA" : (2.5,6.5),
    "Marvin" : (2.5,1.8),
    "Stevie" : (5,6.5)
}

#Draws out the nodes with the specific details
nx.draw(
        Neighborhood, 
        pos = Pos, 
        with_labels = True, 
        node_color = "green", 
        node_size = 3000, 
        font_color = "white", 
        font_family = "Times New Roman", 
        font_weight = "bold", 
        width = 5
        )
plt.margins(0.2)

#Displaying what has been graphed
plt.show()

#Trying to find a eulerian path 

#Checking to see if the graph is connected using Breadth First Search algorithm 
def is_connected(G):
    #Looking for a house(node) with at least one street (edge) connected to it 
    start = None
    for house in G.nodes:
        if G.degree(house) >0:
            start = house
            break
    
    #If the house have no streets connected to it, then it is trivially connected
    if start is None:
        return True
    
    visited_house = set()
    queue_visited_house = deque([start])

    while queue_visited_house:
        current = queue_visited_house.popleft()

        if current not in queue_visited_house:
            visited_house.add(current)

            for neighbor in G.neighbors(current):
                if neighbor not in visited_house:
                    queue_visited_house.append(neighbor)
    
    #Checking to see all the houses were visited
    for house in G.nodes():
        if G.degree(house) > 0 and house not in visited_house:
            return False
    return True

#Count odd degree nodes
def odd_nodes(G):
    for house in G.nodes:
        if G.degree(house) % 2 != 0:
            odd += 1

    if odd == 0:
        return 2 #There is a Eulerian cycle
    elif odd == 2:
        return 1 #Eulerian path only 
    else:
        return 0 #Not Eulerian at all

def eulerian_status(G):
    if not is_connected(G):
        return "Not Eulerian (graph is not connected)"
    
    odd = odd_nodes(G)

    if odd == 2:
        return "Eulerian Cycle"
    elif odd == 1:
        return "Eulerian Path"
    else:
        return "Not Eulerian"

#Calling the functions 
print(eulerian_status(Neighborhood))