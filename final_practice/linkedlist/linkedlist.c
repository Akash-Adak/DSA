#include<stdio.h>
#include<stdlib.h>
struct node{
    int val;
    struct node *next;
};
struct node *temp,*start=NULL,*new,*last,*pre;
void create(int n){
    start=(struct node*)malloc(sizeof(struct node*));
    start->val=n;
    start->next=NULL;
   last=start;

}
void insert_first(){
     int n;
    printf("enter element=");
    scanf("%d",&n);
    if(start==NULL){
        create(n);
        return;
    }
    new=(struct node*)malloc(sizeof(struct node*));
    new->val=n;
    new->next=start;
    start=new;
} 
void insert_last(){
     int n;
    printf("enter element=");
    scanf("%d",&n);
    if(start==NULL){
        create(n);
        return;
    }
    new=(struct node*)malloc(sizeof(struct node*));
    new->val=n;
    new->next=NULL;
    last->next=new;
    last=new;
}
void insert_any_position(){
     int n,pos;
    printf("enter element=");
    scanf("%d",&n);
    if(start==NULL){
        create(n);
        return;
    }
    new=(struct node*)malloc(sizeof(struct node*));
    new->val=n;
    new->next=NULL;
   printf("enter a position=");
   scanf("%d",&pos);
   temp=start;
   for(int i=0;i<pos-1;i++){
    pre=temp;
     temp=temp->next;
   }
   new->next=temp;
   pre->next=new;
}


void delete_first(){
  if(start==NULL){
    printf("list is not created");
    return;
  }
  temp=start;
  temp=temp->next;
  printf("deleted node is=%d",start->val);
  free(start);
  start=temp;
} 
void delete_last(){
     if(start==NULL){
    printf("list is not created");
    return;
  }
  temp=start;
  while(temp->next!=last){
    temp=temp->next;
  }
  
  printf("deleted node is=%d",last->val);
  
  free(last);
  last=temp;
  last->next=NULL;
}
void delete_any_position(){
 if(start==NULL){
    printf("list is not created");
    return;
  }

int pos;
   printf("enter a position=");
   scanf("%d",&pos);
   temp=start;
   for(int i=0;i<pos-1;i++){
    pre=temp;
     temp=temp->next;
   }
   pre->next=temp->next;
  printf("deleted node is=%d",temp->val);
  free(temp);


}

void display(){
    temp=start;
    while(temp!=NULL){
        printf("%d->",temp->val);
        temp=temp->next;
    }
    printf("NULL");
}

void main(){
    int choice;
    do{
      printf("          linkdlist        ");
       printf("\n1.display\n2.insert on first\n3.insert on last\n4.insert on middle\n5.delete on first\n6.delete on last\n7.delete on middle\n8.exist");
       printf("             \n         ");
      printf("\nenter your choce=");
      scanf("%d",&choice);
      switch(choice){
          
            case 1: display();
            break;
            case 2:insert_first();
            break;
            case 3: insert_last();
            break;
            case 4:insert_any_position();
            break;
            case 5: delete_first();
            break;
            case 6:delete_last();
            break;
            case 7: delete_any_position();
            break;
       
         
            default: printf("not valid");
      }
    }while(choice!=8);
}