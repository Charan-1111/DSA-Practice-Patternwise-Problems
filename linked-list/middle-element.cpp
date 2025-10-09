/*
    Q.You are given the head of a linked list, You have to return the value of the middle node of the linked list.

            - If the number of nodes is odd, return the middle node value.
            - If the number of nodes is even, there are two middle nodes, so return the second middle node value.
        
    Example 1:
       Input:  1 2 3 4 5
                
        Output: 3
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

int getMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head;
    
    while(fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return fast->next != NULL ? slow->next->data : slow->data;
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
    
    int midVal = getMiddle(head);
    
    cout << "Middle element of the linked list : " << midVal << endl;
    
    return 0;
}

// Time complexity - O(n)
// Space complexity - O(sizeof(Node))
