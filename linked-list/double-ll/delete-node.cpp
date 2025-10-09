/*
    Q.You are given a Doubly Linked List and an integer x. Remove the node at position x (positions are 1-indexed) from the list, and return the head of the updated list.
        
    Example 1:
       Input:  1 1 2 3 4, 1
                
        Output: 1 2 3 4
*/

#include <bits/stdc++.h>

using namespace std;

struct Node {
  int data;
  Node* next;
  Node* prev;
};

Node* getNewNode(int data) {
    Node* newNode = new Node(); 
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    
    return newNode;
}

Node* insertIntoDLL(Node* head, int data) {
    Node* newNode = getNewNode(data);
    
    if(!head) return newNode;
    
    Node* curr = head;
    
    while(curr->next) {
        curr = curr->next;
    }
    
    curr->next = newNode;
    newNode->prev = curr;
    
    return head;
}

Node* deleteNode(Node* head, int x) {
        
    if(!head)
    return head;
    
    if(x == 1) {
        head = head->next;
        return head;
    }
    
    
    // Your code here
    Node* curr = head;
    
    int pos = 1;
    
    while(pos < x && curr){
        pos++;
        curr = curr->next;
    }
    
    if(curr->prev){
        curr->prev->next = curr->next;
    }
    
    if(curr->next){
        curr->next->prev = curr->prev;
    }
    
    return head;
}

int main() {
    int n;
    cout << "Enter the number of elements in the doubly linked list : ";
    cin >> n;
    
    Node* head = NULL;
    
    cout << "Enter the elements of the linked list in order : ";
    for(int i=0; i<n; i++) {
        int data;
        cin >> data;
        
        head = insertIntoDLL(head, data);
    }
    int pos;
    cout << "Enter the posisition at which the node to be deleted : ";
    cin >> pos;
    
    head = deleteNode(head, pos);
    Node* reverseHead = reverseDLL(head);
    
    return 0;
}

// Time complexity - O(n)
// Space complexity - O(sizeof(Node))
