class Solution {
public:
    unordered_map<string,vector<pair<string,double>>> adj;
    map<string,int> visited;
    double ans;
    void dfs(string v,string s,double temp){
        if(v==s){
            ans=temp;
            return;
        }
        visited[v]=1;
        for(auto u:adj[v]){
            if(!visited[u.first] && ans==-1){
                dfs(u.first,s,temp*u.second);
            }
        }
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for(int i=0;i<equations.size();i++){
            adj[equations[i][0]].push_back({equations[i][1],values[i]});
            adj[equations[i][1]].push_back({equations[i][0],(1.0/values[i])});
        }
        vector<double> fans;
        for(auto q:queries){
            ans=-1;
            visited.clear();
            if(adj.find(q[0])!=adj.end() && adj.find(q[1])!=adj.end()){
                dfs(q[0],q[1],1);
            }
            fans.push_back(ans);
        }
        return fans;
        
    }
};

/*Equations are given in the format A / B = k, where A and B are variables represented as strings, and k is a real number (floating point number). Given some queries, return the answers. If the answer does not exist, return -1.0.

Example:
Given a / b = 2.0, b / c = 3.0.
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? .
return [6.0, 0.5, -1.0, 1.0, -1.0 ].

The input is: vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries , where equations.size() == values.size(), and the values are positive. This represents the equations. Return vector<double>.

According to the example above:

equations = [ ["a", "b"], ["b", "c"] ],
values = [2.0, 3.0],
queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ]. 
 

The input is always valid. You may assume that evaluating the queries will result in no division by zero and there is no contradiction.

solution 
construct DAG 
apply dfs to find between a and b

*/