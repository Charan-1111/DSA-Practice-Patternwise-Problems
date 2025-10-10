/*
    Q. You’re given a linked list. The last node might point to null, or it might point to a node in the list, thus forming a cycle.

        Find out whether the linked list has a cycle or not, and the length of the cycle if it does.

        If there is no cycle, return 0, otherwise return the length of the cycle.
        
    Example 1:
       Input:  4 10 3 5
               2
                
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


// ================> Main Logic <================

int lengthOfLoop(Node *head) {
    Node* slow = head;
    Node* fast = head;

    bool loopFound = false;

    while(fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;

        if(fast == slow) {
            loopFound = true;
            break;
        }
    }

    if(!loopFound) return 0;

    Node* curr = slow->next;
    int len = 1;

    while(curr != slow) {
        len = len+1;
        curr = curr->next;
    }

    return len;
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
    
    int lengthOfLoop = lengthOfLoop(head);
    
   cout << "Length of the loop in Linked List is : " << lengthOfLoop << endl;
    
    return 0;
}

// Time complexity - O(n)
// Space complexity - O(sizeof(Node))
