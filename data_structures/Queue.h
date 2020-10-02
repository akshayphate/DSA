#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#define EMPTY 1
#define NOTEMPTY 0


typedef struct Queue {
    LinkedList* list;
} Queue;

Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->list = createLinkedList();

    return queue;
}


int enque(int data, Queue* q) {
    addToList(data, q->list);
    return data;
}

int dequeue(Queue* q) {
    return removeFirst(q->list);
}

void printQueue(Queue* q) {
    printList(q->list);
}

int isEmpty(Queue* q) {
    if (q->list->head == NULL) 
        return EMPTY;
    else
        return NOTEMPTY;
}