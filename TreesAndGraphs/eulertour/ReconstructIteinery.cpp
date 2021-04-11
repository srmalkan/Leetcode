class Solution {
public:
    unordered_map<string,vector<string>> adj;
    map<pair<string,string>,int> visited;
    vector<string> ans;
    void dfs(string v){
        for(auto s:adj[v]){
            if(visited[{v,s}]!=0){
                visited[{v,s}]--;
                dfs(s);
            }
        }
        ans.push_back(v);
    }
    static bool comp(string s1,string s2){
        if(s1[0]!=s2[0]){
            return s1[0]<s2[0];
        }else if(s1[1]!=s2[1]){
            return s1[1]<s2[1];
        }else{
            return s1[2]<s2[2];
        }
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto v:tickets){
            adj[v[0]].push_back(v[1]);
            visited[{v[0],v[1]}]++;
        }
        for(auto itr=adj.begin();itr!=adj.end();itr++){
            sort(itr->second.begin(),itr->second.end(),comp);
            // adj[s.first]=s.second;
        }
        
        dfs("JFK");
        // for(auto p:visited){
        //     cout<<p.first.first<<" "<<p.first.second<<endl;
        // }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

/*
Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.

Note:

If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
All airports are represented by three capital letters (IATA code).
You may assume all tickets form at least one valid itinerary.
One must use all the tickets once and only once.
Example 1:

Input: [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
Output: ["JFK", "MUC", "LHR", "SFO", "SJC"]

solution:
keep track of each edge visited or not .
if stuck backtrack.
*/