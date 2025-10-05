/*
    Representing and inserting a node at the end of the linked list;
    Follow up Inserting node at begin of the linked list and at a given position
*/

#include <bits/stdc++.h>

using namespace std;

struct Node {
  int data;
  Node* next;
};

Node* getNewNode(int data) {
    Node* temp = new Node(); // alternative using malloc ( Node* temp = (Node*) malloc(sizeof(Node)))
    temp->data = data;
    temp->next = NULL;
    
    return temp;
}


Node* insertAtEnd(Node* head, int data) {
    Node* temp = getNewNode(data);
    
    if(!head) return temp;
    
    Node* curr = head; // using so that the head is not changed;
    while(curr->next) {
        curr = curr->next;
    }
    
    curr->next = temp;
    
    return head;
}

Node* insertAtBegin(Node* head, int data) {
    Node* temp = getNewNode(data);
    
    temp->next = head;
    
    return temp;
}

Node * insertAtGivenPosition(Node * head, int pos, int data) {
    Node* temp = getNewNode(data);

    if(pos == 0) {
        temp->next = head;
        return temp;
    }

    Node* curr = head;
    Node* prev = NULL;

    while(pos != 0) {
        prev = curr;
        curr = curr->next;
        pos--;
    }

    prev->next = temp;
    temp->next = curr;
    
    return head;
}

int main() {
    int n;
    cout << "Enter the number of elements to be present in the linked list : ";
    cin >> n;
    
    Node* head1 = NULL; // this will be the head pointer for the LL whose elements are inserted at the end.
    
    Node* head2 = NULL; // this will be the head pointer for the LL whose elements are inserted at the beggining.
    
    cout << "Enter the elements in order : ";
    for(int i=0; i<n; i++) {
        int data;
        cin >> data;
        
        // inserting the nodes at the end of the linked list.
        head1 = insertAtEnd(head1, data);
        
        // inserting the nodes at the beggining of the linked list;
        head2 = insertAtBegin(head2, data);
    }
    
    cout << "Linked list after inserting the elements at the end are : ";
    Node* curr = head1;
    while(curr->next) {
        cout << curr->data << "->";
        curr = curr->next;
    }
    cout << curr->data << endl;
    
    cout << "Linked list after inserting the elements at the begginging are : ";
    curr = head2;
    while(curr->next) {
        cout << curr->data << "->";
        curr = curr->next;
    }
    cout << curr->data << endl;
    
    // Final follow up :- inserting the element at a given position
    
    int data, pos;
    
    cout << "Enter the value and posistion to insert in the LL : ";
    cin >> data >> pos;
    
    head1 = insertAtGivenPosition(head1, pos, data);
    
    cout << "LL after inserting at a given posision : ";
    curr = head1;
    while(curr->next) {
        cout << curr->data << "->";
        curr = curr->next;
    }
    cout << curr->data << endl;
    
    return 0;
}

/*
    Time complexity to insert the node at end and a given position of LL is : O(n)
    Time complexity to insert at begining of the LL is : O(1)
    
    Space complexity - O(n*sizeof(Node))
*/
