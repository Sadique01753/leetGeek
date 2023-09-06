//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
//User function Template for C++

//Node Structure
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution{
  public:
  
    //The idea is to make a pair or type <int, int> and store sum including data of current node 
    //in pair.first and sum excluding current node data store in pair.second and return the pair.
    pair<int, int> findMaxSum(Node* root)
    {
        //base case
        //if root is NULL, sum including as well sum excluding current root is 0. thus return a pair<0, 0>
        if(root == NULL)
        {
            pair<int, int> p = make_pair(0, 0);
            return p;
        }
        
        //recursive call for left sub tree of the given tree
        pair<int, int> left = findMaxSum(root->left);
        //recursive call for right sub tree of the given tree
        pair<int, int> right = findMaxSum(root->right);
        
        //creating a pair result of <int, int> type
        pair<int, int> result;
        
        //calculating the sum for result.first which store sum including data of current data and
        //which is equal to current->node->data + pair.second return by previous recursive call
        result.first = root->data + left.second + right.second;
        
        //calculating the sum for result.second which store sum excluding data of current data and
        //which is equal to  the sum of max of pair.first and pair.second return by previous recursive call
        result.second = max(left.first, left.second) + max(right.first, right.second);
        
        return result;
    }
    
    //Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root) 
    {
        if(root == NULL)
            return 0;
            
        pair<int, int> ans = findMaxSum(root);
        
        return max(ans.first, ans.second);
    }
};

//{ Driver Code Starts.

// Driver code 
int main()
{
  int t;
  scanf("%d ",&t);
  while (t--)
  {
        string s;
		getline(cin,s);
		Node* root = buildTree(s);
		Solution ob;
        cout<<ob.getMaxSum(root)<<endl;
  }
  return 0;
}
// } Driver Code Ends