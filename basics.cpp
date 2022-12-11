#include<bits/stdc++.h>
#include<iostream>
using namespace std;
 
 class Node{
    public: int data;
            Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
 };

 void insertAtEnd(Node* &head,int val){
   Node* n = new Node(val);
    if(head==NULL){
        head=n;
        return;
    }
   Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next =n;
 }

 void display(Node* &head){
    Node* temp = head;
    while(temp!= NULL){
        temp->data;
        cout<< temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
 }
 Node* reverse(Node* head){
    Node* prevptr = NULL;
    Node* cur_ptr = head;
    Node* Next_ptr;
    while(cur_ptr!=NULL){
        Next_ptr = cur_ptr->next;
        cur_ptr->next = prevptr;

        prevptr = cur_ptr;
        cur_ptr = Next_ptr;
    } 
    return prevptr;
 };
 Node *reverseRecursive(Node* head){
    if(head ==NULL || head->next ==NULL){
        return head;
    }

    Node* newlinked = reverseRecursive(head->next);
    head->next->next= head;
    head->next =NULL;

    return newlinked;
 }
 void insertAtHead(Node* &head, int val){
     Node* n = new Node(val);
     n->next= head;
     head = n;
 }
 bool search(Node* head, int key){
    Node* temp = head;
    while(temp!=NULL){
        if(temp->data == key){
            return true;
        }
        temp = temp->next; 
    }
    return false;
 }

 void deleteAtEnd(Node* &head){
    Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next--;
    temp->next = NULL;
 }
//  void deleteVal(Node* &head, int val){
//     if(head==NULL){
//         return;
//     }
//     if(head->next==NULL){
//         delelteAtHead(head);
//         return;
//     }
//     Node* temp =head;
//     while(temp->next->data!=val){
//         temp = temp->next;
//     }
//     Node* deleted = temp->next;
//     temp->next = temp->next->next;
//     delete deleted;
//  }
//  void delelteAtHead(Node* &head){
//     Node* temp1 = head;
//     head= head->next;
//     delete temp1;
//  }
  
 
int main()
{
    Node* head = NULL;
    insertAtEnd(head, 12);
    insertAtEnd(head, 15);
    insertAtEnd(head, 18);
    insertAtEnd(head, 21);

    display(head);
    insertAtHead(head, 9);
    display(head);
    cout<<search(head, 18)<<endl;
    // deleteAtEnd(head);
    // display(head);
    // deleteVal(head, 12);
    // display(head);
    // delelteAtHead(head);
    // display(head);
    // Node* newlinkedlist = reverse(head);
    // display(newlinkedlist);
    Node* reversed = reverseRecursive(head);
    display(reversed);
    return 0;
}
