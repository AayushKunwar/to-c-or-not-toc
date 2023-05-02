// fermats last theorem expressed as a hello-world program
// for n>2 no solution is found
// copied from book

#include<stdio.h>
#include<math.h>

int main(){
    int n,total,x,y,z;
    printf("Enter the power n:");
    scanf("%d",&n);
    total = 3;
    while(1){
        for (x=1; x<=total-2; x++){
            for(y=1; y<=total-x-1; y++){
                z = total -x-y;
                if(pow(x,n) + pow(y,n) == pow(z,n)){
                    printf("hello world\n");
                }
            }
        }
        total++;
    }
}

