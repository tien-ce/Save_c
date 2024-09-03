#include <iostream>
#include <cmath>
#include<vector>
#include<utility>
using namespace std;

class BTNode {
    public: 
        int val; 
        BTNode *left; 
        BTNode *right; 
        BTNode() {
            this->left = this->right = NULL;
        } 
        BTNode(int val) {
            this->val = val;
            this->left = this->right = NULL;
        } 
        BTNode(int val, BTNode*& left, BTNode*& right) {
            this->val = val;
            this->left = left;
            this->right = right;
        } 
        

};
BTNode* createTree(int parent[], int n, int value[]) {
    vector<BTNode*> nodes(n);
    for (int i = 0; i < n; ++i) {
        nodes[i] = new BTNode(value[i]);
    }
    BTNode* root = nullptr;
    for (int i = 0; i < n; ++i) {
        if (parent[i] == -1)
            root = nodes[i];
        else {
            BTNode* ptr = nodes[parent[i]];
            if (ptr->left == nullptr)
                ptr->left = nodes[i];
            else
                ptr->right = nodes[i];
        }
    }
    return root;
}
pair<int,int> longestPathSum1(BTNode* &root){
    if(root==nullptr)
    return make_pair(0,0);
    pair<int,int> left = longestPathSum1(root->left);
    pair<int,int> right = longestPathSum1(root->right);
    if(left.first>right.first){
        return make_pair(1+left.first,root->val+left.second);
    }
    else if(left.first<right.first){
           return make_pair(1+right.first,root->val+right.second);
    }
    else 
    {
        if(left.second>right.second){
            return make_pair(1+left.first,root->val+left.second);
        }
        else{
              return make_pair(1+right.first,root->val+right.second);
        }
    }
}
int longestPathSum(BTNode* root) {
    return longestPathSum1(root).second;
}
int main(){
	int arr[] = {-1,0,0,2,2,3,3,5};
int value[] = {1,5,4,7,12,4,8,2};
BTNode* root = createTree(arr, sizeof(arr)/sizeof(int), value);
cout << longestPathSum(root);
}
// STUDENT ANSWER END
