class Solution {
public:
    bool ans=false;
    vector<vector<int>> mp;
    vector<int> visited;
    vector<int> ordering;
    vector<int> st;
    int dfs(int v,int i){
        visited[v] = 1;
        st[v]=1;
        for(auto u:mp[v]){
            if(visited[u]==1 && st[u]==1){
                ans=true;
                // cout<<u<<"\n";
            }
            if(!visited[u] && !ans){
                i = dfs(u,i);
            }
        }
        st[v]=0;
        ordering[i]=v;
        return i-1;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        mp.resize(numCourses);
        for(auto v:prerequisites){
            mp[v[1]].push_back(v[0]);
        }
        
        visited.resize(numCourses);
        ordering.resize(numCourses);
        st.resize(numCourses);

        int j=numCourses-1;
        for(int i=0;i<numCourses;i++){
            if(!visited[i] && !ans){
                j = dfs(i,j);
            }
            if(ans){
                break;
            }
        }
        if(ans){
            return {};
        }
        return ordering;
    }
};

/*
There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

Input: 4, [[1,0],[2,0],[3,1],[3,2]]
Output: [0,1,2,3] or [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both     
             courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. 
             So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3] .


solution:
to get the topological ordering we use dfs
and simultaneosly track present in track to find cycles. 

*/