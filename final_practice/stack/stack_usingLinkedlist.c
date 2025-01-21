#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct Node{
	int data;
	struct Node* next;
};

struct Node* top = NULL;
struct Node* temp;
bool isEmpty(){
    return top==NULL;
}
void display(){
	temp = top;
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
		top = (struct Node*) malloc(sizeof(struct Node*));
		top->data = n;
		top->next = NULL;
	}
	else{
		temp = (struct Node*) malloc(sizeof(struct Node*));
		temp->next = top;
		temp->data = n;
		top = temp;
	}
}

void pop(){
	temp = top;
	if(isEmpty()){
		printf("\nStack is empty!\n");
		exit(1);
	}
	else{
		temp = temp->next;
	
	printf("\nItem to be removed is %d.", top->data);
	free(top);
	top = temp;
    }
}
void peek(){
    if(isEmpty()){
        printf("\nstack is empty\n");
    }else{
         printf("peeked elememt is=%d",top->data);
    }
}

int main(){
	int choice;
	do{
		printf("\n1.Push\n2.Pop\n3.Display\n4.peek\n5.Exit\nChoice: ");
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
                case 4:
                peek();
                break;
			default:
				printf("\nInvalid Input!\n");			
		}
	}while(choice!=5);
	return 0;
}