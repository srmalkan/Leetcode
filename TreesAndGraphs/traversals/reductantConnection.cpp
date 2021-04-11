class Solution {
public:
    vector<vector<int>> adj;
    
    bool dfs(int u,int v,vector<bool> &visited){
        visited[u]=1;
        if(u==v){
            return true;
        }
        bool ans =false;
        for(auto x:adj[u]){
            if(!visited[x]){
                ans = ans | dfs(x,v,visited);
            }
        }
        return ans;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        adj.resize(1100);
        for(auto e:edges){
            vector<bool> visited(1100);
            if(dfs(e[0],e[1],visited)){
                return {e[0],e[1]};
            }
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        return {0,0};
    }
};
/*
In this problem, a tree is an undirected graph that is connected and has no cycles.

The given input is a graph that started as a tree with N nodes (with distinct values 1, 2, ..., N), with one additional edge added. The added edge has two different vertices chosen from 1 to N, and was not an edge that already existed.

The resulting graph is given as a 2D-array of edges. Each element of edges is a pair [u, v] with u < v, that represents an undirected edge connecting nodes u and v.

Return an edge that can be removed so that the resulting graph is a tree of N nodes. If there are multiple answers, return the answer that occurs last in the given 2D-array. The answer edge [u, v] should be in the same format, with u < v.

Example 1:
Input: [[1,2], [1,3], [2,3]]
Output: [2,3]
Explanation: The given undirected graph will be like this:
  1
 / \
2 - 3
Example 2:
Input: [[1,2], [2,3], [3,4], [1,4], [1,5]]
Output: [1,4]
Explanation: The given undirected graph will be like this:
5 - 1 - 2
    |   |
    4 - 3

solution : 
we use property of tree i.e The path between any two nodes in tree is always unique.
we use dfs to verify the property.
for every edge we check if path is already present.
*?