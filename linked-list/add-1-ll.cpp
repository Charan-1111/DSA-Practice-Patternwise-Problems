/*
    Q. You are given a linked list where each element in the list is a node and have an integer data. You need to add 1 to the number formed by concatinating all the list node numbers together and return the head of the modified linked list. 

        Note: The head represents the first element of the given array.
        
    Example 1:
       Input:   1 5 2
       Output: 1 5 3
       
    Example 2:
        Input : 9 9
        Output : 1 0 0
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
Node* reverse(Node* head) {
    Node* prev = NULL;

    while(head->next) {
        Node* temp = head->next;
        head->next = prev;
        prev = head;
        head = temp;
    }

    head->next = prev;

    return head;
}

Node* addOne(Node *head) {
    head = reverse(head);

    Node* curr = head;
    Node* prev = NULL;

    int carry = 1;

    while(curr) {
        int val = curr->data + carry;
        curr->data = val%10;
        carry = val/10;
        prev = curr;
        curr = curr->next;
    }

    while(carry) {
        int val = carry%10;
        carry /= 10;

        curr = new Node();
        curr->data = val;
        curr->next = NULL;
        prev->next = curr;
        prev = curr;
        curr = curr->next;
    }

    return reverse(head);
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
    
    head = addOne(head);
    
    return 0;
}

// Time complexity - O(n)
// Space complexity - O(n * Sizeof(Node)) 

// Try for better approach than this
