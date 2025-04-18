#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define MAX_WORD_LEN 101

typedef struct Candidato {
    unsigned int BI;
    char nome[MAX_WORD_LEN];
    char primeira_op[MAX_WORD_LEN];
    unsigned int code;
    unsigned int nota;
} Candidato;

typedef struct node_candidato {
    Candidato* value;
    struct node_candidato* next;
} node_candidato;

typedef struct Escola {
    char nome[MAX_WORD_LEN];
    unsigned int code;
    node_candidato* candidatos;      // head
    unsigned int num_candidatos;
    unsigned int sum_notas;
} Escola;

typedef struct node_escola {
    Escola* value;
    struct node_escola* next;
} node_escola;

node_candidato* create_candidate_node(Candidato* cand) {
    node_candidato* new_node = (node_candidato*)malloc(sizeof(node_candidato));
    new_node->value = cand;
    new_node->next = NULL;
    return new_node;
}

void add_candidate_to_school(Escola* escola, Candidato* cand) {
    node_candidato* new_node = create_candidate_node(cand);
    new_node->next = escola->candidatos;
    escola->candidatos = new_node;
    escola->num_candidatos++;
    escola->sum_notas += cand->nota;
}

Escola* find_or_create_school(node_escola** head, const char* nome, unsigned int code) {
    node_escola* current = *head;
    
    // Search for existing school
    while (current != NULL) {
        if (strcmp(current->value->nome, nome) == 0 && current->value->code == code) {
            return current->value;
        }
        current = current->next;
    }
    
    // Create new school if not found
    Escola* new_escola = (Escola*)malloc(sizeof(Escola));
    strcpy(new_escola->nome, nome);
    new_escola->code = code;
    new_escola->candidatos = NULL;
    new_escola->num_candidatos = 0;
    new_escola->sum_notas = 0;
    
    // Add to schools list
    node_escola* new_node = (node_escola*)malloc(sizeof(node_escola));
    new_node->value = new_escola;
    new_node->next = *head;
    *head = new_node;
    
    return new_escola;
}

int compare_candidate(const void* a, const void* b) {
    return -(((Candidato *)a)->nota - ((Candidato *)b)->nota);
}

void insertionSort(node_escola* escola) {
     
}

int main() {
    int n, flag;
    scanf("%d %d", &n, &flag);
    getchar();

    Candidato candidatos[n];
    node_escola* escolas = NULL;  // Head of schools list

    for (int i = 0; i < n; i++) {
        scanf("%d", &candidatos[i].BI);
        getchar();

        fgets(candidatos[i].nome, MAX_WORD_LEN, stdin);
        candidatos[i].nome[strcspn(candidatos[i].nome, "\n")] = '\0';

        fgets(candidatos[i].primeira_op, MAX_WORD_LEN, stdin);
        candidatos[i].primeira_op[strcspn(candidatos[i].primeira_op, "\n")] = '\0';

        scanf("%d", &candidatos[i].code);
        getchar();

        scanf("%d", &candidatos[i].nota);
        getchar();
        
        // Add candidate to their school's list
        Escola* escola = find_or_create_school(&escolas, candidatos[i].primeira_op, candidatos[i].code);
        add_candidate_to_school(escola, &candidatos[i]);
    }

    if (flag == 0) {
        node_escola* current = escolas;
        int num_schools = 0;
    
        while (current != NULL) {
            num_schools++;
            current = current->next;
        }
        printf("%d\n", num_schools);
    }
    else if (flag == 1) {
        qsort(candidatos, n, sizeof(Candidato), compare_candidate);
        int max_nota = candidatos[0].nota;
        int i = 0;

        printf("%d\n", max_nota);
        while (candidatos[i].nota == max_nota) {
            printf("%s\n", candidatos[i++].nome);
        }
    }
    else if (flag == 2) {
        insertionSort(escolas);
        node_escola* current = escolas;

        while (current != NULL) {
            printf("%s", current->value->nome);
            printf(" %u", current->value->num_candidatos);
            printf(" %.0f\n", round(current->value->sum_notas*1.0 / current->value->num_candidatos));
            current = current->next;
        }
    }

    return 0;
}
