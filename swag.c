#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
} Node;
Node *head = NULL;

Node *create_Node(int value){
    Node *tmp = (Node *)malloc(sizeof(Node));
    tmp -> data = value;
    tmp -> next = head;
    return tmp;
}

void push(Node * data, int value){
    Node *tmp = create_Node(value);

}