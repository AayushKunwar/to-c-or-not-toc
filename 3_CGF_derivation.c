// CFG leftmost (any) derivation
// gives random derivation for every run
/*
    S -> ABa | bABa
    A -> aAb |  ab
    B -> bA  | bB | e
*/
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

typedef struct State_Node {
    char state_id;
    char* child;
    int child_count;
}State_Node;

State_Node states[10];
int states_limit = 0;
char output_str[30];
int output_len = 0;

void make_state(char state_id, char childrens[], int child_count) {
    states[states_limit] = (struct State_Node){ state_id, childrens, child_count };
    states_limit++;
}

int find_state(char id) {
    int choices[10];
    int choices_size = 0;
    for (int i = 0; i < states_limit; i++) {
        if (states[i].state_id == id) {
            choices[choices_size] = i;
            choices_size++;
        }
    }
    if (choices_size != 0) {
        return choices[rand() % choices_size];
    }
    else {
        printf("Not found %c\n", id);
        return -1;
    }
}

int in_array(char* arr, char data) {
    int size = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < size; i++) {
        if (data == arr[i]) {
            return 1;
        }
    }
    return 0;
}

void traverse(char input_state) {
    int state_no = find_state(input_state);

    printf("using rule %d\n",state_no+1);
    for (int i = 0; i < states[state_no].child_count;i++) {
        if (states[state_no].child[i] >= 'a') {
            if (states[state_no].child[i] != 'e') {
                // printf("%c\n", states[state_no].child[i]);
                output_str[output_len] = states[state_no].child[i];
                output_len++;
            }

        }
        else {
            // find the state for char
            int new_state = find_state(states[state_no].child[i]);
            // traverse to that state
            traverse(states[new_state].state_id);
        }
    }
}

int main() {
    srand(time(NULL));
    char str1[] = { 'A', 'B', 'a' };
    make_state('S', str1, 3);
    char str2[] = { 'b', 'A', 'B', 'a' };
    make_state('S', str2, 4);
    char str3[] = { 'a', 'A', 'b' };
    make_state('A', str3,3);
    char str4[] = { 'a', 'b' };
    make_state('A', str4,2);
    char str5[] = { 'b', 'A' };
    make_state('B', str5,2);
    char str6[] = { 'b', 'B' };
    make_state('B', str6,2);
    char str7[] = {'e'};
    make_state('B',str7,1); 
    
    traverse('S');
    printf("output is %s\n", output_str);
    return 0;
}