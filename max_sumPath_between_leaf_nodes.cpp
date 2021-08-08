#include <bits/stdc++.h>

using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

// **********
// int maxPathSum_helper(Node* root, int &sum){
//         if(!root)
//             return 0;
        
//         int leftSum = INT_MIN, rightSum = INT_MIN;
        
//         if(root->left)
//             leftSum = maxPathSum_helper(root->left, sum);
//         if(root->right)
//             rightSum = maxPathSum_helper(root->right, sum);
        
//         if(root->left && root->right)
//             sum = max(sum, leftSum + rightSum + root->data);
        
//         int x = max(leftSum, rightSum);
//         if(x == INT_MIN)
//             x = 0;
        
//         return x + root->data;
//     }

//     int maxPathSum(Node* root)
//     {   
//         if(root){
//             int maxSum = std::numeric_limits<int>::min();
            
//             maxPathSum_helper(root, maxSum);
            
//             return maxSum;
//         }
//         return 0;
//     }
// **********

class Solution {
public:
    int result = INT_MIN;
    int Solve(Node* root){
        if(root == NULL)
            return 0;
        int L = Solve(root->left);
        int R = Solve(root->right);
        if(root->left != NULL and root->right != NULL){
            int max_single = max(L, R)+root->data;
            int max_double = L+root->data+R;
            result = max(result, max_double);
            return max_single;
        }
        else if(root->left != NULL)
            return L+root->data;
        else
            return R+root->data;
    }
    
    int maxPathSum(Node* root)
    {
        int X = Solve(root);
        if(result == INT_MIN)
            result = X;
        return result;
    }
};

// { Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        Solution ob;
        cout << ob.maxPathSum(root) << "\n";
    }
    return 0;
}  // } Driver Code Ends