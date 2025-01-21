#include<stdio.h>
#define m 10
int st[m] ,top=-1;
 
void push(){
    int n;
    if(top==m-1){
        printf("stack is overflow");
        return ;
    }
    printf("enter a number=");
    scanf("%d",&n);
    st[++top]=n;
}

void pop(){
    int n;
    if(top==-1){
        printf("stack is underflow");
        return ;
    }
   top--;
}
void display(){
   
    if(top==-1){
        printf("stack is underflow");
        return ;
    }
    for(int i=top;i>=0;i--){
       printf("%d\n",st[i]);
    }
   
   
}
void peek(){
    int n;
    if(top==-1){
        printf("stack is underflow");
        return ;
    }
    n=st[top];
    printf("the top element is=%d",n);
   
}



void main(){
    int choice;
         do{
            printf("\n1.push\n2.pop\n3.peek\n4.display\n5.exit");
            printf("enter your choice=");
            scanf("%d",&choice);
            switch(choice){
                case 1:push();
                break;
                case 2:pop();
                break;
                case 3:peek();
                break;
                case 4:display();
                break;
               default: printf("not valid");
            }
         }while(choice!=5);
}