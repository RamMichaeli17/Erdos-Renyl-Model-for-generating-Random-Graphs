#define _CRT_SECURE_NO_WARNINGS

/*
Assigned by:
Student1_Ram_Michaeli
Student2_Gal_Israeli
*/


#include <iostream>
#include <vector>
#include <time.h> 
#include <queue>
#include <fstream>

using namespace std;


// Functions Declarations
vector<vector<int>> build_random_graph(int, float);
bool Is_Isolated(vector<vector<int>>&);
bool connectivity(vector<vector<int>>&);
int BFS_max_distance(vector<vector<int>>&, int, vector<bool>&, vector<int>&);
int diameter(vector<vector<int>>&);
//Useful functions for graphs with a small number of vertices or for a complete graph (not used in the program)
//int CalcNumOfEdges(vector<vector<int>>&);
//bool isCompleteGraph(vector<vector<int>>&, int);
//bool isTree(vector<vector<int>>&, int);
//int calcTreeDiam(vector<vector<int>>&, vector<bool>&, vector<int>&);
//void printGraph(vector<vector<int>>&);


// This function is used to generate a random undirected graph as an adjacency list 
vector<vector<int>> build_random_graph(int V, float p)
{
	int i, j;
	float random;
	vector<vector<int>>Graph(V);
	for (i = 0; i < V; i++)
	{
		for (j = i + 1; j < V; j++)
		{

			random = ((float)rand() / (RAND_MAX)); // Generate a random number between 0-1

			if (random <= p)
			{
				Graph[i].push_back(j);
				Graph[j].push_back(i);
				// Undirected graph , therefore i->j && j->i
			}
		}

	}
	return Graph;

}

int BFS_max_distance(vector<vector<int>>& graph, int root, vector<bool>& visited, vector<int>& distances) // BFS , O(V+E)
{
	int max = 0, v;
	queue<int> q;
	vector<int>::iterator i;
	visited[root] = true; // mark root as visited
	q.push(root); // push root to queue

	while (!q.empty()) // while queue is not empty
	{
		v = q.front();  // set variable V to be equal to the front variable in queue
		q.pop(); // remove front variable from queue

		for (i = graph[v].begin(); i != graph[v].end(); i++) // itirate through all of 'v' (current vertex) neighbours 
		{
			if (visited[*i]) // if current neighbour is visited , we continue to the next itiration (i++)
				continue;
			distances[*i] = distances[v] + 1; // 'else' - we update current neighbours distance to be the distance of the parent vertex +1
			q.push(*i); // push the neighbour to the queue
			visited[*i] = true; // mark neighbour as visited
			if (distances[*i] > max) // if current neighbours distance is the biggest distance yet , we save it into max
				max = distances[*i];
		}
	}
	return max;
}
//Useful functions for graphs with a small number of vertices or for a complete graph (not used in the program)
/*
void printGraph(vector<vector<int>>& graph)
{
	// Here we loop through all the vertices , printing them and all their neighbours
	// This function is not used , but is useful for testing
	cout << "\nPrinting the graph..." << endl;
	int i;
	for (i = 0; i < graph.size(); i++)
	{
		cout << "\n[Vertex "<< i+1 << "] ";
		for (auto x : graph[i])
		{
			cout << " -> " << x+1;
		}
		printf("\n");
	}
	printf("\n");
}

int CalcNumOfEdges(vector<vector<int>>&graph)
{
	// This function is used to calculate the edges of a given graph
	int numOfEdges = 0;
	for (int i = 0; i < graph.size(); i++) // iterate through all the vertices
	{
		numOfEdges += graph[i].size(); // sum all the neighbours
	}
	return (numOfEdges / 2); // sum of all neighbours divided by 2 is the amount of edges in an undirected graph
}

bool isCompleteGraph(vector<vector<int>>&graph,int numOfEdges)
{
	// This function is used to determine if a given graph is a complete graph
	return ((numOfEdges) == (  (graph.size()*(graph.size()-1 ))/2)  ); // if numOfEdges = V*(V-1)/2 , that means graph is complete
}

bool isTree(vector<vector<int>>&graph,int numOfEdges)
{
	// This function is used to determine if given graph is a tree.
	// This function can only be called after graph has been checked for connectivity
	return (numOfEdges == (graph.size() - 1)); // If the number of edges = V-1 , then we return true
}

int calcTreeDiam(vector<vector<int>>&graph, vector<bool>& visited, vector<int>& distances)
{
	// Here we use BFS to calculate the diameter of a tree
	// If we know the graph is a tree , we simply run BFS on any node , then run another BFS from the farthest node.
	// After 2 BFS , we know what the diameter is. (it's the farthest distance in the second BFS run)
	int v, max=0,farthestVertex=0;
	queue<int> q;
	vector<int>::iterator i;

	visited[0] = true;
	q.push(0);

	while (!q.empty())
	{
		v = q.front();
		q.pop();
		for (i = graph[v].begin(); i != graph[v].end(); i++)
		{

			if (visited[*i])
				continue;
			distances[*i] = distances[v] + 1;
			q.push(*i);
			visited[*i] = true;
			if (distances[*i] > max)
			{
				max = distances[*i];
				farthestVertex = (*i); // Here we keep track of the farthest vertex
			}
		}

	}
	visited.assign(graph.size(), false);
	distances.assign(graph.size(), 0);
	return BFS_max_distance(graph,farthestVertex,visited,distances); // After finding the farthest vertex in the first BFS , we send it to the regular BFS function, which will find the diameter of the tree
}
*/

