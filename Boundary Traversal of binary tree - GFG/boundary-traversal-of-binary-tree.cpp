//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

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
/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
private:
    //function that returns true only when the passed node is a leaf node
    bool isLeaf(Node* root) {
        return root->left == NULL && root->right == NULL;
    }
    
    //function to return the leftBoundary traversal excluding the root node and leaf nodes
    void leftBoundary(Node* root, vector<int> &res) {
        Node* curr = root->left;
        
        while(curr != NULL) {
            if(isLeaf(curr) == false) res.push_back(curr->data);
            if(curr->left) curr = curr->left;
            else curr = curr->right;
        }
    }
    
    //function to return the leaf nodes
    void leafBoundary(Node* root, vector<int> &res) {
        if(isLeaf(root)){
            res.push_back(root->data);
            return;
        }
        
        if(root->left) leafBoundary(root->left, res);
        if(root->right) leafBoundary(root->right, res);
        
    }
    
    //function to return the rightBoundary traversal excluding the root node and the leaf nodes
    void rightBoundary(Node* root, vector<int> &res) {
        stack<int> st; //Because we neeed to return in reverse order.
        
        Node* curr = root->right;
        
        while(curr != NULL) {
            if(isLeaf(curr) == false) st.push(curr->data);
            if(curr->right) curr = curr->right;
            else curr = curr->left;
        }
        
        //yeh sahi order kar dega elements ka
        while(!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
    }
    
public:
    vector <int> boundary(Node *root)
    {   
        vector<int> res;
        
        if(root == NULL) return res;
        if(isLeaf(root) == false) res.push_back(root->data);
        
        leftBoundary(root, res);
        leafBoundary(root, res);
        rightBoundary(root, res);
        
        return res;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.boundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends