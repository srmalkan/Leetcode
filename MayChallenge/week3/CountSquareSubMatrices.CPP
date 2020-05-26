class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n=matrix[0].size();
        int sum=0;
        while (m!=1 && n!=1){
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(matrix[i][j]==1){
                        sum+=1;   
                    }
                }
            }
            vector<vector<int>> temp(m-1,vector<int>(n-1));
            for(int i=0;i<m-1;i++){
                for(int j=0;j<n-1;j++){
                    if(matrix[i][j]+matrix[i+1][j]+matrix[i][j+1]+matrix[i+1][j+1]==4){
                        temp[i][j]=1;
                    }else{
                        temp[i][j]=0;
                    }
                }
            }
            for(int i=0;i<m-1;i++){
                for(int j=0;j<n-1;j++){
                    matrix[i][j] = temp[i][j];
                }
            }
            m=m-1;
            n=n-1;
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==1){
                    sum+=1;   
                }
            }
        }
        return sum;
    }
};


/*
Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

 

Example 1:

Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15
Explanation: 
There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.
*/