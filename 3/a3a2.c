#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node* next;
};
struct Node* nnode(struct Node* new){
	new=(struct Node*)malloc(sizeof(struct Node*));
	return new;
}

void add_ele(struct Node* head,int dat,struct Node* temp){
	//struct node* temp=NULL;
	struct Node* new=NULL;
	new=nnode(new);
	new->data=dat;
	temp=head->next;
	while(temp->next!=head){
		temp=temp->next;
	}
	temp->next=new;
	new->next=head;
}
void print(struct Node* head,struct Node* temp){
	printf("%d ",head->data);
	temp=head;
	temp=temp->next;
	while(temp!=head){
		printf("%d ",temp->data);
		temp=temp->next;
	}
}
int count_no_ele(struct Node* head,struct Node* temp){
	int t=1;
	if(head==NULL)return 0;
	temp=head;
	temp=temp->next;
	if(head!=temp)t++;
	while(head!=temp){
		temp=temp->next;
		t++;
	}
	return --t;
}
struct Node* remove_first(struct Node* head, struct Node* temp){
	temp=head;
	while(temp->next!=head)temp=temp->next;
	temp->next=head->next;
	free(head);
	temp=temp->next;
	return temp;
}
void add_last(struct Node* head,struct Node* temp,int dat){
	temp=head;
	while(temp->next!=head)temp=temp->next;
	struct Node* new=NULL;
	new=nnode(new);
	new->data=dat;
	new->next=head;
	temp->next=new;
}
void remove_last(struct Node* head,struct Node* temp){
	temp=head;
	while(temp->next->next!=head)temp=temp->next;
	struct Node* del=NULL;
	del=temp->next;
	free(del);
	temp->next=head;

}
void main(){
	
	
	struct Node* head=NULL;
	struct Node* temp=NULL;
	struct Node* last=NULL;
	int choice = -1,f=0,t1,t2,t3;
	while(choice!=0){
		printf("Enter your choice:\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
			printf("Enter the data of the new node at the start\n");
			scanf("%d",&t1);
			if(f==0){
					head=nnode(head);
					head->data=t1;
					head->next=head;
					last=head;
				}
			else 
					add_ele(head,t1,temp);
					f++;
			break;
			case 2:
					printf("Printing the elements of the list:\n");
					print(head,temp);
					printf("\n");
			break;
			case 3:
					t1=count_no_ele(head,temp);
					printf("The number of elements in the list are %d\n",t1);
			break;
			case 4:
					printf("Removing the first element of the list\n");
					head=remove_first(head,temp);
					f--;
			break;
			case 5:
					printf("Enter the number to be inserted at the end of the list\n");
					scanf("%d",&t1);
					add_last(head,temp,t1);
					f++;
			break;
			case 6:
					printf("Removing the last element of the list\n");
					remove_last(head,temp);
					f--;
			break;
		}
	}
}
