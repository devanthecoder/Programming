#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    double key;
    struct node* next;
}Node;
Node* CreateNode(double key){
    Node* node = (Node *)calloc(1, sizeof(Node));
    node->next = NULL;
    node->key = key;
    return node;
}
Node* Search(Node* Head, double key){
    Node* curr = Head;
    while(curr!=NULL && curr->key!=key)curr=curr->next;
    return curr;
}
void Insert(Node* toInsert, Node* at){
    if (at == NULL || toInsert == NULL) return;
    toInsert->next = at->next;
    at->next = toInsert;
}
void Prepend(Node* toInsert, Node** Head){
    toInsert->next = *Head;
    *Head = toInsert;
}
void Delete(Node** Head, Node* toDelete){
    if (*Head == NULL || toDelete == NULL) return;
    Node* temp = toDelete;
    if(toDelete==(*Head)) (*Head) = (*Head)->next;
    else{
        Node* before = (*Head);
        while(before->next != toDelete && before->next != NULL) before = before->next;
        if(before->next == toDelete)before->next = temp->next;
    }
    free(temp);
}