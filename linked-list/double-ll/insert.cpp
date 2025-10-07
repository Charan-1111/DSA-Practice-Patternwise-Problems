/*
    Q. You are given a Doubly linked list, where every node in the linked list contains two pointers ‘next’ and ‘prev’ which point to the next node and previous node in the list respectively. All nodes have some positive integer value associated with them. Your task is to insert an integer value ‘VAL’ in the linked list at a given position ‘K’.

        Note:
        
        The position given will always be less than or equal to the length of the linked list.
        Assume that the Indexing for the linked list starts from 0.
        
    Example 1:
       Input:  0 0
               1 2 3 4 -1
                
        Output: 0 1 2 3 4 -1
        
    Example 2:
        Input: 5 5
               5 4 3 2 1 -1
               
        Output: 5 4 3 2 1 5
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

Node* insertAtGivenPos(int k, int val, Node *head) {
    Node* temp = (Node*) malloc(sizeof(Node));
    temp->data = val;
    temp->next = NULL;
    temp->prev = NULL;

    if(k == 0) {
        temp->next = head;
        head->prev = temp;

        return temp;
    }
    
    Node* curr = head;

    int curr_pos = 0;
    
    while(curr_pos < k-1) {
        curr = curr->next;
        curr_pos++;
    }

    temp->next = curr->next;
    temp->prev = curr;

    if(curr->next) {
        curr->next->prev = temp;
    }

    curr->next = temp;

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
    
    int val, pos;
    cout << "Enter the value to insert and the position to insert : ";
    cin >> val >> pos;
    
    Node* head = insertAtGivenPos(pos, val, head);
    
    return 0;
}

// Time complexity - O(n)
// Space complexity - O(sizeof(Node))
