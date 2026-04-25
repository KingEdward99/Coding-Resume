"""
    This program simulates the key locaitons of different houses in a neighboorhood
    It then finds the best route to remove snow from each edge and node
"""

#importing to help plot the different houses
import matplotlib.pyplot as plt 

#helps to create houses as nodes
import networkx as nx

#Creating the graph of the neighborhood
Neighborhood = nx.Graph()

#Adding the houses as nodes
Neighborhood.add_node("Stevie")
Neighborhood.add_node("Marvin")
Neighborhood.add_node("SZA") 
Neighborhood.add_node("Beyonce") 
Neighborhood.add_node("HER") 

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