class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        pair<int,int> total={0,0};
        dfs(root,total,0);
        return total.second;
        
    }
    void dfs(TreeNode* root, pair<int,int>& total,int level){
        if(root->right==NULL && root->left==NULL){
            if(level>total.first){
                total.first = level;
                total.second = root->val;
            }else if(level == total.first){
                total.second +=root-> val;
            }
            
        }
        if(root->right!=NULL){
            dfs(root->right,total,level+1);
        }
        if(root->left!=NULL){
            dfs(root->left,total,level+1);
        }

    }
};