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

void pushhead(struct ListNode** head_ref, int new_data)
{
    /* 1. allocate node */
    struct ListNode* new_node = (struct ListNode*) malloc(sizeof(struct ListNode));
   
    /* 2. put in the data  */
    new_node->val  = new_data;
   
    /* 3. Make next of new node as head */
    new_node->next = (*head_ref);
   
    /* 4. move the head to point to the new node */
    (*head_ref)    = new_node;
}

void insertAfter(struct ListNode* prev_node, int new_data)
{
    /*1. check if the given prev_node is NULL */
    if (prev_node == NULL)
    {
      printf("the given previous node cannot be NULL");
      return;
    }
  
    /* 2. allocate new node */
    struct ListNode* new_node =(struct ListNode*) malloc(sizeof(struct ListNode));
  
    /* 3. put in the data  */
    new_node->val  = new_data;
  
    /* 4. Make next of new node as next of prev_node */
    new_node->next = prev_node->next;
  
    /* 5. move the next of prev_node as new_node */
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
struct comp
{
    bool operator()(ListNode* const A,ListNode* const B)
    {
        return A->val>B->val;
    }
};

ListNode* solve(vector<ListNode*>A)
{
    int n=A.size();
    priority_queue<ListNode*,vector<ListNode*>,comp>pq;
    rep(i,0,n)
    {
        if(A[i]!=NULL)
        pq.push(A[i]);
    }
    ListNode* res=new ListNode(0);
    ListNode* resnode=res;
    while(!pq.empty())
    {
        resnode->next=pq.top();
        pq.pop();
        resnode=resnode->next;
        if(resnode->next)
        pq.push(resnode->next);
    }
    return res->next;
}
int main()
{
    ListNode* a=NULL;
    ListNode* b=NULL;
    ListNode* c=NULL;
    append(&a,1);
    append(&a,10);
    append(&a,20);
    append(&b,4);
    append(&b,11);
    append(&b,13);
    append(&c,3);
    append(&c,8);
    vector<ListNode*>x;
    x.push_back(a);
    x.push_back(b);
    x.push_back(c);
    ListNode *finalans=solve(x);
    printList(finalans);
}   