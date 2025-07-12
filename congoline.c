//congoline
#include<stdio.h>
#include<stdlib.h>
struct Node {
	int data;
	struct Node* next;
};
struct Node *head=NULL;
void insertAtEnd(int data) {
	struct Node* newNode=(struct Node *)malloc(sizeof(struct Node));
	newNode->data=data;
	newNode->next=NULL;
	if(head==NULL) {
		head=newNode;
	}
	else {
		struct Node *temp=head;
		while(temp->next!=NULL) {
			temp=temp->next;
		}
		temp->next=newNode;
	}
	printf("In queue:%d\n",data);
}
void deque() {
	struct Node* temp=head;
	head=temp->next;
	printf("Dequed is %d\n",temp->data);
	free(temp);

}
void peek() {
	struct Node *temp=head;
	printf("peek is %d\n",temp->data);
}
int main() {
	insertAtEnd(10);
	insertAtEnd(20);
	insertAtEnd(30);
	insertAtEnd(40);
	insertAtEnd(50);
	insertAtEnd(60);
	insertAtEnd(70);
	deque();
	deque();
	deque();

}
