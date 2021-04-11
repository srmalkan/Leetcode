class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m= matrix.size();
        int n= matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                dp[i][j]=-1;
            }
        }
        vector<vector<int>> dirs={{1,0},{0,1},{-1,0},{0,-1}};
        int longIncPath =0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(dp[i][j]==-1){
                    dp[i][j] = dfs(i,j,m,n,matrix,dp,dirs);
                }
                if(dp[i][j]>longIncPath){
                    longIncPath =dp[i][j];
                }
            }
        }
        
        return longIncPath;
        
    }
    
    int dfs(int p,int q,int m,int n,vector<vector<int>>& matrix,vector<vector<int>>& dp,vector<vector<int>> dirs){
        if(dp[p][q]!=-1){
            return dp[p][q];
        }
        dp[p][q]=1;
        for(int i=0;i<4;i++){
            int newp=p+dirs[i][0];
            int newq=q+dirs[i][1];
            if(newp<m && newp>=0 && newq<n && newq>=0){
                if(matrix[newp][newq]>matrix[p][q]){
                    int temp = 1+dfs(newp,newq,m,n,matrix,dp,dirs);
                    if(dp[p][q]<temp){
                        dp[p][q]=temp;
                    }
                }
            }
        }
        return dp[p][q];
    }
};