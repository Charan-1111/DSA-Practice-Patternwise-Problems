/*
    Q. You are given the head node of a singly linked list 'head'. Your task is to modify the linked list in such a way that all the even valued nodes appear before the all odd valued node and order of nodes remain the same.
        
    Example 1:
       Input:  1 2 3 2 1
       Output: 2 2 1 3 1
       
    Example 2:
        Input : 1 2 3 4 3 
        Output : 2 4 1 3 3
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
Node* insertNode(Node* head, int data) {
    Node* temp = (Node*) malloc(sizeof(Node));
    temp->data = data;
    temp->next = head;

    return temp;
}

Node* segregateEvenOdd(Node* head)
{
    vector<int> even;
    vector<int> odd;

    Node* curr = head;
    
    while(curr) {
        if(curr->data&1) {
            odd.push_back(curr->data);
        } else {
            even.push_back(curr->data);
        }

        curr = curr->next;
    }
    head = NULL;
    reverse(odd.begin(), odd.end());
    reverse(even.begin(), even.end());

    for(int val : odd) {
        head = insertNode(head, val);
    }

    for(int val : even) {
        head = insertNode(head, val);
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
    
    Node* newHead = segregateEvenOdd(head);
    
    return 0;
}

// Time complexity - O(n)
// Space complexity - O(n) ( extra space )

// See for better solution which can be done in one traversal without extra space
