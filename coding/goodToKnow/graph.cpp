/*
In graph theory, a graph consists of vertices (also called nodes or points), which are connected by edges (also called arcs, links, or lines). Edges can be directed (having a specific direction) or undirected (no specific direction). 

Degree of a Vertex − The degree of a vertex V of a graph G (denoted by deg (V)) is the number of edges incident with the vertex V.

Even and Odd Vertex − If the degree of a vertex is even, the vertex is called an even vertex and if the degree of a vertex is odd, the vertex is called an odd vertex.

Degree of a Graph − The degree of a graph is the largest vertex degree of that graph. For the above graph the degree of the graph is 3.

The Handshaking Lemma − In a graph, the sum of all the degrees of all the vertices is equal to twice the number of edges. For example, in above case, sum of all the degrees of all vertices is 8 and total edges are 4.

A bipartite graph is a graph in which if the graph coloring is possible using two colors i.e; vertices in a set are colored with the same color.


given as edges  - convert to adjacent list..
given as matrix
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/* traverse using dfs */
void dfs(int start_vertex, vector<vector<int>>& adj_list, vector<bool>& visited) {
    stack<int> stack;
    stack.push(start_vertex);
    visited[start_vertex] = true;

    while (!stack.empty()) {
        int current_vertex = stack.top();
        stack.pop();
        cout << current_vertex << " ";

        for (int neighbor : adj_list[current_vertex]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                stack.push(neighbor);
            }
        }
    }
}

void bfs(int start_vertex, vector<vector<int>>& adj_list, vector<bool>& visited) {
    queue<int> queue;
    queue.push(start_vertex);
    visited[start_vertex] = true;

    while (!queue.empty()) {
        int current_vertex = queue.front();
        queue.pop();
        cout << current_vertex << " ";

        for (int neighbor : adj_list[current_vertex]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                queue.push(neighbor);
            }
        }
    }
}

int dfs(int node, int parent, const vector<vector<int>>& adj, int& diameter) {
    int max_depth1 = 0, max_depth2 = 0;
    for (int child : adj[node]) {
        if (child != parent) {
            int current_depth = dfs(child, node, adj, diameter) + 1;
            if (current_depth > max_depth1) {
                max_depth2 = max_depth1;
                max_depth1 = current_depth;
            } else if (current_depth > max_depth2) {
                max_depth2 = current_depth;
            }
        }
    }
    diameter = max(diameter, max_depth1 + max_depth2);
    return max_depth1;
}

int treeDiameter(int n, const vector<vector<int>>& edges) {
	
	//convert edges to adj list
    vector<vector<int>> adj(n);
    for (const auto& edge : edges) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }

    int diameter = 0;
    dfs(0, -1, adj, diameter);
    return diameter;
}


int main() {
    int num_vertices = 6;
    vector<vector<int>> adj_list(num_vertices);
    adj_list[0] = {1, 2};
    adj_list[1] = {0, 3, 4};
    adj_list[2] = {0, 5};
    adj_list[3] = {1};
    adj_list[4] = {1};
    adj_list[5] = {2};

    vector<bool> visited(num_vertices, false);
    cout << "DFS traversal starting from vertex 0: ";
    dfs(0, adj_list, visited);
    cout << endl;
	
	vector<bool> visited_bfs(num_vertices, false);
    cout << "BFS traversal starting from vertex 0: ";
    bfs(0, adj_list, visited_bfs);
    cout << endl;
	
	int G[][V] = {{ 0, 1, 0, 0},
                { 1, 0, 0, 0},
                { 0, 0, 0, 1},
                { 1, 0, 1, 0}};
				
				
	
    return 0;
}