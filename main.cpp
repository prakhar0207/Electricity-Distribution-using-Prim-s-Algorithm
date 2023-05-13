#include <iostream>
#include <climits>
#include <vector>
using namespace std;

void printMatrix(vector<vector<int>> adjMatrix)
{
    int n = adjMatrix.size();
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

int findMinVertex(bool *visited, int *weight, int nodes)
{
    int minVertex = -1;
    for(int i=0; i<nodes; i++)
    {
        if(!visited[i] && (minVertex==-1 || weight[i] < weight[minVertex]))
        {
            minVertex = i;
        }
    }
    return minVertex;
}


void primsAlgo(vector<vector<int>> adjMatrix, int nodes)
{
    int *parent = new int[nodes];
    bool *visited = new bool[nodes];
    int *weight = new int[nodes];
    for(int i=0; i<nodes; i++)
    {
        visited[i] = false;
        weight[i] = INT_MAX;
    }
    parent[0] = -1;
    weight[0] = 0;
    for(int i=0;i<nodes;i++)
    {
        //find min vertex
        int minVertex = findMinVertex(visited,weight,nodes);
        visited[minVertex] = true;
        //explore the unvisited neighbours of min vertex
        for(int j=0; j<nodes; j++)
        {
            if(adjMatrix[minVertex][j]!=0 && !visited[j])
            {
                if(adjMatrix[minVertex][j] < weight[j])
                {
                    weight[j] = adjMatrix[minVertex][j];
                    parent[j] = minVertex;
                }
            }
        }
    }
    int total_min_distance = 0;
    for(int i=1; i<nodes; i++)
    {
        if(parent[i] < i)
        {
            total_min_distance += weight[i];
            cout << parent[i] << " " << i << " " << weight[i] << endl;
        }
        else
        {
            total_min_distance += weight[i];
            cout << i << " " << parent[i] << " " << weight[i] << endl;
        }
    }
    cout << "\n\nTotal Minimum Distance taken is " << total_min_distance << endl;
}



int main() {
    int nodes, edges;
    cin >> nodes >> edges;
    vector<vector<int>> adjMatrix(nodes, vector<int>(nodes, 0));
    for(int i=0; i<edges; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adjMatrix[u][v] = w;
        adjMatrix[v][u] = w;
    }
    cout << "Adjacency Matrix of the given data will be : " << endl;
    printMatrix(adjMatrix);
    cout << "Traversal Graph of the given data will be : " << endl;
    primsAlgo(adjMatrix,nodes);
    return 0;
}