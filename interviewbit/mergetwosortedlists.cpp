#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
struct ListNode{
    int val;
    ListNode *next;
};
void push(struct ListNode** head_ref, int new_data)
{
    /* 1. allocate node */
    // 1. allocate node
    ListNode* new_node = new ListNode(); 
  
    // 2. put in the data
    new_node->val = new_data; 
  
    // 3. Make next of new node as head
    new_node->next = (*head_ref); 
  
    // 4. Move the head to point to 
    // the new node
    (*head_ref) = new_node;
}
void insertAfter(ListNode* prev_node, int new_data)
{
  
    // 1. Check if the given prev_node is NULL
    if (prev_node == NULL) {
        cout << "The given previous node cannot be NULL";
        return;
    }
  
    // 2. Allocate new node
    ListNode* new_node = new ListNode();
  
    // 3. Put in the data
    new_node->val = new_data;
  
    // 4. Make next of new node as
    // next of prev_node
    new_node->next = prev_node->next;
  
    // 5. move the next of prev_node
    // as new_node
    prev_node->next = new_node;
}
void append(ListNode** head_ref, int new_data)  
{  
    
    // 1. allocate node 
    ListNode* new_node = new ListNode(); 
    
    // Used in step 5 
    ListNode *last = *head_ref; 
    
    // 2. Put in the data 
    new_node->val = new_data;  
    
    // 3. This new node is going to be  
    // the last node, so make next of  
    // it as NULL
    new_node->next = NULL;  
    
    // 4. If the Linked List is empty, 
    // then make the new node as head 
    if (*head_ref == NULL)  
    {  
        *head_ref = new_node;  
        return;  
    }  
    
    // 5. Else traverse till the last node 
    while (last->next != NULL)
    {
        last = last->next;  
    }
    
    // 6. Change the next of last node 
    last->next = new_node;  
    return;  
}
void printList(ListNode *node) 
{ 
    while (node != NULL) 
    { 
        cout<<" "<<node->val; 
        node = node->next; 
    } 
}
ListNode* solve(ListNode*A ,ListNode* B)
{
    if(!A)
        return B;
    if(!B)
        return A;
    ListNode* headone=A;
    ListNode* headtwo=B;
    ListNode* node1=headone;
    ListNode* node2=headtwo;
    ListNode *res = new ListNode();
    while(node1!=NULL && node2!=NULL)
    {
        if(node1->val<node2->val)
        {
            res->next=node1;
            node1=node1->next;
        }
        else
        {
            res->next=node2;
            node2=node2->next;
        }

    }
    while(node1!=NULL)
    {
        res->val=node1->val;
        res->next=node1;
        node1=node1->next;
    }
    while(node2!=NULL)
    {
        res->val=node2->val;
        res->next=node2;
        node2=node2->next;
    }
    return res;
}
int main()
{
    ListNode* head=new ListNode();
    ListNode* node=head;
    rep(i,0,5)
    {
        node->val=i;
        node->next=NULL;
        node=node->next;
    }
    printList(head);
}   