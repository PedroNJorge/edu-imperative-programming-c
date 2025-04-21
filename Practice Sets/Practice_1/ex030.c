#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX_WORD_LEN 81

typedef struct Candidato {
    int BI;
    char nome[MAX_WORD_LEN];
    char escola[MAX_WORD_LEN];
    int escola_code;
    int nota;
} Candidato;

typedef struct node_candidato {
    Candidato* candidato;
    struct node_candidato* next;
} node_candidato;

typedef struct Escola {
    char nome[MAX_WORD_LEN];
    int code;
    int num_candidatos;
    int soma_notas;
    float media;
    node_candidato* ll_candidatos_head;
} Escola;

typedef struct node_escola {
    Escola* escola;
    struct node_escola* next;
} node_escola;

node_candidato* add_candidato(node_candidato** ll_candidatos, Candidato* new_candidato) {
    node_candidato* new_node = (node_candidato *)malloc(sizeof(node_candidato));
    new_node->candidato = new_candidato;
    new_node->next = *ll_candidatos;
     
    return new_node;
}


Escola* find_or_create_escola(node_escola** ll_escolas, Candidato* candidato) {
    node_escola* temp = *ll_escolas;

    while (temp != NULL) {
        if (strcmp(temp->escola->nome, candidato->escola) == 0 && temp->escola->code == candidato->escola_code) {
            temp->escola->num_candidatos++;
            temp->escola->soma_notas += candidato->nota;
            temp->escola->media = round(temp->escola->soma_notas*1.0 / temp->escola->num_candidatos);
            temp->escola->ll_candidatos_head = add_candidato(&temp->escola->ll_candidatos_head, candidato);
            return NULL;
        }

        temp = temp->next;
    }

    Escola* new_escola = (Escola *)malloc(sizeof(Escola));
    strcpy(new_escola->nome, candidato->escola);
    new_escola->code = candidato->escola_code;
    new_escola->num_candidatos = 1;
    new_escola->media = new_escola->soma_notas = candidato->nota;

    return new_escola;
}

node_escola* add_escola(node_escola** ll_escolas, Escola* new_escola) {
    node_escola* new_node = (node_escola *)malloc(sizeof(node_escola));
    new_node->escola = new_escola;
    new_node->next = *ll_escolas;
     
    return new_node;
}

int compare_candidatos_nota(const void* a, const void* b) {
    return -(((Candidato *)a)->nota - ((Candidato *)b)->nota );
}

void bubble_sort(node_escola** ll_escolas) {
    bool swapped = false;
    node_escola* i_ptr = *ll_escolas;
    node_escola* end_ptr = NULL;


    do {
        swapped = false;

        while (i_ptr->next != end_ptr) {
            if (i_ptr->escola->media < i_ptr->next->escola->media) {
                // swap the two nodes
                node_escola* temp = i_ptr->next;
                i_ptr->next = temp->next;
                temp->next = i_ptr;
                
                // update prev node next address
                if (i_ptr == *ll_escolas) {
                    *ll_escolas = temp;
                } else {
                    node_escola* prev = *ll_escolas;

                    while (prev-> next != i_ptr) {
                        prev = prev->next;
                    }

                    prev->next = temp;
                }

                swapped = true;
                // go back one because of i_ptr while loop update
                i_ptr = temp;
            }
            
            i_ptr = i_ptr->next;
        }

        end_ptr = i_ptr;
        i_ptr = *ll_escolas;
    } while (swapped);
}

int main() {
    int n, flag;
    scanf("%d %d", &n, &flag);
    getchar();

    node_escola* ll_escolas = NULL;

    Candidato array_candidatos[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &array_candidatos[i].BI);
        getchar();

        fgets(array_candidatos[i].nome, MAX_WORD_LEN, stdin);
        array_candidatos[i].nome[strcspn(array_candidatos[i].nome, "\n")] = '\0';

        fgets(array_candidatos[i].escola, MAX_WORD_LEN, stdin);
        array_candidatos[i].escola[strcspn(array_candidatos[i].escola, "\n")] = '\0';

        scanf("%d", &array_candidatos[i].escola_code);
        getchar();

        scanf("%d", &array_candidatos[i].nota);
        getchar();


        Escola* new_escola = find_or_create_escola(&ll_escolas, &array_candidatos[i]);

        if (new_escola != NULL) {
            ll_escolas = add_escola(&ll_escolas, new_escola);
        }
    }

    if (flag == 0) {
        node_escola* temp = ll_escolas;
        int num_escolas = 0;
        while (temp != NULL) {
            num_escolas++;
            temp = temp->next;
        }
        printf("%d\n", num_escolas);
    } else if (flag == 1) {
        qsort(array_candidatos, n, sizeof(Candidato), compare_candidatos_nota);

        int max_nota = array_candidatos[0].nota;
        int temp_nota = max_nota;
        int i = 0;

        printf("%d\n", max_nota);
        while (temp_nota == max_nota && i < n) {
            printf("%s\n", array_candidatos[i].nome);
            temp_nota = array_candidatos[++i].nota;
        }
    } else if (flag == 2) {
        bubble_sort(&ll_escolas);

        node_escola* temp = ll_escolas;

        while (temp != NULL) {
            printf("%s %d %.0f\n", temp->escola->nome, temp->escola->num_candidatos, temp->escola->media);

            temp = temp->next;
        }
    }

    return 0;
}
