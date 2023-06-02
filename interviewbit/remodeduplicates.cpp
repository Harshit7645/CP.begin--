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
ListNode* solve(ListNode* A)
{
    ListNode* head1=NULL;
    ListNode* node=A;
    set<int>s;
    while(node!=NULL)
    {
        s.insert(node->val);
        node=node->next;
    }
    for(auto x:s)
    {
        append(&head1,x);
    }
    return head1;
}
int main()
{
    ListNode* head=NULL;
    append(&head,1);
    append(&head,1);
    append(&head,2);
    append(&head,2);
    append(&head,2);
    append(&head,3);
    append(&head,5);
    ListNode* x=solve(head);
   printList(x);
}   