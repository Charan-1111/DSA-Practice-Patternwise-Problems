/*
    Q. You are given two non-negative numbers 'num1' and 'num2' represented in the form of linked lists.

        The digits in the linked lists are stored in reverse order, i.e. starting from least significant digit (LSD) to the most significant digit (MSD), and each of their nodes contains a single digit.

       Calculate the sum of the two numbers and return the head of the sum list.
        
    Example 1:
       Input:   1 2 3
                4 5 6
       Output:  5 7 9
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
    Node* curr = head;
    Node* prev = NULL;

    while(curr) {
        Node* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }

    return prev;
}

Node* insert(Node* head, int data) {
    Node* temp = (Node*) malloc(sizeof(Node));
    temp->data = data;
    temp->next = head;

    return temp;
}

Node* addTwoNumbers(Node *num1, Node *num2) {

    Node* curr1 = num1;
    Node* curr2 = num2;

    int carry = 0;

    Node* head = NULL;

    while(curr1 && curr2) {
        int sum = curr1->data + curr2->data + carry;
        int rem = sum % 10;
        carry = sum / 10;

        head = insert(head, rem);

        curr1 = curr1->next;
        curr2 = curr2->next;
    }

    while(curr1) {
        int sum = curr1->data + carry;
        int rem = sum % 10;
        carry = sum / 10;

        head = insert(head, rem);

        curr1 = curr1->next;
    }

    while(curr2) {
        int sum = curr2->data + carry;
        int rem = sum % 10;
        carry = sum / 10;

        head = insert(head, rem);

        curr2 = curr2->next;
    }

    while(carry) {
        int rem = carry % 10;
        carry /= 10;

        head = insert(head, rem);
    }

    head = reverse(head);

    return head;
}
// ================> Main Logic <================

int main() {
    int n;
    cout << "Enter the number of elements in the first linked list : ";
    cin >> n;
    
    Node* head = NULL;
    
    cout << "Enter the elements of the linked list in order : ";
    for(int i=0; i<n; i++) {
        int data;
        cin >> data;
        
        head = insertIntoDLL(head, data);
    }
    
    int m;
    cout << "Enter the number of elements in second linked list : ";
    cin >> m;
    
    Node* head2 = NULL;
    cout << "Enter the elements of the linked list in order : ";
    for(int i=0; i<m; i++){
        int data;
        cin >> data;
        head2 = insertIntoDLL(head2, data);
    }
    head = addTwoNumbers(head, head2);
    
    return 0;
}

// Time complexity - O(n)
// Space complexity - O(n * Sizeof(Node)) 

// Try for better approach than this
