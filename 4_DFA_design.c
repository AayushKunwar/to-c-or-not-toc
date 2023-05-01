// dfa implementation
// implemented random dfa found in my notebook, works doe
#include<stdio.h>
#include<string.h>

typedef struct Node {
    char name;
    struct Node* a;
    struct Node* b;
} Node;

int main() {
    Node a, b, c, d, e;

    a.name = 'a';
    a.a = &b;
    a.b = &e;
    b.name = 'b';
    b.a = &c;
    b.b = &b;
    c.name = 'c';
    c.a = &c;
    c.b = &c;
    d.name = 'd';
    d.a = &e;
    d.b = &d;
    e.name = 'e';
    e.a = &d;
    e.b = &e;

    Node* current = &a;
    char input[] = "01101";
    char accept[] = "cd"; // these are the final accepted states

    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == '0') {
            current = current->a;
        }
        else if (input[i] == '1') {
            current = current->b;
        }
        else {
            printf("wrong input m8\n");
            return 0;
        }
    }
    printf("the final state is %c\n",current->name);
    char *result = strchr(accept, current->name);
    if(result == 0){
        printf("not accepted");
        return 0;
    }
    printf("accepted");
}