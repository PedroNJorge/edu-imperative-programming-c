#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 501

typedef struct patient {
    char name[MAX_LEN];
    char priority;
} Patient;

typedef struct node {
    Patient* value;
    struct node* next;
} Node;

typedef struct queue {
    Node* head;
    Node* tail;
} Queue;

void init_queues(Queue* A, Queue* B, Queue* C);
void add_to_queue(Queue* queue, Patient* new_patient);
Patient* remove_patient(Queue* queue);
Patient* call_patient(Queue* A, Queue* B, Queue* C);

int main() {
    int n;
    scanf("%d", &n);
    getchar();

    Queue A_queue, B_queue, C_queue;
    init_queues(&A_queue, &B_queue, &C_queue);

    int event;
    for (int i = 0; i < n; i++) {
        scanf("%d", &event);
        getchar();
        if (event == 0) {
            Patient* new_patient = (Patient *)malloc(sizeof(Patient));

            fgets(new_patient->name, MAX_LEN, stdin);
            new_patient->name[strcspn(new_patient->name, "\n")] = '\0';

            new_patient->priority = getchar();
            getchar();

            switch (new_patient->priority) {
                case 'A':
                    add_to_queue(&A_queue, new_patient);
                    break;
                case 'B':
                    add_to_queue(&B_queue, new_patient);
                    break;
                case 'C':
                    add_to_queue(&C_queue, new_patient);
                    break;
            }
        } else {
            Patient* called_patient = call_patient(&A_queue, &B_queue, &C_queue); 
            if (called_patient != NULL) {
                printf("%s\n", called_patient->name);
                free(called_patient);
            }
        }
    }

    return 0;
}

void init_queues(Queue* A, Queue* B, Queue* C) {
    A->head = NULL; A->tail = NULL;
    B->head = NULL; B->tail = NULL;
    C->head = NULL; C->tail = NULL;
}

void add_to_queue(Queue* queue, Patient* new_patient) {
    Node* new_node = (Node *)malloc(sizeof(Node));
    new_node->value = new_patient;
    new_node->next = NULL;

    if (queue->head == NULL) {
        queue->head = queue->tail = new_node;
    }
    else {
        queue->tail->next = new_node;
        queue->tail = new_node;
    }
}

Patient* remove_patient(Queue* queue) {
    if (queue->head == NULL) return NULL;

    Node* old_head = queue->head;
    Patient* patient = old_head->value;
    queue->head = old_head->next;
    free(old_head);

    return patient;
}

Patient* call_patient(Queue* A, Queue* B, Queue* C) {
    if (A->head != NULL) return remove_patient(A);
    else if (B->head != NULL) return remove_patient(B);
    else if (C->head != NULL) return remove_patient(C);

    return NULL;
}
