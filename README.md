# Bellman-Ford-Algorithm
Data Structures and Algorithms Project on Bellman Ford Algorithm

**Bellman-Ford Algorithm:**

**Input:** Graph and a source vertex  
**Output:** Shortest distance to all vertices from source. If there is a negative weight cycle, then shortest distances are not calculated, negative weight cycle is reported.  
1. Initialize distances from source to all vertices as infinite and distance to source itself as 0.   
2. Create an array dist[] of size |V| with all values as infinite except dist[source] where source is the starting vertex.  
3. Calculate shortest distances. Repeat the following steps |V|-1 times (where |V| is the number of vertices in given graph)    
	  a) Repeat the following for each edge u->v    
		  If dist[v] > dist[u] + weight of edge u->v, then update dist[v]    
		  dist[v] = dist[u] + weight of edge u->v     
4. Reports if there is a negative weight cycle in the graph. Repeat the following for each edge u->v    
	  a)	If dist[v] > dist[u] + weight of edge uv, then print “Graph contains negative weight cycle”    
