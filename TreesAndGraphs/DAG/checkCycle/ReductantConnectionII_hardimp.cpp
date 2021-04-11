class Solution {
public:
    vector<vector<int>> adj;
    vector<bool> visited,st;
    bool checkCycle(int v,vector<bool> &visited,vector<bool> &st){
        visited[v]=1;
        st[v]=1;
        bool ans =false;
        for(auto u:adj[v]){
            if(st[u]){
                ans = true;
            }
            if(!visited[u] && !ans){
                ans = ans | checkCycle(u,visited,st);
            }
        }
        st[v]=0;
        return ans;
    }
    
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        adj.resize(1100);
        
        vector<int> s(1100);
        for(int i=1;i<=edges.size();i++){
            s[i]=-1;
        }
        vector<vector<int>> ans;
        for(auto e:edges){
            if(s[e[1]]!=-1){
                ans.push_back({s[e[1]],e[1]});
                ans.push_back({e[0],e[1]});
                continue;
            }
            s[e[1]]=e[0];
        }
        for(auto e:edges){
            vector<bool> visited(edges.size()+5),st(edges.size()+5);

            if(ans.size()!=0 && ans[1][0]==e[0] && ans[1][1]==e[1]){
                continue;
            }
            adj[e[0]].push_back(e[1]);


            if(checkCycle(e[0],visited,st)){
                if(ans.size()==0){
                    return {e[0],e[1]};
                }
                return ans[0];
                
            }
        }
        return ans[1];
    }
};

/*
In this problem, a rooted tree is a directed graph such that, there is exactly one node (the root) for which all other nodes are descendants of this node, plus every node has exactly one parent, except for the root node which has no parents.

The given input is a directed graph that started as a rooted tree with N nodes (with distinct values 1, 2, ..., N), with one additional directed edge added. The added edge has two different vertices chosen from 1 to N, and was not an edge that already existed.

The resulting graph is given as a 2D-array of edges. Each element of edges is a pair [u, v] that represents a directed edge connecting nodes u and v, where u is a parent of child v.

Return an edge that can be removed so that the resulting graph is a rooted tree of N nodes. If there are multiple answers, return the answer that occurs last in the given 2D-array.

Example 1:
Input: [[1,2], [1,3], [2,3]]
Output: [2,3]
Explanation: The given directed graph will be like this:
  1
 / \
v   v
2-->3
Example 2:
Input: [[1,2], [2,3], [3,4], [4,1], [1,5]]
Output: [4,1]
Explanation: The given directed graph will be like this:
5 <- 1 -> 2
     ^    |
     |    v
     4 <- 3
Note:
The size of the input 2D-array will be between 3 and 1000.
Every integer represented in the 2D-array will be between 1 and N, where N is the size of the input array.
*/