#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

struct Stack {
    int arr[MAX_SIZE];
    int top;
};

void initialize(struct Stack *stack) {
    stack->top = -1;
}

int isEmpty(struct Stack *stack) {
    return (stack->top == -1);
}

int isFull(struct Stack *stack) {
    return (stack->top == MAX_SIZE - 1);
}

void push(struct Stack *stack, int data) {
    if (isFull(stack)) {
        printf("Stack Overflow: Cannot push element onto the stack.\n");
        return;
    }
    stack->arr[++stack->top] = data;
    printf("%d pushed onto the stack.\n", data);
}

// Function to pop an element from the stack
int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow: Cannot pop element from an empty stack.\n");
        return -1;
    }
    return stack->arr[stack->top--];
}


void display(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("The stack is empty.\n");
        return;
    }
    printf("Stack contents: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->arr[i]);
    }
    printf("\n");
}

int main() {
    struct Stack stack;
    initialize(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    display(&stack);

    int popped = pop(&stack);
    if (popped != -1) {
        printf("Popped element: %d\n", popped);
    }

    display(&stack);

    return 0;
}
