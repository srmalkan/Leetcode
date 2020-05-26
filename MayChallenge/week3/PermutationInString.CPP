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
    
    bool checkInclusion(string p, string s) {
        map<char,int> P;
        for(char x : p){
            P[x]++;
        }
        int m=p.length();
        int n=s.length();
        if(m>n){
            return false;
        }
        map<char,int> temp;
        for(int i=0;i<m-1;i++){
            temp[s[i]]++;
        }
        for(int i=m-1;i<n;i++){
            temp[s[i]]++;
            if(compareMaps(temp,P)){
                return true;
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
        return false;
    }
};

/*
Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.

 

Example 1:

Input: s1 = "ab" s2 = "eidbaooo"
Output: True
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input:s1= "ab" s2 = "eidboaoo"
Output: False
 

Constraints:

The input strings only contain lower case letters.
The length of both given strings is in range [1, 10,000].
*/