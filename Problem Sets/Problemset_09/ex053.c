#include "linkedList.h"

void duplicate(LinkedList *l) {
    int len = l->size;
    Node* current = l->first;

    for (int i = 0; i < 2*len; i += 2) {
        addAt(l, i, current->val);
        current = current->next;
    }
}
