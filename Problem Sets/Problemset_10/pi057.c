#include "queue.h"
#include <string.h>

void process(Queue* q, Queue* a, Queue* b) {
    while (!isEmpty(q)) {
        Node* cur = q->first;
        char* str = cur->val;
	char* D = cur->next->val;

	if (strcmp(D, "A") == 0) {
                addLast(a, str);
                removeFirst(q);
	}
        else if (strcmp(D, "B") == 0) {
                addLast(b, str);
                removeFirst(q);
	}
	else {
                if (a->size < b->size) {
                    addLast(a, str);
                    removeFirst(q);
                } else if (b->size < a->size) {
                    addLast(b, str);
                    removeFirst(q);
                } else removeFirst(q);
        }
        removeFirst(q);
    }
}
