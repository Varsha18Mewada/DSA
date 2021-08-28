
#include<stdio.h>
struct stack{
    char arr[15];
    int tos;
};
void push( struct stack*,char);
char pop(struct stack *);
int isoperand(char);
int isempty(struct stack);
int prcd(char,char);
void convert(char [],char []);
int main(){


    char infix[15];
    char postfix[15];
    printf("Enter a valid infix  expression ");
    scanf("%s",infix);
    convert(infix,postfix);
    printf("%s",postfix);


return 0;

}
void push(struct stack *p,char ch){
    p->arr[++p->tos]=ch;

}
char pop(struct stack *p){
    return p->arr[p->tos--];
}
int isoperand(char ch){
    if((ch>=48 && ch<=57)||(ch>='a'&& ch<='z')||(ch>='A'&& ch<='Z'))
        return 1;
    return 0;
}
int isempty(struct stack s){
    if(s.tos==-1)
        return 1;
    return 0;
}

int prcd(char ch1,char ch2){
    if(ch2=='$')
        return 0;
    else if(ch1=='$')
        return 1;
    else if(ch2=='/'||ch2=='*'||ch2=='%')
        return 0;
    else if(ch1=='/'||ch1=='*'||ch1=='%')
        return 1;
    else if(ch2=='+'|| ch2=='-')
        return 0;
    else
        return 1;
}

void convert(char infix[], char postfix[]){
struct stack s;

int ans,i,j=0;
char ch;
s.tos=-1;
for(i=0; infix[i]!='\0'; i++){
        ch=infix[i];
        if(isoperand(ch)==1){
            postfix[j]=ch;
            j++;
        }
        else{
                while(isempty(s)==0){
                        ans=prcd(ch,s.arr[s.tos]);
                        if(ans==1)
                            break;
                        postfix[j]=pop(&s);
                        j++;}
                push(&s,ch);

        }
    }
        while(isempty(s)==0){
            postfix[j]=pop(&s);
            j++;}
        postfix[j]='\0';
    }


