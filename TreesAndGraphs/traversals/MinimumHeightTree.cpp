class Solution {
public:
    vector<int> level,indegree,visited;
    vector<vector<int>> adj;
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        level.resize(n);
        indegree.resize(n);
        visited.resize(n);
        adj.resize(n);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            indegree[e[0]]++;
            indegree[e[1]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(adj[i].size()==1){
                q.push(i);
                level[i]=1;
            }
        }
        while(!q.empty()){
            int x = q.front();
            q.pop();
            visited[x]=1;
            for(auto v:adj[x]){
                if(!visited[v]){
                    indegree[v]--;
                    if(indegree[v]==1){
                        q.push(v);
                        level[v] = level[x]+1;
                    }
                }
            }
        }
        int mx = *max_element(level.begin(),level.end());
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(level[i]==mx){
                ans.push_back(i);
            }
        }
        return ans;
    }
        
};

/*
For an undirected graph with tree characteristics, we can choose any node as the root. The result graph is then a rooted tree. Among all possible rooted trees, those with minimum height are called minimum height trees (MHTs). Given such a graph, write a function to find all the MHTs and return a list of their root labels.

Format
The graph contains n nodes which are labeled from 0 to n - 1. You will be given the number n and a list of undirected edges (each edge is a pair of labels).

You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.

Input: n = 4, edges = [[1, 0], [1, 2], [1, 3]]

        0
        |
        1
       / \
      2   3 

Output: [1]

Solution : 
traverse from leaf node to root node
for each step remove leaf nodes and append newly created leaf nodes.
assign level to each node in reverse order such that level of ancestor > level of child
node with maximum level is the root.
since we are removing leaf nodes in each iteration , it is assured that we will have minimum height tree.
*/

