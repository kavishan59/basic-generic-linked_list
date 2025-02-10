
#include "linked_list.h"
#include <cstddef>
#include <cstdlib>
#include <stdlib.h>

Node *createNode(void *data)
{
  Node *newNode = malloc(sizeof(Node));
  if (!newNode)
    return (NULL);
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

//add a node at the end of the list
void appendNode(Node **head, void *data)
{
  Node *newNode = createNode(data);
  if (!newNode)
    return;
  if(*head == NULL)
  {
    *head = newNode;
    return;
  }

  Node *temp = *head;
  while (temp->next != NULL)
    temp = temp->next;

  temp->next = newNode;
}


void printLint(Node *head, void (*printFunc)(void *))
{
  Node *temp = head;
  while (temp != NULL)
  {
    printFunc(temp->data);
    temp = temp->next;
  }
}

// use NULL as freeData if using primitive type directly inside the node
void freeList(Node *head, void (*freeData)(void *))
{
  Node *temp;
  while (head != NULL)
  {
    temp = head;
    head = head->next;

    if(freeData)
      freeData(temp->data);
    free(temp);
  }
}

// search a Node for a value
Node *searchList(Node *head, void *key, int (*compareFunc)(void *, void *))
{
  while (head != NULL)
  {
    if (compareFunc(head->data,key) == 0)
      return head;
    head = head->next;
  }
  return NULL;
}

//delete a Node by value
void deleteNode(Node **head, void *key, int (*compareFunc)(void *, void *), void (*freeData)(void *))
{
  Node *temp = *head;
  Node *prev = NULL;

  while(temp != NULL)
  {
    if (compareFunc(temp->data, key) == 0)
    {
      if (prev)
        prev->next = temp->next;
      else
        *head = temp->next; //if it's the head node
      
      if (freeData)
        freeData(temp->data);
      free(temp);
      return ;
    }

    prev = temp;
    temp = temp->next;
  }
}

//delete a Node at specifix index
void deleteNodeAtIndex(Node **head, int index, void (*freeData)(void *))
{
  if (*head == NULL || index < 0)
    return ;

  Node *temp = *head, *prev = NULL;

  // if deleteing the head node
  if (index == 0)
  {
    *head = temp->next;
    if (freeData)
      freeData(temp->data);
    free(temp);
    return ;
  }

  for (int i = 0; temp != NULL && i < index; i++)
  {
    prev = temp;
    temp = temp->next;
  }

  if (temp == NULL)
    return ;

  prev->next = temp->next;

  if (freeData)
    free(temp->data);
  free(temp);
}


int countNodes(Node *head)
{
  int count = 0;
  while (head != NULL)
  {
    count++;
    head = head->next;
  }
  return count;
}
