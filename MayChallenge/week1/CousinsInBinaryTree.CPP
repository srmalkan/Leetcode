/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void depth(TreeNode* root,int x,int d,int &level){
        if(root==NULL || level){
            return;
        }
        if(x == root->val){
            level=d;
        }
        depth(root->left,x,d+1,level);
        depth(root->right,x,d+1,level);
        
    }
    bool isCousins(TreeNode* root, int x, int y) {
        if(root->val==x || root->val ==y){
            return false;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        int xd=0,px;
        while(!q.empty()){
            TreeNode *temp = q.front();
            q.pop();
            if(temp->left){
                if(temp->left->val==x){
                    px=temp->val;
                    break;
                }
                q.push(temp->left);
            }
            if(temp->right){
                if(temp->right->val==x){
                    px=temp->val;
                    break;
                }
                q.push(temp->right);
            }
            xd++;
        }
        while(!q.empty()){
            q.pop();
        }
        q.push(root);
        int yd=0,py;
        while(!q.empty()){
            TreeNode *temp = q.front();
            q.pop();
            if(temp->left){
                if(temp->left->val==y){
                    py=temp->val;
                    break;
                }
                q.push(temp->left);
            }
            if(temp->right){
                if(temp->right->val==y){
                    py=temp->val;
                    break;
                }
                q.push(temp->right);
            }
            yd++;
        }
        xd=0;
        yd=0;
        depth(root,x,0,xd);
        depth(root,y,0,yd);
        // cout<<xd<<" "<<px<<"\n";
        // cout<<yd<<" "<<py<<"\n";
        if(yd==xd && px!=py){
            return true;
        }
        return false;
    }
};


/*
In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

Return true if and only if the nodes corresponding to the values x and y are cousins.

 

Example 1:
         1
        / \
       2   3
      /
     4
Input: root = [1,2,3,4], x = 4, y = 3
Output: false
Example 2:
        1
       / \
      2   3
       \   \
        4   5

Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true

Note:

The number of nodes in the tree will be between 2 and 100.
Each node has a unique integer value from 1 to 100.
*/