#include <iostream>

using namespace std;

struct Node {
    Node* left = nullptr;
    Node* right = nullptr;
    int value = 0;
};

void makeTree(Node* root) {
    root->value = 1;

    Node* n1 = new Node;
    Node* n2 = new Node;
    Node* n3 = new Node;
    Node* n4 = new Node;
    Node* n5 = new Node;

    root->left = n1;
    root->right = n2;

    n1->left = n3;
    n1->right = n4;

    n3->left = new Node;
    n3 -> right = new Node;

    n2->left = n5;
    n2->right = new Node;
}

int ans = 0;
int sum_SubtreeDepths = 0;

void dfs(Node* r, int depth = 0) {
    ans += depth;

    if (r->left) {
        // cout << "going left " << "at depth : " << depth << endl;
        // cout << "Left node : " << r->left << endl;
        dfs(r->left, depth + 1);
    }

    if (r->right) {
        // cout << "going right " << "at depth : " << depth << endl;
        // cout << "Right node : " << r->right << endl;
        dfs(r->right, depth + 1);
    }
}

void sumOfDepths(Node* root) {
    dfs(root);
}

void sumOfSubtreeDepths(Node* root) {
    dfs(root);
    sum_SubtreeDepths += ans;
    ans = 0;

    if (root-> left) {
        sumOfSubtreeDepths(root->left);
    }

    if (root-> right) {
        sumOfSubtreeDepths(root->right);
    }
}

int main(int argc, char const* argv[])
{
    Node root;
    makeTree(&root);

    sumOfDepths(&root);
    cout << "Sum of depths : " << ans << endl;
    ans = 0;
    sumOfSubtreeDepths(&root);
    cout << "Sum of subtree depths : " << sum_SubtreeDepths;

    return 0;
}