/*
    Q. Given a linked list of 'N' nodes, where each node has an integer value that can be 0, 1, or 2. You need to sort the linked list in non-decreasing order and the return the head of the sorted list.
        
    Example 1:
       Input:  1 0 2 1 0 2 1
       Output: 0 0 1 1 1 2 2
       
    Example 2:
        Input : 2 1 0 2 1 0 2 1 0 0 2
        Output : 0 0 0 0 1 1 1 2 2 2 2
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
Node* insert(Node* head, int data) {
    Node* temp = (Node*) malloc(sizeof(Node));
    temp->data = data;
    temp->next = head;

    return temp;
}

Node* sortList(Node *head){
    vector<int> v;
    Node* curr = head;

    while(curr) {
        v.push_back(curr->data);
        curr = curr->next;
    }

    int l = 0, mid = 0, r = v.size()-1;

    while(mid <= r) {
        if(v[mid] == 0) {
            swap(v[l], v[mid]);
            l++;
            mid++;
        } else if(v[mid] == 2) {
            swap(v[mid], v[r]);
            r--;
        } else {
            mid++;
        }
    }

    head = NULL;
    for(int i=v.size()-1; i>=0; i--) {
        head = insert(head, v[i]);
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
    
    head = sortLL(head);
    
    return 0;
}

// Time complexity - O(n)
// Space complexity - O(n * Sizeof(Node)) 

// Try for better approach than this
