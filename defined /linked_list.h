#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

#define DATA_TYPE int  // Change this to float, char*, struct, etc.

typedef struct Node {
    DATA_TYPE data; 
    struct Node *next;
} Node;

// Function prototypes
Node *createNode(DATA_TYPE value);
void appendNode(Node **head, DATA_TYPE value);
void printList(Node *head, void (*printFunc)(DATA_TYPE));
void freeList(Node *head);
Node *searchList(Node *head, DATA_TYPE key, int (*compareFunc)(DATA_TYPE, DATA_TYPE));
void deleteNode(Node **head, DATA_TYPE key, int (*compareFunc)(DATA_TYPE, DATA_TYPE));
void deleteNodeAtIndex(Node **head, int index);
int countNodes(Node *head);

#endif // LINKED_LIST_H

