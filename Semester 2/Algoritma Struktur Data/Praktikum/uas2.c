#include <stdio.h>
#include <limits.h>

#define V 6
#define INF INT_MAX

int minDistance(int dist[], int visited[]);
void printPath(int parent[], int j, char names[]);
void dijkstra(int graph[V][V], int src, int dst, char names[]);

int main()
{
    int graph[V][V] = {
        { 0, 1, 0, 2, 0, 0 }, 
        { 0, 0, 1, 4, 0, 0 }, 
        { 0, 0, 0, 0, 1, 2 }, 
        { 0, 0, 0, 0, 3, 0 }, 
        { 0, 0, 0, 0, 0, 1 }, 
        { 0, 0, 0, 0, 0, 0 }  
    };

    char names[V] = { 'S', 'A', 'B', 'C', 'D', 'E' };
    
    int src = 0;
    int dst = 4;
    
    dijkstra(graph, src, dst, names);

    return 0;
}

int minDistance(int dist[], int visited[])
{
    int min = INF;
    int min_index = -1;

    for (int v = 0; v < V; v++)
    {
        if (!visited[v] && dist[v] <= min)
        {
            min = dist[v];
            min_index = v;
        }
    }
    
    return min_index;
}

void printPath(int parent[], int j, char names[])
{
    if (parent[j] == -1)
    {
        printf("%c", names[j]);
        return;
    }
    
    printPath(parent, parent[j], names);
    printf(" -> %c", names[j]);
}

void dijkstra(int graph[V][V], int src, int dst, char names[])
{
    int dist[V];
    int visited[V];
    int parent[V];

    for (int i = 0; i < V; i++)
    {
        dist[i] = INF;
        visited[i] = 0;
        parent[i] = -1;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, visited);
        
        if (u == -1)
        {
            break;
        }
        
        visited[u] = 1;

        for (int v = 0; v < V; v++)
        {
            if (!visited[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    printf("jalur terpendek dari %c ke %c: ", names[src], names[dst]);
    printPath(parent, dst, names);
    printf("\ntotal beban minimum: %d\n", dist[dst]);
}