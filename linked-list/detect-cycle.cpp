/*
    Q.You are given a Singly Linked List of integers. Return true if it has a cycle, else return false.
    
      A cycle occurs when a node's next points back to a previous node in the list.
        
    Example 1:
       Input:  1 2 3 4 -1
               1
                
        Output: true
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

bool detectCycle(Node *head) {
    if(head == NULL) return head;
	//	Write your code here
    Node* fast = head;
    Node* slow = head;

    while(fast->next && fast->next->next) {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow) {
            return true;
        }

    }

    return false;
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
    
   cout << "Is there any loop : " << detectCycle(head) << endl; 
    
    return 0;
}

// Time complexity - O(n)
// Space complexity - O(sizeof(Node))
