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
int getcount(ListNode *head)
{
    int cnt=0;
    while(head!=NULL)
    {
        head=head->next;
        cnt++;
    }
    return cnt;
}
ListNode* reverse(ListNode* head)
    {
        if (head == NULL || head->next == NULL)
            return head;
 
        /* reverse the rest list and put
          the first element at the end */
        ListNode* rest = reverse(head->next);
        head->next->next = head;
 
        /* tricky step -- see the diagram */
        head->next = NULL;
 
        /* fix the head pointer */
        return rest;
    }
int solve(ListNode *A)
{
    ListNode *head=A;
    ListNode *node=head;
    ListNode *newhead=NULL;
    int n=getcount(A);
    while(node!=NULL)
    {
        append(&newhead,node->val);
        node=node->next;
    }
    ListNode* current = newhead;
        ListNode *prev = NULL, *next = NULL;
 
        while (current != NULL) {
            // Store next
            next = current->next;
            // Reverse current node's pointer
            current->next = prev;
            // Move pointers one position ahead.
            prev = current;
            current = next;
        }
        newhead = prev;
    ListNode* revnode=newhead;
    node=head;
    rep(i,0,n)
    {
        if(revnode->val!=node->val)
        return 0;
        revnode=revnode->next;
        node=node->next;
    }
    printList(A);
    cout<<endl;
    printList(newhead);
    return 1;
}
int main()
{
    ListNode *head=NULL;
    append(&head,1);
    append(&head,1);
    append(&head,6);
    append(&head,4);    
    append(&head,1);
    // append(&head,5);
    // append(&head,7);
    // append(&head,4);
    // append(&head,3);//append(&head,3);
    cout<<solve(head);
} 