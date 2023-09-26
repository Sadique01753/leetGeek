//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct LNode
{
    int data;
    struct LNode* next;
    
    LNode(int x){
        data = x;
        next = NULL;
    }
};

struct TNode  
{  
    
    int data;  
    struct TNode* left;  
    struct TNode* right; 
    TNode(int x)
    {
        data=x;
        left=right=NULL;
    }
}; 

void preOrder(TNode* node)  
{  
    if (node == NULL)  
        return;  
    cout<<node->data<<" ";  
    preOrder(node->left);  
    preOrder(node->right);  
} 


// } Driver Code Ends
//User function Template for C++


//User function Template for C++

/* 
//Linked List
struct LNode
{
    int data;
    struct LNode* next;
    
    LNode(int x){
        data = x;
        next = NULL;
    }
};

//Tree
struct TNode  
{  
    
    int data;  
    struct TNode* left;  
    struct TNode* right; 
    TNode(int x)
    {
        data=x;
        left=right=NULL;
    }
}; */
class Solution{
  public:
    
    int findSize(LNode* head)
    {
        LNode* temp = head;
        int count = 0;
        
        while(temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }
    
    TNode* createTree(LNode* &head, int n)
    {
        if(n <= 0 || head == NULL)
            return NULL;
            
        TNode* leftTree = createTree(head, n/2);
        
        TNode* root = new TNode(head->data);
        
        root->left = leftTree;
        
        head = head->next;
        
        root->right = createTree(head, (n - n/2 -1));
        
        return root;
    }
    
    TNode* sortedListToBST(LNode *head) {
        
        TNode* root = NULL;
        
        if(head == NULL)
            return root;
            
        int size = findSize(head);
        
        root = createTree(head, size);
        
        return root;
        
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;

        int data;
        cin>>data;
        LNode *head = new LNode(data);
        LNode *tail = head;
        for (int i = 0; i < n-1; ++i)
        {
            cin>>data;
            tail->next = new LNode(data);
            tail = tail->next;
        }
        Solution ob;
        TNode* Thead = ob.sortedListToBST(head);
        preOrder(Thead);
        cout<<"\n";
        
    }
    return 0;
}

// } Driver Code Ends