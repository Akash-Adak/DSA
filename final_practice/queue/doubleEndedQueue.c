# include<stdio.h>
# define Size 5
 
int deque_arr[Size];
int front = -1;
int rear = -1;
 
/*Begin of insert_rear*/
void insert_rear()
{
    int added_item;
    if((front == 0 && rear == Size-1) || (front == rear+1))
    {   printf("Queue Overflow\n");
        return;}
    if (front == -1)  /* if queue is initially empty */
    {   front = 0;
        rear = 0;}
    else{
    if(rear == Size-1)  /*rear is at last position of queue */
        rear = 0;
    else
        rear = rear+1;
    } 
    printf("Input the element for adding in queue : ");
    scanf("%d", &added_item);
    deque_arr[rear] = added_item ;
}

 
/*Begin of insert_front*/
void insert_front()
{   int added_item;
    if((front == 0 && rear == Size-1) || (front == rear+1))
    {   printf("Queue Overflow \n");
        return;  }
    if (front == -1)/*If queue is initially empty*/
    {   front = 0;
        rear = 0;    }
    else
    if(front== 0)
        front=Size-1;
    else
        front=front-1;
    printf("Input the element for adding in queue : ");
    scanf("%d", &added_item);
    deque_arr[front] = added_item ;  }

 
/*Begin of delete_front*/
void delete_front()
{   if (front == -1)
    {   printf("Queue Underflow\n");
        return ;
    }
    printf("Element deleted from queue is : %d\n",deque_arr[front]);
    if(front == rear) /*Queue has only one element */
    {   front = -1;
        rear=-1;
    }
    else
        if(front == Size-1)
            front = 0;
        else
            front = front+1;
}

 
/*Begin of delete_rear*/
void delete_rear()
{
    if (front == -1)
    {
        printf("Queue Underflow\n");
        return ;
    }
    printf("Element deleted from queue is : %d\n",deque_arr[rear]);
    if(front == rear) /*queue has only one element*/
    {
        front = -1;
        rear=-1;
    }
    else
        if(rear == 0)
            rear=Size-1;
        else
            rear=rear-1;    }
 
/*Begin of input_que*/
void display_queue()
{   
    int front_pos = front,rear_pos = rear;
     
    if(front == -1)
    {   printf("Queue is empty\n");
        return;
    }
    printf("Queue elements :\n");
    if( front_pos <= rear_pos )
    {   
        while(front_pos <= rear_pos)
        {
            printf("%d ",deque_arr[front_pos]);
            front_pos++;
        }
    }
    else
    {
        while(front_pos <= Size-1)
        {   printf("%d ",deque_arr[front_pos]);
            front_pos++;    
        }
        front_pos = 0;
        while(front_pos <= rear_pos)
        {   
            printf("%d ",deque_arr[front_pos]);
            front_pos++;
        }
    }
    printf("\n");
}
 void main()
{   int choice;
   do
  {
      printf("          Dqueue        ");
       printf("\n1.insert rear\n2.delete front\n3.insert front\n4.delete rear\n5.display\n6.exist");
       printf("             \n         ");
      printf("\nenter your choce=");
      scanf("%d",&choice);
      switch(choice){
           case 1:insert_rear();
            break;
           case 2:delete_front();
           break;
            case 3:insert_front();
            break;
             case 4:delete_rear();
            break;
             case 5: display_queue();
            break;
            default: printf("not valid");
      }
  }while(choice!=6);
}
