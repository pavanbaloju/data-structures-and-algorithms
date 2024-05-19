#include <iostream>
#include <vector>
using namespace std;

// Definition of TreeNode structure representing a TreeNode in the binary tree
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *next;
    TreeNode() : val(0), left(nullptr), right(nullptr), next(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
};


// Function to construct BST from pre order traversal brute force
TreeNode *bstFromPreorderBrute(vector<int> &preorder)
{
    // If the pre-order traversal is empty, return null
    if (preorder.empty())
        return nullptr;

    // Create a new TreeNode with the first element of the pre-order traversal as the root
    TreeNode *root = new TreeNode(preorder[0]);

    // Create a vector to store the elements less than the root
    vector<int> left;
    // Create a vector to store the elements greater than the root
    vector<int> right;

    // Iterate through the pre-order traversal starting from the second element
    for (int i = 1; i < preorder.size(); i++)
    {
        // If the current element is less than the root, add it to the left vector
        if (preorder[i] < root->val)
            left.push_back(preorder[i]);
        // If the current element is greater than the root, add it to the right vector
        else
            right.push_back(preorder[i]);
    }

    // Recursively construct the left and right subtrees
    root->left = bstFromPreorderBrute(left);
    root->right = bstFromPreorderBrute(right);

    // Return the root of the BST
    return root;
}

// Function to construct BST from pre order traversal
TreeNode *bstFromPreorder(vector<int> &preorder, int &index, int upperBound)
{
    // If the current index exceeds the upperBound or the value at the current index is greater than the upperBound, return null
    if (index == preorder.size() || preorder[index] > upperBound)
        return nullptr;

    // Create a new TreeNode with the value at the current index
    TreeNode *root = new TreeNode(preorder[index]);

    // Increment the index to move to the next element in the pre-order traversal
    index++;

    // Recursively construct the left and right subtrees
    root->left = bstFromPreorder(preorder, index, root->val);
    root->right = bstFromPreorder(preorder, index, upperBound);

    // Return the root of the BST
    return root;
}

// Function to construct BST from pre-order traversal
TreeNode *bstFromPreorder(vector<int> &preorder)
{
    // Initialize the index to 0 and the upperBound to INT_MAX
    int index = 0, upperBound = INT_MAX;

    // Call the recursive function to construct the BST from the pre-order traversal
    return bstFromPreorder(preorder, index, upperBound);
}

// Function to print the in-order traversal of the BST
void inorder(TreeNode *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main()
{
    // Input pre-order traversal of the BST
    vector<int> preorder = {8, 5, 1, 7, 10, 12};

    // Construct the BST from the pre-order traversal
    TreeNode *root = bstFromPreorder(preorder);

    // Print the in-order traversal of the BST
    inorder(root);
    cout << endl;

    // Construct the BST from the pre-order traversal using brute force
    root = bstFromPreorderBrute(preorder);

    // Print the in-order traversal of the BST
    inorder(root);

    return 0;
}