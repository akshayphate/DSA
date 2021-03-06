#include <stdio.h>
#include "../data_structures/Queue.h"
#include "../data_structures/AdjListGraph.h"

void BFS(AdjListGraph* G, int src) {
    for (int i = 1; i <= G->V; i++) {
        if (src != i) {
            G->vertices[i]->colour = WHITE;
            G->vertices[i]->distance = INFINITY;
            G->vertices[i]->parent = NIL;
        }
    }

    G->vertices[src]->colour = GREY;
    G->vertices[src]->distance = 0;
    G->vertices[src]->parent = NIL;

    Queue* Q = createQueue();
    enque(src, Q);
    int vertex;

    while (!isEmpty(Q)) {
        vertex = dequeue(Q);
        Vertex* v = G->vertices[vertex];
        Node* current = v->list->head;
        while (1) {
            if (current == NULL)
                break;
            int neighbour = current->data;
            Vertex* neighbourVertex = G->vertices[neighbour];
            if (neighbourVertex->colour == WHITE) {
                neighbourVertex->colour = GREY;
                neighbourVertex->distance = v->distance + 1;
                neighbourVertex->parent = vertex;
                enque(neighbour, Q);
            }
            current = current->next;
        }
        v->colour = BLACK;
    }

    for (int i = 1; i <= G->V; i++) {
        printf("\nVertex %d : Distace %d", i, G->vertices[i]->distance);
    }
    printf("\n");
}

int main(){

    AdjListGraph* G = getRandomGraph1();
    int source = 1;

    BFS(G, source);
    
    return 0;
}
