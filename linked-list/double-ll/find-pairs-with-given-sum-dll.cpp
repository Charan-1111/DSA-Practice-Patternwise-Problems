/*
    Q. A doubly-linked list is a data structure that consists of sequentially linked nodes, and the nodes have reference to both the previous and the next nodes in the sequence of nodes.

        You are given a sorted doubly linked list of size 'n', consisting of distinct positive integers, and a number 'k'.

        Find out all the pairs in the doubly linked list with sum equal to 'k'.
        
    Example 1:
       Input:  1 2 3 4 9
               5
                
       Output: [{1,4}, {2,3}]
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

vector<pair<int, int>> findPairs(Node* head, int k){
    vector<pair<int, int>> res;
    Node* tail = head;

    while(tail->next) {
        tail = tail->next;
    }

    Node* curr = head;

    while(curr < tail) {
        int sum = curr->data + tail->data;
        if(sum == k) {
            res.push_back({curr->data, tail->data});
            curr = curr->next;
            tail = tail->prev;
        } else if(sum < k) {
            curr = curr->next;
        } else {
            tail = tail->prev;
        }
    }

    return res;
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
    
    int val;
    cout << "Enter the value of the sum to be find : ";
    cin >> val;
    
    vector<pair<int, int>> res = findPairs(head, val);
    
    return 0;
}

// Time complexity - O(n)
// Space complexity - O(1)
