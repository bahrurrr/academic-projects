#include <stdio.h>
#include <stdlib.h>

#define max 6
#define inf 99999

typedef struct {
    int data[100];
    int top;
} stack;

void initstack(stack *s);
void push(stack *s, int value);
int pop(stack *s);
int getmindist(int dist[], int visited[]);
void dijkstra(int graph[max][max], int src, int dest);
void warshall(int graph[max][max], int src, int dest);

int main() {
    int graph[max][max] = {
        {0, 4, 3, inf, inf, inf},
        {inf, 0, 5, 2, inf, inf},
        {inf, inf, 0, 7, inf, inf},
        {inf, inf, inf, 0, 2, inf},
        {4, 4, inf, inf, 0, 6},
        {inf, inf, inf, inf, inf, 0}
    };
    
    int start = 0;
    int end = 5;
    
    printf("praktikum graph & shortest path\n");
    printf("node asal (input)  : %d\n", start);
    printf("node tujuan (input): %d\n", end);
    
    dijkstra(graph, start, end);
    warshall(graph, start, end);
    
    return 0;
}

void initstack(stack *s) {
    s->top = -1;
}

void push(stack *s, int value) {
    s->data[++(s->top)] = value;
}

int pop(stack *s) {
    if (s->top == -1) return -1;
    return s->data[(s->top)--];
}

int getmindist(int dist[], int visited[]) {
    int min = inf, min_idx = -1;
    for (int v = 0; v < max; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_idx = v;
        }
    }
    return min_idx;
}

void dijkstra(int graph[max][max], int src, int dest) {
    int dist[max], visited[max], parent[max];
    
    for (int i = 0; i < max; i++) {
        dist[i] = inf;
        visited[i] = 0;
        parent[i] = -1;
    }
    
    dist[src] = 0;
    
    for (int count = 0; count < max - 1; count++) {
        int u = getmindist(dist, visited);
        if (u == -1 || u == inf) break;
        
        visited[u] = 1;
        
        for (int v = 0; v < max; v++) {
            if (!visited[v] && graph[u][v] != inf && dist[u] != inf && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }
    
    printf("\nalgoritma dijkstra\n");
    if (dist[dest] == inf) {
        printf("tidak ada rute dari %d ke %d\n", src, dest);
        return;
    }
    
    printf("beban minimal : %d\n", dist[dest]);
    
    stack s;
    initstack(&s);
    int curr = dest;
    while (curr != -1) {
        push(&s, curr);
        curr = parent[curr];
    }
    
    printf("urutan rute   : ");
    while (s.top != -1) {
        printf("%d", pop(&s));
        if (s.top != -1) printf(" -> ");
    }
    printf("\n");
}

void warshall(int graph[max][max], int src, int dest) {
    int dist[max][max];
    int next[max][max];
    
    for (int i = 0; i < max; i++) {
        for (int j = 0; j < max; j++) {
            dist[i][j] = graph[i][j];
            if (graph[i][j] != inf && i != j) {
                next[i][j] = j;
            } else {
                next[i][j] = -1;
            }
        }
    }
    
    for (int k = 0; k < max; k++) {
        for (int i = 0; i < max; i++) {
            for (int j = 0; j < max; j++) {
                if (dist[i][k] != inf && dist[k][j] != inf && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    next[i][j] = next[i][k];
                }
            }
        }
    }
    
    printf("\nalgoritma floyd-warshall\n");
    if (dist[src][dest] == inf) {
        printf("tidak ada rute dari %d ke %d\n", src, dest);
        return;
    }
    
    printf("beban minimal : %d\n", dist[src][dest]);
    
    int temppath[max];
    int count = 0;
    int curr = src;
    
    while (curr != dest) {
        temppath[count++] = curr;
        curr = next[curr][dest];
        if (curr == -1) break;
    }
    temppath[count++] = dest;
    
    stack s;
    initstack(&s);
    for (int i = count - 1; i >= 0; i--) {
        push(&s, temppath[i]);
    }
    
    printf("urutan rute   : ");
    while (s.top != -1) {
        printf("%d", pop(&s));
        if (s.top != -1) printf(" -> ");
    }
    printf("\n");
}