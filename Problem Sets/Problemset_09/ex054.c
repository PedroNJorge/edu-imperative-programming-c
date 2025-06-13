#include "linkedList.h"

void removeAll(NodeInfo x, LinkedList *l) {
    if (!l || !l->first) return;  // Handle empty list

    Node **current = &(l->first);  // Pointer-to-pointer to update links
    while (*current != NULL) {
        if ((*current)->val == x) {
            Node *toRemove = *current;
            *current = (*current)->next;  // Bypass the node to remove
            free(toRemove);  // Free memory (if needed)
            l->size--;       // Update size
        } else {
            current = &((*current)->next);  // Move to next node
        }
    }
}
