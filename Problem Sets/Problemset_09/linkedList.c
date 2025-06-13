// --------------------------------------------------
// ProgramaÃ§Ã£o Imperativa (CC1003) DCC-FCUP
// http://www.dcc.fc.up.pt/~fds/aulas/pi/2425/
// ---------------------------------------------------
// Singly Linked List -- F. Silva
// Last update: 19/5/2025
// -------------------------------------------------------------

#include "linkedList.h"

// initializes a new node
Node *newNode(NodeInfo val, Node *next) {
  Node *nnode= malloc(sizeof(Node)); // alocate memory for new node
  nnode->val= val;
  nnode->next= next;
  return nnode;
}
// inititialize the list as empty
void initList(LinkedList *list) {
  list->size= 0;
  list->first= NULL;
}
// verify if list is empty
bool isEmpty(LinkedList *list) {
  return (list->size == 0); // or first 00 null
}
//
int size(LinkedList *l) {
  return l->size;
}
// add in first position
void addFirst(LinkedList *list, NodeInfo v) {
  // create new node point to same node as pointed by list->first
  Node *nnode= newNode(v, list->first);
  // make list->first point to new node
  list->first= nnode;
  list->size++;
}
// remove first node from list
bool removeFirst(LinkedList *list, NodeInfo *removedVal) {
  if (isEmpty(list))
    return false;
  Node *tmp= list->first;
  *removedVal= tmp->val;
  list->first= tmp->next;
  free(tmp);
  list->size--;
  return true;
}

// add new node at the end of the list
void addLast(LinkedList *list, NodeInfo v) {
  Node *nnode = newNode(v, NULL);

  if (isEmpty(list)) {
    // if list is empty, nnode becomes the first
    list->first = nnode;
  } else {
    // traverse the list until pointing to last node
    Node *curr = list->first;
    while (curr->next != NULL) {
      curr = curr->next;
    }
    // make next pointer of last node to point to new node
    curr->next = nnode;
  }
  list->size++;
}

// remove the last node in the list
// we have to
//  - verify if list has just 1 node, then it becomes empty
//  - traverse the list until the node before last, and
//    then adjust the next pointer to point to null
bool removeLast(LinkedList *list, NodeInfo *removedVal) {
  if (list->first == NULL)
    return false;

  Node *curr = list->first; // current starts at first node
  // if only 1 node, the list becomes empty
  if (curr->next == NULL) {
    *removedVal = curr->val;
    free(curr);
    list->first = NULL;
    list->size--;
    return true;
  }
  // Traverse to the second-to-last node
  while (curr->next->next != NULL) {
    curr = curr->next;
  }
  *removedVal = curr->next->val;
  free(curr->next);
  curr->next = NULL;
  list->size--;
  return true;
  /* em alternativa:
  Node *prev= curr;
  while (curr->next != NULL) {
    prev= curr;
    current = curr->next;
  }
  *removedVal = curr->val;
  free(curr);
  prev->next = NULL;
  list->size--;
  */
}

// returns the position (index) of the first node with the value v.
// returns -1 if not found.
int indexOf(LinkedList *list, NodeInfo v) {
  Node *curr = list->first;
  int index = 0;

  while (curr != NULL && curr->val != v) {
    curr = curr->next;
    index++;
  }
  return (curr->val == v) ? index : -1;
  // returns -1 if not found
}

// inserts a new node with val v at a given index (0-based).
// returns true on success, false if the index is invalid.
bool addAt(LinkedList *list, int index, NodeInfo v) {
  if (index < 0 || index > list->size)
    return false;
    
  if (index == 0) {
    addFirst(list, v);
    return true;
  }
  Node *nnode = newNode(v,NULL);   
  Node *curr = list->first;
  for (int i = 0; i < index - 1; i++) {
    curr = curr->next;
  }
  nnode->next = curr->next;
  curr->next  = nnode;
  list->size++;
  return true;
}

// remove the node at position index and
// store the removed value in removedVal.
// return true on success, false if the index is invalid.
bool removeAt(LinkedList *list, int index, int *removedVal) {
  if (index < 0 || index >= list->size)
    return false;

  if (index == 0) {
    return removeFirst(list, removedVal);
  }

  Node *curr = list->first;
  for (int i = 0; i < index - 1; i++) {
    curr = curr->next;
  }
  Node *tmp = curr->next;
  *removedVal = tmp->val;
  curr->next = tmp->next;
  free(tmp);
  list->size--;
  return true;
}

void printList(LinkedList *list) {
  Node *curr= list->first;

  while (curr != NULL) {
    printf("%d",curr->val);
    curr= curr->next;
    printf("%c"," \n"[curr==NULL]);
  }
}
