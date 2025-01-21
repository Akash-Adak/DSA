#include<stdio.h>
#define MAXSIZE 10
int cq[MAXSIZE],rear=-1,front=-1;
void insert(){
if((rear+1)%MAXSIZE==front) printf(" queue is overflow");
else{
    int n;
    printf(" enter a element= ");
    scanf("%d",&n);
    if(rear==-1 && front==-1){
     rear=0;
     front=0;
    }
    else{
        rear=(rear+1)%MAXSIZE;
    }
    cq[rear]=n;
}
}
void Delete(){
    int n;
    if(front==-1&&rear==-1) printf(" queue is empty");
    else{
      n=cq[front];
      if(front==rear){
        front=rear=-1;
      }
      else{
        front=(front+1)%MAXSIZE;
      }
      printf(" delete element is =%d",n);
    }
}
void display(){
    if(front==-1&&rear==-1) printf(" queue is empty");
    else {
      int i;
        printf(" queue elements");
        for ( i=front;i!=rear;i=(i+1)%MAXSIZE){
          printf("\n%d",cq[i]);
        }
         printf("\n%d",cq[i]);
    }
}
void main(){
  int choice;
  do
  {
      printf("          circular queue        ");
       printf("\n1.insert\n2.delete\n3.display\n4.exist");
       printf("             \n         ");
      printf("\nenter your choce=");
      scanf("%d",&choice);
      switch(choice){
           case 1:insert();
            break;
           case 2:Delete();
           break;
            case 3: display();
            break;
            default: printf("not valid");
      }
  }while(choice!=4);
}
