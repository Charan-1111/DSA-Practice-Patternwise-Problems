/*
    Q. You are given the head of a singly linked list of positive integers. You have to check if the given linked list is palindrome or not.
        
    Example 1:
       Input:  1 2 3 2 1
       Output: 1
       
    Example 2:
        Input : 1 2 3 4 3 
        Output : 0
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
bool isPalindrome(Node *head) {
    vector<int> v;
    Node* curr = head;

    while(curr) {
        v.push_back(curr->data);
        curr = curr->next;
    }

    int l = 0, r = v.size()-1;

    while(l <= r) {
        if(v[l] != v[r]) return false;

        l++;
        r--;
    }

    return true;
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
    
   cout << "Is the linked list palindrome : " << isPalindrome(head) << endl;
    
    return 0;
}

// Time complexity - O(n)
// Space complexity - O(n)
