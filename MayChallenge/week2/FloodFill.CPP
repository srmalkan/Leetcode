class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n= image.size();
        if(n==0){
            return image;
        }
        int m = image[0].size();
        vector<vector<int>> visited(n,vector<int>(m));
        vector<vector<int>> dir={{0,1},{1,0},{-1,0},{0,-1}};
        queue<pair<int,int>> q;
        q.push({sr,sc});
        visited[sr][sc]=1;
        int color = image[sr][sc];
        image[sr][sc]=newColor;
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int x=p.first + dir[i][0];
                int y=p.second + dir[i][1];
                if(x>=0 && x<n && y>=0 && y<m && visited[x][y]!=1 && image[x][y]==color){
                    image[x][y]=newColor;
                    visited[x][y]=1;
                    q.push({x,y});
                }
            }
        }
        return image;
    }
};

/*
An image is represented by a 2-D array of integers, each integer representing the pixel value of the image (from 0 to 65535).

Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.

To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor.

At the end, return the modified image.

Example 1:
Input: 
image = [[1,1,1],[1,1,0],[1,0,1]]
sr = 1, sc = 1, newColor = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: 
From the center of the image (with position (sr, sc) = (1, 1)), all pixels connected 
by a path of the same color as the starting pixel are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected
to the starting pixel.
Note:

The length of image and image[0] will be in the range [1, 50].
The given starting pixel will satisfy 0 <= sr < image.length and 0 <= sc < image[0].length.
The value of each color in image[i][j] and newColor will be an integer in [0, 65535].
*/