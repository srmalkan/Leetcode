class Solution {
public:
    vector<vector<pair<int,int>>> adj;
    vector<int> level;
    vector<bool> visited;
    int cnt;
    
    void dfs(int v,int t){
        visited[v]=1;
        for(auto u:adj[v] ){
            if(level[u.first]>t+u.second){
                level[u.first] = t+u.second;
                dfs(u.first,u.second+t);
            }
        }
    }
    
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        adj.resize(N+5);
        level.resize(N+5);
        visited.resize(N+5);
        for(auto e:times){
            adj[e[0]].push_back({e[1],e[2]});
        }
        for(int i=1;i<=N;i++){
            level[i]=1000;
        }
        cnt=0;
        level[K]=0;
        dfs(K,0);
        for(int i=1;i<=N;i++){
            if(!visited[i]){
                return -1;
            }
        }
        
        return *max_element(level.begin(),level.end());
    }
};
/*
There are N network nodes, labelled 1 to N.

Given times, a list of travel times as directed edges times[i] = (u, v, w), where u is the source node, v is the target node, and w is the time it takes for a signal to travel from source to target.

Now, we send a signal from a certain node K. How long will it take for all nodes to receive the signal? If it is impossible, return -1.

 

Example 1:



Input: times = [[2,1,1],[2,3,1],[3,4,1]], N = 4, K = 2
Output: 2
 

Note:

N will be in the range [1, 100].
K will be in the range [1, N].
The length of times will be in the range [1, 6000].
All edges times[i] = (u, v, w) will have 1 <= u, v <= N and 0 <= w <= 100.

solution:
Apply dfs
for each element check if relaxation is possible.
if possible recall dfs
*/