//{ Driver Code Starts
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


void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        temp = new Node(val);
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}




int getCountOfNode(Node *root, int l, int h)
{

    if (!root) return 0;


    if (root->data == h && root->data == l)
        return 1;

    if (root->data <= h && root->data >= l)
         return 1 + getCountOfNode(root->left, l, h) +
                    getCountOfNode(root->right, l, h);

    else if (root->data < l)
         return getCountOfNode(root->right, l, h);


    else return getCountOfNode(root->left, l, h);
}


bool isDeadEnd(Node *root);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node *root;
        Node *tmp;
    //int i;

        root = NULL;

        int N;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int k;
            cin>>k;
            insert(&root, k);

        }

        
     cout<<isDeadEnd(root);
     cout<<endl;
    }
}


// } Driver Code Ends


/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/

void solve(Node* root, unordered_set<int> &node, set<int> &leaf)
{
    if(root == NULL)
        return;
        
    if(root->left == NULL && root->right == NULL)
    {
        leaf.insert(root->data);
        return;
    }
    
    node.insert(root->data);
    
    solve(root->left, node, leaf);
    solve(root->right, node, leaf);
}

void checkDeadEnd(set<int> leaf, unordered_set<int> node, bool &ans)
{
    for(auto it=leaf.begin(); it!=leaf.end(); it++)
    {
        int temp = *it;
        int pre = temp - 1;
        int suc = temp + 1;
        
        if(temp == 1)
        {
            if(node.find(suc) != node.end())
            {
                ans = true;
            }
        }
        else
        {
            if(node.find(pre) != node.end() && node.find(suc) != node.end())
            {
                ans = true;
            }
        }
    }
}

/*You are required to complete below method */
bool isDeadEnd(Node *root)
{
    bool ans = false;
    if(root == NULL)
        return ans;
        
    unordered_set<int> node;
    set<int> leaf;
    
    solve(root, node, leaf);
    
    checkDeadEnd(leaf, node, ans);
    
    return ans;
}