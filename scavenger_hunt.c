#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node {
	char *data;
	struct Node *next;
};

struct Node *head=NULL;


void insertAtBeg(char *clue) {
	struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
	newNode->data=(char*)malloc(strlen(clue)+1);
	strcpy(newNode->data,clue);
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
}

void display()
{
	if(head==NULL) {
		printf("No clues....\n");
	}
	struct Node *temp=head;
	while(temp!=NULL) {
		printf("%s-->",temp->data);
		temp=temp->next;
	}
}

void startGame() {
	if(head==NULL) {
		printf("No clues....\n");
	}
	struct Node *temp=head;
	while(temp!=NULL) {
		getchar();
		printf("%s-->",temp->data);
		temp=temp->next;
	}
}

int main() {
	char *clue;

	int choice;
	do {
		printf("Choice 1:Add clue\nchoice 2:display\nchoice 3:To strat Game\nchoice 4:exit\n");
		scanf("%d",&choice);
		switch(choice) {
		case 1:
			printf("enter clue\n");
			scanf(" %[^\n]s",clue);
			insertAtBeg(clue);
			break;
		case 2:
			printf("ALL clues are\n");
			display();
			printf("\n");
			break;
		case 3:
			printf("Lets start a game\n");
			startGame();
			break;
		case 4:
			printf("exiting game\n");
			exit(0);
			break;
		default:
			printf("enter valid input\n");

		}

	} while(1);
}