int diameter(vector<vector<int>>& graph)
{
	// This function is used to calculate diameter of a given graph
	int V = graph.size();
	// #1 If the graph is not connected , return V+1 (This indicates 'infinite' diameter)
	if (!connectivity(graph))
		return (V + 1);
	//Useful functions for graphs with a small number of vertices or for a complete graph (not used in the program)
	/*
	int numOfEdges = CalcNumOfEdges(graph);

	// #2 If the graph is complete , we simply return 1
	if (isCompleteGraph(graph,numOfEdges))
		return 1;

	// #3 If the graph is a tree, we only need 2 BFS to find out the diameter
	if (isTree(graph,numOfEdges))
		return calcTreeDiam(graph,visited,distances);*/

	vector<bool> visited = vector<bool>(V, false);
	vector<int> distances = vector<int>(V, 0);

	// #4 If the graph is connected , not complete and not a tree , we calculate diameter using BFS on every node
	int i, max = 0, current;
	for (i = 0; i < V; i++) // For each vertex
	{
		current = BFS_max_distance(graph, i, visited, distances); // Find farthest distance
		visited.assign(graph.size(), false);
		distances.assign(graph.size(), 0);

		if (current > max) // If distance is the farthest distance yet , save it
		{
			max = current;
		}

	}
	return max; // max = diam(G)

}

bool connectivity(vector<vector<int>>& graph)
{
	// This function checks if given graph is connected
	// If an isolated vertex exists , we can end the function here and return false
	if (Is_Isolated(graph))
		return false;

	/*
	If there is no isolated vertex , what we do is we run BFS from node 0
	And then we check how many times the algorithm has marked a vertex as "visited"
	If that number equals V , then we know it's connected , otherwise return false
	*/
	int v, counter = 1, NoOfVer = graph.size();
	queue<int> q;
	vector<bool>visited(NoOfVer, false);
	vector<int>::iterator i;

	visited[0] = true;
	q.push(0);

	while (!q.empty())
	{
		v = q.front();
		q.pop();
		for (i = graph[v].begin(); i != graph[v].end(); i++)
		{
			if (visited[*i])
				continue;
			q.push(*i);
			visited[*i] = true;
			counter++;
		}
	}
	return (counter == NoOfVer);
}

bool Is_Isolated(vector<vector<int>>& graph)
{
	// This function is used to determine if given graph contains isolated vertex
	for (int i = 0; i < graph.size(); i++) // For each vertex
	{
		if (graph[i].empty()) // If it has no neighbours
			return true;
	}
	return false;
}


