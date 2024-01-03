#include <stdio.h>
#include <stdlib.h>

struct node{
  int x;
  struct node *next;
};

struct node *create_node(int data){
  // create a node
  
  struct node *newnode = (struct node*)malloc(sizeof(struct node*));
  newnode->x = data;
  newnode->next = NULL;
  return newnode;
}

void insert_data(struct node *head , int data){
  // insert data into node
  
  struct node *newnode = (struct node*)malloc(sizeof(struct node*));
  newnode->x = data;
  newnode->next = NULL;
  head->next = newnode;
}

void print_nodes(struct node *head , int total){
  // print all nodes
  
  struct node *newnode = head;
  for(int i=0;i<total;i++){
    printf("%d\n" , newnode->x);
    newnode = newnode->next;
  }

  // free all allocated memory in order to avoid memory leak
  newnode = head;
  for(int i=0;i<total;i++){
    struct node *nextnode = newnode->next;
    free(newnode);
    newnode = nextnode;
  }
}
int main(){
  int total=1;
  struct node* head = create_node(10);
  struct node* old_node = head;
  
  for(int i=0;i<12;i++){
    total++;
    insert_data(old_node , i);
    old_node = old_node->next;
  }
  
  print_nodes(head , total);
  return 0;
}
