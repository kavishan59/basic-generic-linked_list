
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>


//Structure for a generic node
typedef struct Node 
{
  void *data;
  struct Node *next;
} Node;


//Function prototypes


Node *createNode(void *data);
void appendNode(Node **head, void *data);
void printLint(Node *head, void (*printFunc)(void *));
void freeList(Node *head, void (*freeData)(void *));
Node *searchList(Node *head, void *key, int (*compareFunc)(void *, void *));
void deleteNode(Node **head, void *key, int (*compareFunc)(void *, void *), void (*freeData)(void *));
void deleteNodeAtIndex(Node **head, int index, void (*freeData)(void *));
int countNodes(Node *head);

#endif // !LINKED_LIST_H

