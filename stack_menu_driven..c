/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include<stdlib.h>


    struct stack {
    int arr[5];
    int tos;
};

void push(struct stack*,int);
int pop(struct stack*);

int main(){
    struct stack s;
s.tos=-1;
  int x;

    printf("\nselect the operation");
    printf("\n1. PUSH");
    printf("\n2. POP");
    printf("\n3. QUIT");

 printf("\n Enter your choice:");
 int ch;
 scanf("%d",&ch);

 switch(ch){
     case 1:
     for(int i=1; i<=6; i++){
    printf("\nEnter an element which you want to push : ");
    scanf("%d",&x);
    push(&s,x);
    break;
    //continue;

}
     case 2:
     for(int i=1; i<=6; i++){
     pop(&s);
     break;
     //continue;

}
case 3:
exit(0);
break;

default:
printf("Enter valid operation ");


 }

 /*printf("Enter 1 for continue ");
 int one;
 sacnf("%d",&one);
 while()*/


    return 0;
}

void push(struct stack*p,int x){
    if(p->tos==4){
        printf("\nStack overflow ");
        return ;
    }
    else{
        p->tos=p->tos+1;
        p->arr[p->tos]=x;
        printf("\nPushed successfully %d",x);

    }

}

int pop(struct stack *p){
    if(p->tos==-1){
        printf("\nStack underflow ");
        return;
    }
    else{
        int popped=p->arr[p->tos];
         printf("\nPopped element is %d ",popped);
         p->tos=p->tos-1;

    }
}

