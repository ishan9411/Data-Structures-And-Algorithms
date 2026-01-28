#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data){
        val = data;
        left = NULL;
        right = NULL;
    }
};

TreeNode* insertBST(TreeNode* root, int num){
    if(root == NULL){
        return new TreeNode(num);
    }

    if(root->val > num){
        root->left = insertBST(root->left, num);
    }

    if(root->val < num){
        root->right = insertBST(root->right, num);
    }

    return root;
}

void preorder(TreeNode* root){
    if(root == NULL){
        return;
    }
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

int main(){
    vector<int> arr = {10, 2, 15, 3, 8, 11, 4, 14};

    TreeNode* root = new TreeNode(arr[0]);

    for(int i = 1; i<arr.size(); i++){
        insertBST(root, arr[i]);
    }

    preorder(root);

}