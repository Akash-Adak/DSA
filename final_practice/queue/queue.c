#include<stdio.h>
#define m 10
int queue[m] ,front =0,rear=-1;
 
void push(){
    int n;
    if(rear==m-1){
        printf("queueack is overflow");
        return ;
    }
    printf("enter a number=");
    scanf("%d",&n);
    queue[++rear]=n;
}

void pop(){
    
    if(rear==-1){
        printf("queueack is underflow");
        return ;
    }
    printf("poped element is=%d",queue[front]);
   front++;
}
void display(){
   
    if(rear==-1){
        printf("queueack is underflow");
        return ;
    }
    for(int i=front;i<=rear;i++){
       printf("%d\n",queue[i]);
    }
   
   
}




void main(){
    int choice;
         do{
            printf("\n1.push\n2.pop\n3.display\n4.exit");
            printf("enter your choice=");
            scanf("%d",&choice);
            switch(choice){
                case 1:push();
                break;
                case 2:pop();
                break;
               
                case 3:display();
                break;
               default: printf("not valid");
            }
         }while(choice!=4);
}