#include <stdbool.h>

#define MAX 500

typedef struct s {
	int top;
	char array[MAX];
} S;

void push(S* s, char val) {
	s->array[s->top++] = val;
}

char pop(S* s) {
	return s->array[--s->top];
}

bool balanced(char s[]) {
	S stack;
	stack.top = 0;

	int i = 0;
	while (s[i] != '\0') {
		if (s[i] == '(' || s[i] == '[') {
			push(&stack, s[i]);
		} else if (s[i] == ')' || s[i] == ']') {
			char popped = pop(&stack);
			if (!((s[i] == ')' && popped == '(') || (s[i] == ']' && popped == '[')))
				return false;
		}

		i++;
	}

	stack.top != 0 ? false : true;
}
