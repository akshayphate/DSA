#include <stdlib.h>
#include "LinkedList.h"
#define WHITE 2
#define GREY  1
#define BLACK 0
#define INFINITY -99999999
#define NIL      -88888888

#ifndef ADJLISTGRAPH_H
#define ADJLISTGRAPH_H

typedef struct graph_vertex {
    int vertexNumber;
    int colour;
    int distance;
    int parent;
    LinkedList* list;

} Vertex;

typedef struct Graph {
    int V;
    Vertex** vertices;

} AdjListGraph;

AdjListGraph* createGraph(int V) {
    AdjListGraph* graph = (AdjListGraph*)malloc(sizeof(AdjListGraph));
    graph->V = V;
    graph->vertices = (Vertex**)malloc((V+1) * sizeof(Vertex*));

    for (int i = 1; i <= V; i++) {
        graph->vertices[i] = (Vertex*)malloc(sizeof(Vertex));
        graph->vertices[i]->vertexNumber = i;
        graph->vertices[i]->list = createLinkedList();
    }

    return graph;
}

void addEdge(AdjListGraph* g, int src, int dest) {
    addToList(dest, g->vertices[src]->list);
    addToList(src, g->vertices[dest]->list);
}

void printGraph(AdjListGraph* graph) {
    for (int i = 1; i <= graph->V; i++) {
        printf("Vertex %d : ", i);
        printList(graph->vertices[i]->list);
        printf("\n");
    }
}

AdjListGraph* getRandomGraph1() {
    AdjListGraph* graph = createGraph(8);

    addEdge(graph, 1, 2);
    addEdge(graph, 1, 5);
    addEdge(graph, 2, 6);
    addEdge(graph, 3, 4);
    addEdge(graph, 3, 6);
    addEdge(graph, 3, 7);
    addEdge(graph, 6, 7);
    addEdge(graph, 4, 7);
    addEdge(graph, 4, 8);
    addEdge(graph, 7, 8);

    return graph;
}

#endif