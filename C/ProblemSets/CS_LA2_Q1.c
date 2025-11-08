#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    double value;
    struct node* next;
}Node;
typedef struct{
    Node* Head;
    Node* Tail;
}List;
List DefineList(){
    List L;
    L.Head = NULL;
    L.Tail = NULL;
    return L;
}
Node* CreateNode(double value){
    Node* node = (Node*)calloc(1, sizeof(Node));
    // node->prev = NULL;
    node->next = NULL;
    node->value = value;
    return node;
}
Node* Search(List L, double value){
    Node* curr = L.Head;
    while(curr!=NULL && curr->value!=value)curr=curr->next;
    return curr;
}
void Insert(List* L, Node* toInsert, Node* at){
    toInsert->next = at->next;
    if(at->next==NULL)L->Tail = toInsert;;
    // else 
    at->next = toInsert;
    // toInsert->prev = at;
}
void Delete(List* L, Node* N){
    if(!N)return;
    Node* temp = N;
    // Node* temp2 = N->prev;
    Node* prev = L->Head;
    while(prev->next!=N && prev!=NULL){
        prev = prev->next;
    }
    // if(!prev)return;
    if(prev!=NULL) prev->next = N->next;
    else L->Head = N->next;
    // if(N->next!=NULN->prev;
    free(temp);

}
void Prepend(List* L, Node* N){
    if(L->Head==NULL) {
        L->Head = N;
        L->Tail = N;
    }
    else{
        N->next = L->Head;
        // L->Head->prev = N;
        L->Head = N;
    }
}
void PrintList(List L){
    Node* curr;
    for(curr=L.Head;curr->next!=NULL;curr=curr->next)printf("%.0lf ", curr->value);
    printf("%.0lf\n", curr->value);
}
List Merge(List L1, List L2){
    List L = DefineList();
    Node* Curr1 = L1.Head;
    Node* Curr2 = L2.Head;
    if(!Curr2) L = L1;
    else if (!Curr1) L = L2;
    else{
        while(Curr1!=NULL && Curr2!=NULL){
            if(Curr1->value < Curr2->value){
                if(!L.Head) Prepend(&L, CreateNode(Curr1->value));
                else Insert(&L, CreateNode(Curr1->value), L.Tail);
                Curr1 = Curr1->next;
            }
            else{
                if(!L.Head) Prepend(&L, CreateNode(Curr2->value));
                else Insert(&L, CreateNode(Curr2->value), L.Tail);
                Curr2 = Curr2->next;
            }
        }
        while(Curr1!=NULL){
            // if(!L.Head) Prepend(&L, CreateNode(Curr1->value));
            Insert(&L, CreateNode(Curr1->value), L.Tail);
            Curr1 = Curr1->next;
        }
        while(Curr2!=NULL){
            // if(!L.Head) Prepend(&L, CreateNode(Curr1->value));
            Insert(&L, CreateNode(Curr2->value), L.Tail);
            Curr2 = Curr2->next;
        }
    }
    return L;
}
int main(){
    int n1, n2;
    scanf("%d", &n1);
    List L1 = DefineList();
    double x;
    for(int i=0;i<n1;i++){
        scanf("%lf", &x);
        if(!L1.Head)Prepend(&L1, CreateNode(x));
        else Insert(&L1, CreateNode(x), L1.Tail);
    }
    List L2 = DefineList();
    scanf("%d", &n2);
    // double x;
    for(int i=0;i<n2;i++){
        scanf("%lf", &x);
        if(!L2.Head)Prepend(&L2, CreateNode(x));
        else Insert(&L2, CreateNode(x), L2.Tail);
    }
    PrintList(L1);
    PrintList(L2);
    List M = Merge(L1, L2);
    PrintList(M);
}