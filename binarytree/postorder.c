/*
  Name  : Fakhra Najm
  Email : fnajm09@gmail.com
  Postorder traversal with one stack without using recursion  
*/

#include<stdio.h>
#include<stdlib.h>
#include"Queue.h"
#include"stack.h"

struct Node *root = NULL;
struct Queue queue;
struct stack stk;

void createTree(){
  createQ(&queue, 100);
  struct Node *node, *place_holder;
  int value;
  printf("Enter root value : ");
  scanf("%d", &value);
  root = (struct Node *)malloc(sizeof(struct Node));
  root->data = value;
  root->left_child = root->right_child = NULL;
  enqueue(&queue, root);

  while ( ! isEmpty(queue))
  {
    place_holder = dequeue(&queue);
    
    printf("Enter left child of %d: ", place_holder->data);
    scanf("%d", &value);
    if(value != -1){
      node = (struct Node *)malloc(sizeof(struct Node));
      node->data = value;
      node->left_child = node->right_child = NULL;
      place_holder->left_child = node;
      enqueue(&queue, node);
    }

    printf("Enter right child of %d: ", place_holder->data);
    scanf("%d", &value);
    if(value != -1){
      node = (struct Node *)malloc(sizeof(struct Node));
      node->data = value;
      node->left_child = node->right_child = NULL;
      place_holder->right_child = node;
      enqueue(&queue, node);
    }
  }
}

void postorder(struct Node *root){

  createStack(&stk, 100);
  int i = 0;
  while(root || ! isEmptyStack(stk)){
    if(root){
      push(&stk, root);
      root = root->left_child;
    }
    else{
      root = pop(&stk);
      if( root->right_child == NULL){
        printf("%d ", root->data);
        root = NULL;
        i++;
        }

      }
      else{
        root = root->right_child;
      }

    }
  }
}

int main(){
  createTree();
  postorder(root);
  return 0;
}