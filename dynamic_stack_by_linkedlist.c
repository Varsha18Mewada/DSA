#include<stdio.h>
#include<stdlib.h>
struct stack{
int data ;
struct stack *next;

};
void push(struct stack **,int);
int pop(struct stack **);
void display(struct stack *);

int main()
{
    struct stack *tos=NULL;
    int choice ,x;
    do{
    printf("\n Enter choice \n 1. PUSH \n 2. POP \n 3.Display\n  4.Exit \n");
    scanf("%d",&choice);
    switch(choice)
    {
     case 1:
         printf("Enter a Element ");
         scanf("%d",&x);
         push(&tos,x);
         break;
     case 2:
        pop(&tos);
        break;
    case 3:
        display(tos);
        break;


     case 4:
        return 0;
        break;
     default:
        printf("Invalid choice ");
        break;


    }
    }
    while(choice != 4);
    return 0;
}
void push(struct stack **ptos,int x){
    struct stack *p;
    p=(struct stack *)malloc(sizeof(struct stack));
    if(p==NULL){
        printf("Stack Overflow");
        return;
    }

    p->data=x;
    p->next=*ptos;
    *ptos=p;
    printf("Data added successfully");

}
int pop(struct stack **ptos){
    struct stack *temp;
    int x;
    if(*ptos==NULL){
        printf("Stack Underflow");
        return -1;
    }
    temp=*ptos;
    x=temp->data;
    *ptos=(*ptos)->next;
    free(temp);
    printf(" %d Data Deleted successfully", x);
    return x;

}
void display(struct stack *tos){
if(tos==NULL){
    printf("Stack is empty");
}
 while(tos!=NULL)
      {
         printf("\n %d",tos->data);
         tos=tos->next ;
      }
/*do{
    printf("%d",tos->data);
    tos=tos->next;
}
while(tos->next!=NULL);*/
}
