#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data; 
	struct Node *next;
};
struct Node* head = NULL;
void printList(struct Node *n){
	while(n!=NULL){
		printf("%d ", n->data);
		n = n->next;
	}
}
void create_list(int new_data){
	head = (struct Node*) malloc(sizeof(struct Node));
	head->data = new_data; 
	head->next = NULL;
}
void insert_node(int new_data){
	struct Node* new_node =(struct Node*) malloc(sizeof(struct Node));
	if (head==NULL){
		 head = new_node;
		 head->data = new_data;
		 head->next = NULL; 
	}
	else{
		new_node->data = new_data; 
		new_node->next = NULL;
		struct Node* cursor = head;
		struct Node* back = NULL;
		while(cursor->next!=NULL){
			cursor = cursor->next;
		}
		cursor->next = new_node;
	}
}
void delete_node(int del_data){
	if(head==NULL){
		exit(1);
	}
	if(head->data == del_data){
			head = head->next; 
	}
	else{
		struct Node* cursor = head; 
		struct Node* back = NULL;
		while(cursor->data!=del_data){
			back = cursor; 
			cursor = cursor->next;
		}
		if(cursor!=NULL && cursor->data == del_data){
			back->next = cursor->next; 
			cursor->next = NULL;
			free(cursor);
		}
	}
}
int main(int argc, char const *argv[])
{
  create_list(5);
  insert_node(4);
  insert_node(3);
  insert_node(2);
  delete_node(5);
  printList(head);
  return 0;
}
