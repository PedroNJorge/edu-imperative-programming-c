#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 200
#define SKIPEOL {while (getchar()!='\n') ;}

typedef struct node {
    int index;
    char val;
} Node;

typedef struct stack {
    int top;
    Node* array[MAX];
} Stack;

void verify(char *line);
Node* pop(Stack* stack);
void push(Stack* stack, int index, char val);

int main() {	
    int ncases;
    char line[MAX];
    
    scanf("%d",&ncases);
    SKIPEOL;
    for (int c=0; c<ncases; c++) {
        fgets(line,sizeof(line),stdin);
        line[strcspn(line, "\n")] = '\0';
        verify(line);
    }
}

void verify(char* line) {
    Stack stack;
    stack.top = 0;

    int i = 0;
    while (line[i] != '\0') {
        if (line[i] == '(' || line[i] == '[') {
            push(&stack, i, line[i]);
        } else if (line[i] == ')' || line[i] == ']') {
            if (stack.top == 0) {
                printf("Erro na posicao %d\n", i);
                return;
            }
            Node* popped = pop(&stack);
            if ((line[i] == ')' && popped->val != '(') || (line[i] == ']' && popped->val != '[')) {
                printf("Erro na posicao %d\n", i);
                return;
            } else free(popped);
        }

        i++;
    }

    if (stack.top != 0) printf("Ficam parenteses por fechar\n");
    else printf("Expressao bem formada\n");
}

Node* pop(Stack* stack) {
    if (stack->top == 0) return NULL;
    return stack->array[--stack->top];
}
void push(Stack* stack, int index, char val) {
    Node* new_node = (Node *)malloc(sizeof(Node));
    new_node->index = index; new_node->val = val;
    stack->array[stack->top++] = new_node;
}
