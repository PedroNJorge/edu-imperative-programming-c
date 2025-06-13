// --------------------------------------------------
// Programação Imperativa (CC1003) DCC-FCUP
// http://www.dcc.fc.up.pt/~fds/aulas/pi/2425/
// ---------------------------------------------------
// Singly Linked List -- F. Silva
// Last update: 19/5/2025
// ---------------------------------------------------

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

// NodeInfo can be a structured datatype
// but then we need to implement a function
// int compareTo(NodeInfo a, NodeInfo b) to compare structures

#define NodeInfo int 

// Define a node
typedef struct Node {
  NodeInfo      val; 
  struct Node *next;
} Node;

// Define the linked list
typedef struct {
    Node *first;
    int size;
} LinkedList;

// prototypes
Node *newNode(NodeInfo val, Node *next);  // create a new Node
void initList(LinkedList *list);          // initializes list as empty
bool isEmpty(LinkedList *);               // verifies if list is empty
int  size(LinkedList *);
void addFirst(LinkedList *, NodeInfo val); // add node with val in first position
void addLast(LinkedList *list, NodeInfo v);
bool addAt(LinkedList *list, int index, NodeInfo v);
bool removeFirst(LinkedList *list, NodeInfo *removedVal);
bool removeLast(LinkedList *list, NodeInfo *removedVal);
bool removeAt(LinkedList *list, int index, int *removedVal);
int  indexOf(LinkedList *list, NodeInfo v);
void printList(LinkedList *list);
void removeAll(NodeInfo , LinkedList *);
