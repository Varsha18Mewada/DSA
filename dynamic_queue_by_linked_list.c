#include<stdio.h>
#include<stdlib.h>
struct queue{
int data ;
struct queue *next;

};
void insert(struct queue **,struct queue **,int);
int rem(struct queue **,struct queue **);

void display(struct queue *);

int main()
{
    struct queue *rear,*front;
    rear=front=NULL;
    int choice ,x;
    do{
    printf("\n Enter choice \n 1. INSERT \n 2. REMOVE \n 3.Display \n 4.Exit \n");
    scanf("%d",&choice);
    switch(choice)
    {
     case 1:
         printf("Enter a Element ");
         scanf("%d",&x);
         insert(&front,&rear,x);
         break;
     case 2:
        rem(&front,&rear);
        break;
    case 3:
        display(front);
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


void insert(struct queue **pf,struct queue **pr,int x){
    struct queue *p;
    p=(struct queue *)malloc(sizeof(struct queue));
    if(p==NULL){
        printf("Heap is full");
        return ;
    }
    p->data=x;
    p->next=NULL;
    if(*pf==NULL)
        *pf=p;
    else
        (*pr)->next=p;

    (*pr)=p;
    printf("Data added successfully");

}

int rem(struct queue **pf,struct queue **pr){
    struct queue *temp;
    int x;
    if((*pf)==NULL){
        printf("Queue is Underflow");
        return -1;
    }
    x=(*pf)->data;
    temp=*pf;
    if(*pf==*pr)
        *pf=*pr=NULL;
    else
        (*pf)=(*pf)->next;
    free(temp);
    printf("%d Data deleted successfully",x);
    return x;


}
 void display(struct queue *f){
     struct queue *t;
     if(f==NULL){
        printf("Dynamic queue is empty");
        return;
     }
     t=f;
     while(t!=NULL){
        printf("%d ",t->data);
        t=t->next;
     }

 }
