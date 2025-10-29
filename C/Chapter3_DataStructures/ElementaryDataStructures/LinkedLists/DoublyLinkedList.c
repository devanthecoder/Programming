#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    double key;
    struct node* prev;
    struct node* next;
}Node;
typedef struct{
    Node* NIL;
}List;
List CreateList(){
    List L;
    L.NIL = (Node *)calloc(1, sizeof(Node));
    L.NIL->next = L.NIL;
    L.NIL->prev = L.NIL;
}
Node* CreateNode(double key){
    Node* node = (Node *)calloc(1, sizeof(Node));
    node->next = NULL;
    node->prev = NULL;
    node->key = key;
    return node;
}
Node* Search(List* L, double key){
    Node* curr = L->NIL->next;
    while(curr!=L->NIL && curr->key!=key)curr=curr->next;
    return curr==L->NIL?NULL:curr;
}
void Insert(Node* toInsert, Node* at){
    toInsert->next = at->next;
    at->next = toInsert;
    toInsert->next->prev = toInsert;
    toInsert->prev = at;
}
void Delete(List* L, Node* toDelete){
    Node* temp = toDelete;
    // else{
        Node* before = L->NIL->next;
        while(before->next != toDelete && before->next != L->NIL) before = before->next;
        if(before->next == toDelete)before->next = temp->next;
        else{
            fprintf(stderr, "RUNTIME ERROR\n");
            exit(EXIT_FAILURE);
        }
    // }
    free(temp);
}
void PrintList(List L){
    printf("{ ");
    for(Node* curr=L.NIL->next;curr!=L.NIL;curr=curr->next)printf("%.2lf ", curr->key);
    printf("}\n");
}
int main(){
    List L = CreateList();
    Node* N0  = CreateNode(0);
    Insert(N0, L.NIL);
    Node* N1  = CreateNode(1);
    Node* N2  = CreateNode(2);
    Node* N3  = CreateNode(3);
    Insert(N1, L.NIL->next);
    Insert(N2, L.NIL->next);
    Insert(N3, L.NIL->next);
    PrintList(L);
}