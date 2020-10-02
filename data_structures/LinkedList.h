#include <stdio.h>
#include <stdlib.h>
#define EMPTYLIST -99999999

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct Node{
    int data;
    struct Node* next;
}Node;

typedef struct LinkedList {
    Node* head;
    Node* tail;
}LinkedList;

LinkedList* createLinkedList() {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    list->head = NULL;
    list->tail = NULL;

    return list;
}

Node* createNewNode(int data) {
    Node* temp = (Node*)malloc(sizeof(Node)); 
    temp->data = data;

    return temp;
}

void addToList(int data, LinkedList* list) {
    Node* newNode = createNewNode(data);
    newNode->next = NULL;

    if (list->head == NULL) list->head = newNode;
    else if (list->head->next == NULL) list->head->next = newNode;          
    else list->tail->next = newNode;   
    
    list->tail = newNode;
}

void emptyTheList(LinkedList* list) {
    free(list->head);
    list->head = NULL;
    list->tail = NULL;
}

int removeLast(LinkedList* list) {
    if (list->head == NULL) {
        return EMPTYLIST;
    }

    if (list->head->next == NULL) {
        emptyTheList(list);
    }
    else 
    if (list->head->next == list->tail) {
        list->head->next = NULL;
        free(list->tail);
        list->tail = list->head;
    }
    else {
        Node* current = list->head;
        while (current->next != list->tail) 
            current = current->next;
        free(list->tail);
        list->tail = current;
        current->next = NULL;
    }
}

int removeFirst(LinkedList* list) {
    if (list->head == NULL) {
        printf("\nList is empty\n");
        return EMPTYLIST;
    }

    int val = list->head->data;

    if (list->head->next == NULL) 
        emptyTheList(list);
    else 
    if (list->head->next == list->tail) {
        free(list->head);
        list->head = list->tail;
    }
    else {
        Node* current = list->head->next;
        free(list->head);
        list->head = current;
    }

    return val;
}


void printList(LinkedList* list) {
    if (list->head != NULL) {
        Node* current = list->head;
        while (current != NULL) {
            printf("%d -> ", current->data);
            current = current->next;
        }
        printf("NULL\n");
        
    }
    
}

#endif