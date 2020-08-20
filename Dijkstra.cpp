#include <iostream>
#include <set>
#include <vector>
#include <list>


#define INF 1000000

using namespace std;

class Graph {
private:
	//Number of vertices
	int V;
	//points to adjacency list
	list<pair<int, int>> *adj;

public:
	Graph(int v);
	void addEdge(int v1, int v2, int weight);
	void shortestPath(int s);

};

//graph constructor
Graph::Graph(int v) {
	//set's number of vertices
	V = v;
	//create's new adjacency list
	adj = new list<pair<int, int>>[v];
}

//adding edges onto the graph
void Graph::addEdge(int v1, int v2, int weight)
{
	adj[v1].push_back(make_pair(v2, weight));
}

//our hard dijkstra implentation
void Graph::shortestPath(int s) {
	//create's a set to store vertices
	//we will extract the shortest path line with this
	set<pair<int, int>> extract_set;

	//all path's are intialized to the largest value
	//and we find their distances later on
	vector<int> distances(V, INF);

	//we enter into our set, and initialize distances on that set to 0
	extract_set.insert(make_pair(0, s));
	distances[s] = 0;

	//while looking for our shortest distance...
	while (!extract_set.empty()) {
		//extract the minimum distances, and delete them from the extract set
		pair<int, int> tmp = *(extract_set.begin());
		extract_set.erase(extract_set.begin());

		//get the vertext number
		int nodeNum = tmp.second;

		//look through the adjacency list
		for (auto i = adj[nodeNum].begin(); i != adj[nodeNum].end(); i++)
		{
			//checking the vertex and weight
			int v = (*i).first;
			int weight = (*i).second;

			//check if we have found a shorter path to v
			//we only keep track of our distance compared to one node
			if (distances[v] > distances[nodeNum] + weight)
			{
				//while distance doesn't equal values above INF
				if (distances[v] != INF) {
					extract_set.erase(extract_set.find(make_pair(distances[v], v)));

				}

				//update the distance
				distances[v] = distances[nodeNum] + weight;
				extract_set.insert(make_pair(distances[v], v));
			}
		}
	}

	cout << "Minimum distances from vertex: " << s << endl;
	for (int i = 0; i < V; i++)
		cout << "Vertext: " << i << "\tDistance: " << distances[i] << endl;
}

int main() {
	//creates a graph that can hold 9 vertices from 0,8
	//you can change this value or make it more user input friendly
	//but for now we'll just show it as 9 to test it out
	Graph g(9);
	cout << "Welcome to the Dijkstra Integer program!" << endl;
	cout << "The graph has the following nodes " << endl
		<< "The format looks like: node----connectingNode(weight): " << endl
		<< "0----1(8)" << endl
		<< "0----8(8)" << endl
		<< "1----2(11)" << endl
		<< "1----3(8)" << endl
		<< "2----1(11)" << endl
		<< "2----3(2)" << endl
		<< "2----7(6)" << endl
		<< "3----1(8)" << endl
		<< "3----2(2)" << endl
		<< "3----4(7)" << endl
		<< "4----3(7)" << endl
		<< "4----5(14)" << endl
		<< "4----6(5)" << endl
		<< "5----4(14)" << endl
		<< "5----6(4)" << endl
		<< "5----7(2)" << endl
		<< "6----4(5)" << endl
		<< "6----5(4)" << endl
		<< "7----2(6)" << endl
		<< "7----5(2)" << endl
		<< "7----8(1)" << endl
		<< "8----0(8)" << endl
		<< "8----7(1)" << endl;
	cout << "This is the graph/vertices you are given: " << endl;

	//sample graph I created, this is what it looks like:
	/* (#) represents weight on the line

	1	---(8)---  3  ---(7)---  4
	(4)/  \			|(2)		 |	\(5)
	0		-----(11)-  2			 |(14) 6
	(8)\   			|(6)		 |	/(4)
	8	---(1)---  7  ---(2)---  5

	*/
	//You can also make this user-input friendly
	//I decided to just code in the inputs.

	g.addEdge(0, 1, 4);
	g.addEdge(0, 8, 8);

	g.addEdge(1, 2, 11);
	g.addEdge(1, 3, 8);

	g.addEdge(2, 1, 11);
	g.addEdge(2, 3, 2);
	g.addEdge(2, 7, 6);

	g.addEdge(3, 1, 8);
	g.addEdge(3, 2, 2);
	g.addEdge(3, 4, 7);

	g.addEdge(4, 5, 14);
	g.addEdge(4, 6, 5);

	g.addEdge(5, 4, 14);
	g.addEdge(5, 6, 4);
	g.addEdge(5, 7, 2);

	g.addEdge(6, 4, 5);
	g.addEdge(6, 5, 4);

	g.addEdge(7, 2, 6);
	g.addEdge(7, 5, 2);
	g.addEdge(7, 8, 1);

	g.addEdge(8, 0, 8);
	g.addEdge(8, 7, 1);

	int inquiryNode = 0;
	cout << "Please enter a value from 0-8, of what you want to find the shortest path to: ";
	cin >> inquiryNode;

	while (inquiryNode < 0 || inquiryNode > 8)
	{
		cout << "invalid response, to retry again please input a value from 0-8 of what you want to find the shortest path to: ";
		cin >> inquiryNode;
	}

	g.shortestPath(inquiryNode);
	return 0;
}