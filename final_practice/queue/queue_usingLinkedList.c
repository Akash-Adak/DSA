#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct Node{
	int data;
	struct Node* next;
};

struct Node *rear = NULL,*front=NULL;
struct Node* temp;
bool isEmpty(){
    return rear==NULL;
}
void display(){
	temp = front;
	if(isEmpty()){
		printf("\nStack is Empty!\n");
		return;
	}
	else{
		printf("\nThere are currently items:-\n");
		while(temp != NULL){
			printf("%d\n", temp->data);
			temp = temp->next;
		}	
		printf("\n");
	}
}

void push(){
    int n;
    printf("\nElement to be inserted: ");
	scanf("%d", &n);
	if(isEmpty()){
		rear = (struct Node*) malloc(sizeof(struct Node*));
		rear->data = n;
		rear->next = NULL;
        front=rear;
	}
	else{
		temp = (struct Node*) malloc(sizeof(struct Node*));
        rear->next=temp;

		// temp->next = rear;
		temp->data = n;
        	temp->next=NULL;
		rear = temp;
	}
}

void pop(){
	temp = front;
	if(isEmpty()){
		printf("\nStack is empty!\n");
		exit(1);
	}
	else{
		temp = temp->next;
	
	printf("\nItem to be removed is %d.", front->data);
	free(front);
	front = temp;
    }
}
void peek(){
    if(isEmpty()){
        printf("\nstack is empty\n");
    }else{
         printf("peeked elememt is=%d",front->data);
    }
}

int main(){
	int choice;
	do{
		printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\nChoice: ");
		scanf("%d", &choice);
		switch(choice)	{
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
               
			default:
				printf("\nInvalid Input!\n");			
		}
	}while(choice!=4);
	return 0;
}