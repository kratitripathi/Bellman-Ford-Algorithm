//A C++ program to implement Bellman-ford shortest path algorithm
#include<iostream.h>
#include<conio.h>
#include<limits.h>//for INT_MAX
 
//A structure to represent a weighted edge in graph
struct Edge
{      int source, dest, weight;
};
 
//A structure to represent a connected, directed and weighted graph
struct Graph
{	 // V: Number of vertices, E: Number of edges
    int V, E;
    // The graph is represented as an array of edges
    struct Edge* edge;
};
 
//A function to create a graph with V vertices and E edges
struct Graph* createGraph(int V, int E)
{   struct Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge;
    return graph;
}
 
//A function to display the shortest distance to all nodes from the start node
void printsoln(int dist[], int n)
{
    cout<<"Vertex   Distance from Source\n";
    cout<<"--------------------------------\n";
    for (int i = 0; i < n; ++i)
        {cout<<i<<" \t\t "<<dist[i]<<"\n";}
}
 
//The function that implements Bellman-Ford algorithm.
void BellmanFord(struct Graph* graph, int src)
{   int V = graph->V;
    int E = graph->E;
    int dist[V]; 
//STEP 1: Initialize distances from source to all other vertices as INFINITE
    for (int i = 0; i < V; i++)
        dist[i]   = INT_MAX;
    dist[src] = 0;
//STEP 2: Relax all edges |V| - 1 times. A simple shortest path from source to any other vertex can have maximum |V| - 1 edges
    for (int i = 1; i <= V-1; i++)
    {   for (int j = 0; j < E; j++)
        {
            int u = graph->edge[j].source;
            int v = graph->edge[j].dest;
            int weight = graph->edge[j].weight;
            if (dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }
//STEP 3: Check for negative-weight cycles.  
    for (int i = 0; i < E; i++)
    {
        int u = graph->edge[i].source;
        int v = graph->edge[i].dest;
        int weight = graph->edge[i].weight;
        if (dist[u] + weight < dist[v])
            cout<<"\nGraph contains negative weight cycle\n";
    }
     printsoln(dist, V);
    return;
}

void main()//User interface
{
    cout<<"BELLMAN FORD SHORTEST PATH GRAPH ALGORITHM\n";
    int num,edges,source,dest,weight;
    cout<<"\nEnter the number of NODES in the graph: ";
    cin>>num;
    cout<<"\nEnter the number of EDGES in the graph: ";
    cin>>edges;
    struct Graph* graph = createGraph(num, edges);
    cout<<"\nEnter details of the edges: \n";
    for(int i=0;i<edges;i++)
    {       cout<<"\nEDGE "<<i+1;
            cout<<"\nSouce node: ";
            cin>>graph->edge[i].source;
            cout<<"Destination node: ";
            cin>>graph->edge[i].dest;
            cout<<"Weight: ";
            cin>>graph->edge[i].weight;
    }
    int s;
    cout<<"\nEnter the starting node: ";
    cin>>s;
    cout << "\n\nFollowing are shortest distances to all other nodes from source node "<<s<<": \n";
    BellmanFord(graph, s);
    getch();

}
