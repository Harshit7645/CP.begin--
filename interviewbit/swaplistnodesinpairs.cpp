#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
int M=1e9+7;

 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
void append(ListNode** head_ref, int new_data)
{
    // 1. allocate node
    ListNode* new_node = new ListNode(new_data);
 
    // Used in step 5
    ListNode* last = *head_ref;
 
    // 3. This new node is going to be
    // the last node, so make next of
    // it as NULL
    new_node->next = NULL;
 
    // 4. If the Linked List is empty,
    // then make the new node as head
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
 
    // 5. Else traverse till the last node
    while (last->next != NULL) {
        last = last->next;
    }
 
    // 6. Change the next of last node
    last->next = new_node;
    return;
}
ListNode* swapPairs(ListNode* A)
{
    ListNode* first=A,*second=A->next,*third=A->next->next;
    second->next=first;
    first->next=third;
    ListNode* node=second;
    while(node!=NULL)
    {
        cout<<node->val<<" ";
        node=node->next;
    }
    return node;
}
int main()
{
    ListNode* root=new ListNode(1);
    append(&root,2);
    append(&root,3);
    append(&root,4);
}   