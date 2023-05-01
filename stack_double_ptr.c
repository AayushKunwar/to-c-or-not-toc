#include<stdio.h>
#include<stdlib.h>

typedef struct Stack {
    char data;
    struct Stack* next;
}Stack;

Stack* make_stack(char data) {
    Stack* new_stack = (Stack*)malloc(sizeof(Stack));
    new_stack->data = data;
    new_stack->next = NULL;
    return new_stack;
}

void push(Stack **stack, char data) {
    Stack* new_stack = (Stack*)malloc(sizeof(Stack));
    new_stack->data = data;
    new_stack->next = *stack;
    *stack = new_stack;
    return;
}

char pop(Stack **stack) {
    char output = (*stack)->data;
    Stack* temp = *stack;
    *stack = (*stack)->next;
    free(temp);
    return output;
}


int main() {
    Stack* m = make_stack('a');
    push(&m, 'a');
    push(&m, 'b');
    printf("%c\n", pop(&m));
    printf("%c\n", pop(&m));
    printf("%c\n", pop(&m));
    return 0;
}
/*
typedef struct Node {
  int data;
  struct Node *next;
} Node;

typedef struct Stack {
  Node *top;
} Stack;

Stack make_stack() {
  Stack stack;
  stack.top = NULL;
  return stack;
}

void push(Stack *stack, int data) {
  Node *new_node = malloc(sizeof Node);
  new_node->data = data;
  new_node->next = stack->top;
  stack->top = new_node;
}
*/