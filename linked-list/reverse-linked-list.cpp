/*
    Q.You are given the head of a singly linked list. You have to reverse the linked list and return the head of the reversed list.
        
    Example 1:
       Input:  1 2 3 4 5
                
        Output: 5 4 3 2 1
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

Node* reverseLinkedList(Node *head) {
    Node* prev = NULL;

    while(head) {
        Node* next = head->next;
        
        head->next = prev;
        prev = head;
        head = next;
    }

    return prev;
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
    
    head = reverseLinkedList(head);
    
    return 0;
}

// Time complexity - O(n)
// Space complexity - O(sizeof(Node))
