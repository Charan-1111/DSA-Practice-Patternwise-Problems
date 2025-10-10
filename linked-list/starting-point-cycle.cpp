/*
    Q. You are given a singly linked list that may or may not contain a cycle. You are supposed to return the node where the cycle begins, if a cycle exists, else return 'NULL'.

        A cycle occurs when a node's next pointer returns to a previous node in the list.
        
    Example 1:
       Input:  1 2 3 4 -1
               1
                
        Output: 1
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

Node* firstNode(Node *head)
{
    if(head == NULL) return head;

    //    Write your code here.
    Node* slow = head;
    Node* fast = head;
    bool loopFound = false;

    while(fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) {
            loopFound = true;
            break;
        }
    }

    if(!loopFound) return NULL;

    fast = head;

    while(fast != slow) {
        slow = slow->next;
        fast = fast->next;
    }

    return fast;
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
    
    Node* loopStart = firstNode(head);
    
   cout << "Starting point of lopp is : " << loopStart->data << endl; 
    
    return 0;
}

// Time complexity - O(n)
// Space complexity - O(sizeof(Node))
