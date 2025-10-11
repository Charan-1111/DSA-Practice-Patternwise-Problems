/*
    Q. Given a singly linked list of 'N' nodes. Your task is to delete the middle node of this list and return the head of the modified list.

        However, if the list has an even number of nodes, we delete the second middle node
        
    Example 1:
       Input:  1 2 3 4 5
       Output: 1 2 4 5
       
    Example 2:
        Input : 1 
        Output : -1
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
Node* deleteMiddle(Node* head){
    if(!head->next) {
        return NULL;
    }
    
    Node* slow = head;
    Node* fast = head;
    Node* prev = NULL;

    while(fast->next && fast->next->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    if (fast->next) {
        slow->next = slow->next->next;
    } else {
        prev->next = slow->next;
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
    
    head = deleteMiddle(head);
    
    return 0;
}

// Time complexity - O(n)
// Space complexity - O(1) 
