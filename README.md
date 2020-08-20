# A4-Part-II-Q1
includes: Dijkstra.cpp, README.md (This is the current file you're on), printOut.md.

Dijkstra.cpp:

Dijkstra.cpp is an integer algorithim program. It comes with a greeting and instructions for inputs.
For this demonstration, we are limited to 9 vertices and have a preset graph that's created (explained through the available nodes within the graph, printed out in the format of:

(Node------connectingNode(weight))
They have values 0-8. 

You can input any number from 0-8 for which node you want to see the minimum distances from, any other number will result in a loop of the program until you select a number between 0-8.

Then the program will take all the nodes by using the addEdge function. Then, based on the user's selection, it will calculate whats the shortest distance between the nodes and the inputNode.
It does this through going through the set of nodes from addEdges, and begins extracting them through the set containing nodes and weights.

Once it finds the shortest distance, it goes to the next node and it's paired weight.

After it finds all the nodes, then it will print it out.

printOut.md: is the output text.log from running the program.
