/**
 *
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

int treeSum(TreeNode* root) {
    if (root == nullptr)
        return 0;
        
    int sum = root->val;

    if (root->left)
        sum += treeSum(root->left);

    if (root->right)
        sum += treeSum(root->right);
    
    return sum;
}

vector<int> findFrequentTreeSum(TreeNode* root) {
    unordered_map<int, int> sums;
    
    int sumRight = treeSum(root->right);
    int sumLeft = treeSum(root->left);
    int sum = root->val + sumRight + sumLeft;

    sums[sum]++;
    sums[sumRight]++;
    sums[sumLeft]++;


}

int main(int argc, char const* argv[])
{

    TreeNode node;
    node.val = 5;
    node.right = new TreeNode(-3);
    node.left = new TreeNode(2);

    for (int sum : findFrequentTreeSum(&node)) {
        cout << sum << "\n";
    }

    return 0;
}
