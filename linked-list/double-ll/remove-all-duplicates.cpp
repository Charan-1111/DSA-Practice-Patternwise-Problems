/*
    Q. A doubly-linked list is a data structure that consists of sequentially linked nodes, and the nodes have reference to both the previous and the next nodes in the sequence of nodes.

        You are given a sorted doubly linked list of size 'n'.

        Remove all the duplicate nodes present in the linked list.
        
    Example 1:
       Input: 1 2 2 2 3
               
       Output: 1 2 3
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


// ================> Main Logic <================

Node * removeDuplicates(Node *head) {
    if(!head) return head;

    Node* curr = head->next;

    while(curr) {
        if(curr->data == curr->prev->data) {
            curr->prev->next = curr->next;

            if(curr->next) {
                curr->next->prev = curr->prev;
            }
        }

        curr = curr->next;
    }

    return head;
}

// ================> Main Logic <================

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
    
    head = removeDuplicates(head);
    
    return 0;
}

// Time complexity - O(n)
// Space complexity - O(1)
