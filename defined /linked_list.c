#include "linked_list.h"

Node *createNode(DATA_TYPE value) {
    Node *newNode = malloc(sizeof(Node));
    if (!newNode) return NULL;
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Add a node at the end of the list
void appendNode(Node **head, DATA_TYPE value) {
    Node *newNode = createNode(value);
    if (!newNode) return;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Print the list using a function pointer for custom printing
void printList(Node *head, void (*printFunc)(DATA_TYPE)) {
    Node *temp = head;
    while (temp != NULL) {
        printFunc(temp->data);
        temp = temp->next;
    }
}

// Free the list 
void freeList(Node *head) {
    Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Search for a node by value
Node *searchList(Node *head, DATA_TYPE key, int (*compareFunc)(DATA_TYPE, DATA_TYPE)) {
    while (head != NULL) {
        if (compareFunc(head->data, key) == 0)
            return head;
        head = head->next;
    }
    return NULL;
}

// Delete a node by value
void deleteNode(Node **head, DATA_TYPE key, int (*compareFunc)(DATA_TYPE, DATA_TYPE)) {
    Node *temp = *head, *prev = NULL;

    while (temp != NULL) {
        if (compareFunc(temp->data, key) == 0) {
            if (prev)
                prev->next = temp->next;
            else
                *head = temp->next;

            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}

// Delete a node at a specific index
void deleteNodeAtIndex(Node **head, int index) {
    if (*head == NULL || index < 0) return;

    Node *temp = *head, *prev = NULL;

    if (index == 0) {  // If deleting the head
        *head = temp->next;
        free(temp);
        return;
    }

    for (int i = 0; temp != NULL && i < index; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return; 
    prev->next = temp->next;
    free(temp);
}

// Count the number of nodes in the list
int countNodes(Node *head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}


