// regular expression implemented as DFA
// for (ab*a)*

#include<stdio.h>
#include<string.h>

int main() {
    char input[] = "abba";
    printf("for input: %s\n", input);
    char state = 'P';
    for (int i = 0; i < strlen(input); i++) {
        if (state == 'P' && input[i] == 'a') {
            state = 'Q';
        }
        else if (state == 'P' && input[i] == 'b') {
            printf("not accepted");
            return 0;
        }
        else if (state == 'Q' && input[i] == 'b') {
            state = 'Q';
        }
        else if (state == 'Q' && input[i] == 'a') {
            state = 'P';
        }
    }
    if (state == 'P') {
        printf("accepted\n");
    }
    else {
        printf("not accepted\n");
    }
}