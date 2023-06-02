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
int solve(ListNode *A,int B)
{
    ListNode* head=A;
    ListNode* node=head;
    vector<int>v;
    int n=0;
    while(node!=NULL)
    {
        v.push_back(node->val);
        n++;
        node=node->next;
    }
    int mid=n/2+1;
    if(mid-B-1<0)
    return -1;
    else
    return v[mid-B-1];
}
int main()
{
    ListNode *head=NULL;
    append(&head,3);
    append(&head,4);
    append(&head,7);
    append(&head,5);
    append(&head,6);
    append(&head,16);
    append(&head,51);
    append(&head,61);
    append(&head,16);//append(&head,3);
    cout<<solve(head,3);
} 