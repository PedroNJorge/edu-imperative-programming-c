#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LEN 10001

typedef struct stack {
    int top;
    int array[MAX_LEN];
} Stack;

int pop(Stack* stack);
void push(Stack* stack, int n);
void PDA(char expression[]);

int main() {
    int n;
    scanf("%d", &n); getchar();

    char expression[MAX_LEN];
    for (int i = 0; i < n; i++) {
        fgets(expression, MAX_LEN, stdin);
        expression[strcspn(expression, "\n")] = '\0';

        PDA(expression);
    }

    return 0;
}

int pop(Stack* stack) {
    if (stack->top == 0) return -1;
    else return stack->array[--stack->top];
}

void push(Stack* stack, int n) {
    stack->array[stack->top++] = n;
}

void PDA(char expression[]) {
    Stack stack;
    stack.top = 0;

    int i = 0;
    while (expression[i] != '\0') {
        if (expression[i] == ' ') {
            i++;
            continue;
        } else if (isdigit(expression[i])) {
            int num = 0;
            while (isdigit(expression[i])) {
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            push(&stack, num);
        } else {
            int a = pop(&stack);
            int b = pop(&stack);
            if (a == -1 || b == -1) {
                printf("Expressao Incorreta\n");
                return;
            }

            int result;
            switch (expression[i]) {
                case '+':
                    result = b + a;
                    break;
                case '-':
                    result = b - a;
                    break;
                case '*':
                    result = b * a;
                    break;
                case '/':
                    if (a == 0) {
                        printf("Expressao Incorreta\n");
                        return;
                    }
                    result = b / a;
                    break;
            }

            push(&stack, result);
        }
        i++;
    }

    if (stack.top != 1) printf("Expressao Incorreta\n");
    else printf("%d\n", pop(&stack));
}
