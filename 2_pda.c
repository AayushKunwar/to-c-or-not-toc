// implementation of pda
// for language L = a^n,b^n
#include<stdio.h>
#include<string.h>

typedef struct Stack{
    char data[100];
    int tos;
} Stack;

char pop(Stack *stack){
    char output = stack->data[stack->tos];
    stack->tos--;
    return output;
}
char peek(Stack *stack){
    return stack->data[stack->tos];
}

void push(Stack *stack, char data){
    stack->tos++;
    stack->data[stack->tos] = data;
    return;
}

int main(){
    Stack m;
    // this step required
    push(&m,'e');
    // rememeber to add e at the end of string
    char input[] = "aaaabbbe";
    char state = 'P';
    for(int i = 0; i<strlen(input); i++){
        if(state == 'P' && input[i] == 'a' && peek(&m) == 'e'){
            state = 'P';
            push(&m, 'a');
        }
        else if (state == 'P' && input[i] == 'a' && peek(&m) == 'a')
        {
            state = 'P';
            push(&m, 'a');
        } else if(state == 'P' && input[i] == 'b' && peek(&m) == 'a'){
            state = 'P';
            pop(&m);
        }
        else if(state == 'P' && input[i] == 'e' && peek(&m) == 'e'){
            printf("String is accepted");
            return 0;
        }
        else{
            printf("String not accepted");
            return 0;
        }
        
    }
    return 0;
}