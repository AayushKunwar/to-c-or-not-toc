// example of turing machine
// for one's complement
#include<stdio.h>

int main(){
    // P is the leftmost limit
    char tape[20] = "P101011";
    char state = 'P';
    int head = 0;
    printf("%s\n",tape);
    while(1){
        if(state == 'P' && tape[head] == 'P'){
            state = 'P';
            head++;
        }
        else if(state == 'P' && tape[head] == '1'){
            state = 'Q';
            tape[head] = '0';
        }
        else if(state == 'P' && tape[head] == '0'){
            state = 'Q';
            tape[head] = '1';
            
        }
        else if(state == 'Q'){
            state = 'P';
            head++;
        }
        else if(state == 'P' && tape[head] == 0){
            break;
        }
        else{
            printf("what?");
            break;
        }
    }
    printf("%s\n",tape);
    return 0;
}