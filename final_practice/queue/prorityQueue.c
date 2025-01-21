#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
int queue[SIZE];
int priority[SIZE];
int front = -1, rear = -1;
int isFull() {
 return rear == SIZE - 1;
}
int isEmpty() {
 return front == -1;
}
void enqueue(int value, int prio) {
 if (isFull()) {
 printf("Queue is full\n");
 return;
 }
 if (isEmpty()) {
 front = 0;
 rear = 0;
 queue[rear] = value;
 priority[rear] = prio;
 } else {
 int i;
 for (i = rear; i >= front && priority[i] < prio; i--) {
 queue[i + 1] = queue[i];
 priority[i + 1] = priority[i];
 }
 queue[i + 1] = value;
 priority[i + 1] = prio;
 rear++;
 }
 printf("Inserted %d with priority %d\n", value, prio);
}
int dequeue() {
 if (isEmpty()) {
 printf("Queue is empty\n");
 return -1;
 }
 int data = queue[front];
 printf("Deleted %d with priority %d\n", data, priority[front]);
 if (front == rear) {
 front = rear = -1;
 } else {
 front++;
 }
 return data;
}
void displayQueue() {
 if (isEmpty()) {
 printf("Queue is empty\n");
 return;
 }
 printf("Queue elements are:\n");
 for (int i = front; i <= rear; i++) {
 printf("Value: %d, Priority: %d\n", queue[i], priority[i]);
 }
}
int main() {
 int choice, value, prio;
 while (1) {
 printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
 printf("Enter your choice: ");
 scanf("%d", &choice);
 switch (choice) {
 case 1:
 printf("Enter value to insert: ");
 scanf("%d", &value);
 printf("Enter priority: ");
 scanf("%d", &prio);
 enqueue(value, prio);
 break;
 case 2:
 dequeue();
 break;
 case 3:
 displayQueue();
 break;
 case 4:
 exit(0);
 default:
 printf("Invalid choice\n");
 }
 }
 return 0;
 }