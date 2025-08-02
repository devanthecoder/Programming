#include <iostream>
#include <cmath>
using namespace std;
typedef struct Node{
    struct Node* next;
    double value;
} Node;
void PrintArray(double* arr, int n){
    cout << "[ ";
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "]" << endl;
}
void PrintList(Node* Head){
    for(Node* curr = Head; curr!=NULL; curr=curr->next) cout << curr->value << "->";
    cout << "NULL" << endl;
}
Node* InsertionSort(Node* head) {
    Node* sorted = NULL;
    while (head != NULL) {
        Node* curr = head;
        head = head->next;

        if (!sorted || curr->value < sorted->value) {
            curr->next = sorted;
            sorted = curr;
        } else {
            Node* temp = sorted;
            while (temp->next && temp->next->value < curr->value)
                temp = temp->next;
            curr->next = temp->next;
            temp->next = curr;
        }
    }
    return sorted;
}

double* BucketSort(double* A, int n){
    Node **B = new Node*[n];
    for(int i=0;i<n;i++) {
        B[i] = new Node;
        B[i]->next = NULL;
    }
    for(int i=0;i<n;i++) {
        Node* insert = new Node;
        insert->value=A[i];
        Node* temp = B[(int)floor(n*A[i])];
        while(temp->next!=NULL)temp=temp->next;
        temp->next = insert;
        insert->next = NULL;
    }
    for(int i=0;i<n;i++){
        Node* SortedBi = InsertionSort(B[i]->next);
        B[i]->next = SortedBi;
    }
    int index=0;
    for(int i=0;i<n;i++){
        Node* curr = B[i]->next;
        while(curr!=NULL){
            A[index] = curr->value;
            index++;
            curr=curr->next;
        }
    }
    return A;
}
int main(){
    int n;
    cin >> n;
    double* A = new double[n];
    cout << "Enter values for elements of array to be sorted such that their values are in the range [0,1): ";
    for(int i=0;i<n;i++) cin >> A[i];
    double* sortedA = BucketSort(A, n);
    PrintArray(sortedA, n);
}