/*
    Q. You are given two Singly Linked Lists of integers, which may have an intersection point.
       Your task is to return the first intersection node. If there is no intersection, return NULL.
        
    Example 1:
       Input:  4 1 -1
               5 6 -1
               8 -1
       Output: 8
*/

#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node * next;
    Node * prev;
};

Node * getNewNode(int data) {
    Node * newNode = new Node();
    newNode -> data = data;
    newNode -> next = NULL;
    newNode -> prev = NULL;

    return newNode;
}

Node * insertIntoDLL(Node * head, int data) {
    Node * newNode = getNewNode(data);

    if (!head) return newNode;

    Node * curr = head;

    while (curr -> next) {
        curr = curr -> next;
    }

    curr -> next = newNode;
    newNode -> prev = curr;

    return head;
}


// ================> Main Logic <================
Node* findIntersection(Node *firstHead, Node *secondHead) {
    unordered_map<Node*, int> mp;
    Node* curr = firstHead;

    while(curr) {
        mp[curr] = 1;
        curr = curr->next;
    }

    curr = secondHead;

    while(curr) {
        if(mp.find(curr) != mp.end()) return curr;

        curr = curr->next;

    }

    return NULL;
}
// ================> Main Logic <================

int main() {
    int n;
    cout << "Enter the number of elements in the doubly linked list : ";
    cin >> n;

    Node * head = NULL;

    cout << "Enter the elements of the linked list in order : ";
    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;

        head = insertIntoDLL(head, data);
    }

    head = sortList(head);

    return 0;
}

// Time complexity - O(n)
// Space complexity - O(n * Sizeof(Node)) 

// Try for better approach than this
