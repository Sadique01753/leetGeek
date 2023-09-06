//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    
    int findPosition(int in[], int data, int start, int n)
    {
        for(int i=start; i<n; i++)
        {
            if(in[i] == data)
            return i;
        }
        return -1;
    }
    
    Node* findTree(int in[], int pre[], int &index, int start, int end, int size)
    {
        if(index >= size || start>end)
        {
            return NULL;
        }
            
        
        int rootData = pre[index];
        Node* node = new Node(rootData);
        index++;
        int position = findPosition(in, rootData, start, size);
        
        node->left = findTree(in, pre, index, start, position-1, size);
        node->right = findTree(in , pre, index, position+1, end, size);
        
        return node;
    }
    
    public:
    Node* buildTree(int in[],int pre[], int n)
    {
        int index = 0;
        Node* ans = findTree(in, pre, index, 0, n-1, n);
        
        return ans;
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
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends