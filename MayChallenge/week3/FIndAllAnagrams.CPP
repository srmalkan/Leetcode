class Solution {
public:
    bool compareMaps(map<char,int> &temp, map<char,int> &P){
        if(temp.size()!=P.size()){
            return false;
        }
        for(auto itr=P.begin(),itr2=temp.begin();itr!=P.end();itr++,itr2++){
            // cout<<itr->first<<" "<<itr2->first;
            if(itr->first != itr2->first){
                return false;
            }
            if(itr->second != itr2->second){
                return false;
            }
            
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        map<char,int> P;
        for(char x : p){
            P[x]++;
        }
        int m=p.length();
        int n=s.length();
        if(m>n){
            return ans;
        }
        map<char,int> temp;
        for(int i=0;i<m-1;i++){
            temp[s[i]]++;
        }
        for(int i=m-1;i<n;i++){
            temp[s[i]]++;
            if(compareMaps(temp,P)){
                ans.push_back(i-(m-1));
            }
            // for(auto x:temp){
            //     cout<<x.first<<" "<<x.second<<"\n";
            // }
            // cout<<endl;
            if(temp[s[i-(m-1)]]==1){
                temp.erase(s[i-(m-1)]);
            }else{
                temp[s[i-(m-1)]]--;
            }
            
        }
        return ans;
    }
};

/*
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
*/