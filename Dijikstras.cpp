#include <iostream>
#define MAX 999
using namespace std;
int V;
int graph[100][100];
int minDistance(int dist[], bool Set[])
{

	int min = MAX, min_index;

	for (int v = 0; v < V; v++)
		if (Set[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}
void displayMatrix(int V) {
   for(int i = 0; i < V; i++) {
      for(int j = 0; j < V; j++) {
         cout << graph[i][j] << "  ";
      }
      cout << endl;
   }
}

void printSolution(int dist[])
{
	cout << "Vertex \t Distance from Source" << endl;
	for (int i = 0; i < V; i++)
		cout << i << " \t\t\t\t" << dist[i] << endl;
}

void dijkstra(int graph[100][100], int src) //src = source = 0
{
	int dist[V]; //distance array of every vertex

	bool Set[V]; //array which shows whether the vertex is processed or not
	for (int i = 0; i < V; i++)
		dist[i] = MAX, Set[i] = false; //assigning initial distance to be infinity and false

	dist[src] = 0; //initil distance is 0 of source

	for (int count = 0; count < V - 1; count++) {

		int u = minDistance(dist, Set);//finding minimum distances of all nodes expect initial node, as its distance is 0

		Set[u] = true; // changing the vertex as a processed one


		for (int v = 0; v < V; v++)

			if (!Set[v] && graph[u][v] && dist[u] != MAX && dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v]; // graph lo unna distance kante manam update chesina distance + already unna distance less ayithe change cheyyali
	}

	printSolution(dist);
}

int main()
{

	int e;
	cout<<"enter no of vertices: ";
	cin>>V;
	cout<<"enter no of edges: ";
	cin>>e;
   for(int i=1;i<=e;i++)
    {
        int x,y,weight;
        cout<<"enter vertex 1 : ";
        cin>>x;
        cout<<"enetr vertex 2 : ";
        cin>>y;
        cout<<"enter weight: ";
        cin>>weight;
        graph[x][y]=weight;
    }
    displayMatrix(V);
	dijkstra(graph, 0);

	return 0;
}