int main()
{
	ofstream myFileConnectivity, myFileDiameter, myFileIsIsolated;
	int i, j, counterConnectivity, counterIsIsolated, counterDiameter;
	float ArrayEstimationOfProbability_Connectivity[10], ArrayEstimationOfProbability_IsIsolated[10], ArrayEstimationOfProbability_Diameter[10];
	srand(time(NULL)); // Seed time in main, so everytime we execute the program we get different random graphs
	vector<vector<int>>mainGraph;

	float connectivityArray[10] = { 0.001,0.002,0.003,0.004,0.005 , 0.00699 , 0.0075, 0.008,0.009,0.01 };
	float isIsolatedArray[10] = { 0.0009,0.0015,0.0028,0.0037,0.0053 , 0.00699 , 0.0079, 0.0084,0.0092,0.015 };
	float DiameterArray[10] = { 0.015,0.03,0.06,0.09,0.103 , 0.118 , 0.125, 0.139,0.159,0.175 };



	cout << "Hello user, starting the program....meanwhile please read the instructions:" << endl;
	cout << "After the program will be done, in the project folder 3 new files will be created:" << endl;
	cout << "File No.1-connectivityFile.csv" << endl;
	cout << "File No.2-diameterFile.csv" << endl;
	cout << "File No.3-isIsolatedFile.csv" << endl;
	cout << "In each file a table with the selected probabilites and the outputs of the program will be created." << endl;
	cout << "During the running of the program, evrey 100 graphs you will see an output in the cmd so you'll be able to follow the progress of the program." << endl;


	// Attribute #1 - Connectivity 
	cout << "\n|Connectivity|" << endl;
	myFileConnectivity.open("connectivityFile.csv"); // Open file and check if opened succesfully
	if (!(myFileConnectivity.is_open()))
	{
		cout << "myFileConnectivity failed to open" << endl;
		exit(1);
	}
	myFileConnectivity << "P,0.001,0.002,0.003,0.004,0.005 , 0.00699 , 0.0075, 0.008,0.009,0.01" << endl << "Amount of connected graphs,"; // Write probabilities into file
	for (i = 0; i < 10; i++) // For each probability , run 500 graphs and check number of connected graph
	{
		counterConnectivity = 0;
		for (j = 0; j < 500; j++)
		{
			if (j % 100 == 0)
				cout << "Probability #" << i + 1 << ": [" << connectivityArray[i] << "]   Graph #" << j << endl;
			mainGraph = build_random_graph(1000, connectivityArray[i]);
			if (connectivity(mainGraph))
				counterConnectivity++;
		}
		myFileConnectivity << counterConnectivity << ",";
		ArrayEstimationOfProbability_Connectivity[i] = counterConnectivity; // save number of connected graphs into an array , for later use
	}
	myFileConnectivity << endl << "Estimation of probability,";
	for (i = 0; i < 10; i++) // Here we use the array , to calculate estimation of probability
	{
		myFileConnectivity << (ArrayEstimationOfProbability_Connectivity[i] / 500) << ",";
	}
	myFileConnectivity.close();

	// Attribute #2 - Diameter 
	cout << "\n|Diameter|" << endl;
	myFileDiameter.open("diameterFile.csv");
	if (!(myFileDiameter.is_open()))
	{
		cout << "myFileDiameter failed to open" << endl;
		exit(1);
	}
	myFileDiameter << "P,0.015,0.03,0.06,0.09,0.103 , 0.118 , 0.125, 0.139,0.159,0.175" << endl << "Amount of graphs with diameter 2 or smaller,";
	for (i = 0; i < 10; i++)
	{
		counterDiameter = 0;
		for (j = 0; j < 500; j++)
		{
			if (j % 100 == 0)
				cout << "Probability #" << i + 1 << ": [" << DiameterArray[i] << "]   Graph #" << j << endl;
			mainGraph = build_random_graph(1000, DiameterArray[i]);
			if (diameter(mainGraph) <= 2)
				counterDiameter++;
		}
		myFileDiameter << counterDiameter << ",";
		ArrayEstimationOfProbability_Diameter[i] = counterDiameter;
	}
	myFileDiameter << endl << "Estimation of probability,";
	for (i = 0; i < 10; i++)
	{
		myFileDiameter << (ArrayEstimationOfProbability_Diameter[i] / 500) << ",";
	}
	myFileDiameter.close();

	// Attribute #3 - Is Isolated 
	cout << "\n|Is Isolated|" << endl;
	myFileIsIsolated.open("isIsolatedFile.csv");
	if (!(myFileIsIsolated.is_open()))
	{
		cout << "myFileIsIsolated failed to open" << endl;
		exit(1);
	}
	myFileIsIsolated << "P,0.0009,0.0015,0.0028,0.0037,0.0053 , 0.00699 , 0.0079, 0.0084,0.0092,0.015" << endl << "Amount of graphs with isolated vertex,";
	for (i = 0; i < 10; i++)
	{
		counterIsIsolated = 0;
		for (j = 0; j < 500; j++)
		{
			if (j % 100 == 0)
				cout << "Probability #" << i + 1 << ": [" << isIsolatedArray[i] << "]   Graph #" << j << endl;
			mainGraph = build_random_graph(1000, isIsolatedArray[i]);
			if (Is_Isolated(mainGraph))
				counterIsIsolated++;
		}
		myFileIsIsolated << counterIsIsolated << ",";
		ArrayEstimationOfProbability_IsIsolated[i] = counterIsIsolated;
	}
	myFileIsIsolated << endl << "Estimation of probability,";
	for (i = 0; i < 10; i++)
	{
		myFileIsIsolated << (ArrayEstimationOfProbability_IsIsolated[i] / 500) << ",";
	}
	myFileIsIsolated.close();

	return 0;
}
