//Josephus problam
#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node *next;
	struct Node *prev;
};

struct Node *head=NULL;
struct Node *tail=NULL;

struct Node* createNode(int value) {
	struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
	newNode->data=value;
	newNode->next=NULL;
	newNode->prev=NULL;
	return newNode;
}

void insertAtEnd(int value) {
	struct Node *newNode=createNode(value);
	newNode->prev=tail;
	if(tail!=NULL) {
		tail->next=newNode;
	}
	else {
		head=newNode;
	}
	tail=newNode;
}

void  makeCircular() {
	head->prev=tail;
	tail->next=head;
}

int solveGame(struct Node** head,int k) {
	struct Node *current=*head;
	int count;
	while(current->next!=current) {
		count=1;
		while(count<k) {
			current=current->next;
			count++;
		}
		printf("Player eliminated: %d\n",current->data);
		current->prev->next=current->next;
		current->next->prev=current->prev;
		if(current == *head)
			*head=current->next;
		struct Node *temp=current;
		current=current->next;
		free(temp);
	}
	printf("%dth is the Winner..",current->data);
	int winner=current->data;
	free(current);
	return winner;
}

void display() {
	struct Node *temp=head;
	while(temp!=NULL) {
		printf("%d ",temp->data);
		temp=temp->next;
	}
}
int main() {
	insertAtEnd(10);
	insertAtEnd(20);
	insertAtEnd(30);
	insertAtEnd(40);
	insertAtEnd(50);
	insertAtEnd(60);
	insertAtEnd(70);
	insertAtEnd(80);
	insertAtEnd(90);
	insertAtEnd(100);
	makeCircular();
	//display();
	int key;
	printf("enter key\n");
	scanf("%d",&key);
	solveGame(&head,key);
	//display();
}


