/*
    Q.You are given a doubly-linked list of size 'N', consisting of positive integers. Now your task is to reverse it and return the head of the modified list.

    Note:
    A doubly linked list is a kind of linked list that is bidirectional, meaning it can be traversed in both forward and backward directions.
        
    Example 1:
       Input:  1 2 3 4 5 6 7 8 9
                
        Output: 9 8 7 6 5 4 3 2 1
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

Node* reverseDLL(Node* head) {   
    Node* curr = head;

    while(curr) {
        Node* temp = curr->next;
        curr->next = curr->prev;
        curr->prev = temp;
        head = curr;
        curr = temp;
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
    
    Node* reverseHead = reverseDLL(head);
    
    return 0;
}

// Time complexity - O(n)
// Space complexity - O(sizeof(Node))
